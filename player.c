/*
 * ============================================================
 *  GRAVITY - Player Module Implementation
 * ============================================================
 */

#include "player.h"
#include <conio.h>
#include <consoleapi.h>
#include <windows.h>

#include "backpack.h"
#include "types.h"
#include "utils.h"

/*
 * TODO: Implement player_process_input()
 *
 * Pseudocode:
 *   1. Check if a key has been pressed (use _kbhit() on Windows, or equivalent)
 *   2. Read the key
 *   3. Determine direction (arrow keys) or action (space for teleport)
 *   4. Calculate target cell (new_row, new_col)
 *   5. Based on target cell content:
 *      - EMPTY / EARTH: Move player, clear old cell, set new cell to 'P'
 *        - If EARTH: it becomes EMPTY
 *        - If TREASURE: call player_collect_treasure() first
 *      - BOULDER (only LEFT/RIGHT):
 *        - Check cell beyond boulder
 *        - If that cell is EMPTY: move boulder there, move player to boulder's
 * old spot
 *      - WALL / ROBOT / out-of-bounds: do nothing
 *   6. SPACE key: teleport to random empty cell if teleports > 0
 *
 * IMPORTANT: After moving, check if a boulder was above the old position.
 *            The boulder system will handle this in boulder_update().
 */

void player_process_input(gameStats *stats, Backpack *bp) {
  if (keyboard_hit()) {
    int key = _getch();
    int old_col = stats->player_col;
    int old_row = stats->player_row;
    int new_row = old_row;
    int new_col = old_col;
    int moved = 0;
    int teleported = 0;
    if (key == 224 || key == 0) {
      int real_key = keyboard_get();
      direction dir;
      switch (real_key) {
      case 72:
        dir = DIR_UP;
        moved = 1;
        break;
      case 75:
        dir = DIR_LEFT;
        moved = 1;
        break;
      case 80:
        dir = DIR_DOWN;
        moved = 1;
        break;
      case 77:
        dir = DIR_RIGHT;
        moved = 1;
        break;
      }
      if (moved) {
        switch (dir) {
        case DIR_RIGHT:
          new_col = old_col + 1;
          break;
        case DIR_LEFT:
          new_col = old_col - 1;
          break;
        case DIR_UP:
          new_row = old_row - 1;
          break;
        case DIR_DOWN:
          new_row = old_row + 1;
          break;
        }
      }

      if (new_row >= 0 && new_col >= 0 && new_row < FIELD_ROWS &&
          new_col < FIELD_COLS) {
        if (stats->field[new_row][new_col] == CELL_EMPTY ||
            stats->field[new_row][new_col] == CELL_EARTH) {
          stats->field[old_row][old_col] = CELL_EMPTY;
          stats->player_row = new_row;
          stats->player_col = new_col;
          stats->field[new_row][new_col] = CELL_PLAYER;
        }

        else if (stats->field[new_row][new_col] == CELL_TREASURE_1 ||
                 stats->field[new_row][new_col] == CELL_TREASURE_2 ||
                 stats->field[new_row][new_col] == CELL_TREASURE_3) {
          int value = stats->field[new_row][new_col] - '0';
          player_collect_treasure(stats, bp, value);
          stats->field[old_row][old_col] = CELL_EMPTY;
          stats->player_row = new_row;
          stats->player_col = new_col;
          stats->field[new_row][new_col] = CELL_PLAYER;
        }

        else if (stats->field[new_row][new_col] == CELL_BOULDER) {
          if (dir == DIR_LEFT && new_col > 0 &&
              stats->field[new_row][new_col - 1] == CELL_EMPTY) {
            stats->field[old_row][old_col] = CELL_EMPTY;
            stats->player_row = new_row;
            stats->player_col = new_col;
            stats->field[new_row][new_col] = CELL_PLAYER;
            stats->field[new_row][new_col - 1] = CELL_BOULDER;
          } else if (dir == DIR_RIGHT && new_col + 1 < FIELD_COLS &&
                     stats->field[new_row][new_col + 1] == CELL_EMPTY) {
            stats->field[old_row][old_col] = CELL_EMPTY;
            stats->player_row = new_row;
            stats->player_col = new_col;
            stats->field[new_row][new_col] = CELL_PLAYER;
            stats->field[new_row][new_col + 1] = CELL_BOULDER;
          }
        }
      }
    }

    else {
      switch (key) {
      case 113: // exit
        stats->is_game_over = 1;
        break;
      case 32: // teleport
        if (stats->teleports > 0) {
          find_random_cell(stats->field, CELL_EMPTY, &new_row, &new_col);
          stats->player_row = new_row;
          stats->player_col = new_col;
          stats->field[new_row][new_col] = CELL_PLAYER;
          stats->field[old_row][old_col] = CELL_EMPTY;
          stats->teleports--;
          teleported = 1;
        }
        break;
      }
    }

    if (teleported || moved) {
      if (old_row + 1 < FIELD_ROWS &&
          stats->field[old_row + 1][old_col] == CELL_BOULDER) {
        boulder_update_all();
      }
    }
  }
}
/*
 * TODO: Implement player_collect_treasure()
 *
 * Steps:
 *   1. If backpack is full, call backpack_discard_top()
 *   2. Call backpack_push() with the treasure value
 *   3. Call backpack_check_merge() to see if top two items match
 *      - If they match, pop both, add score, and if treasure was '3', add a
 * teleport
 *      - Keep checking for chain merges (merging may reveal another pair)
 */

void player_collect_treasure(gameStats *stats, Backpack *bp,
                             int treasure_value) {
  if (backpack_is_full(bp))
    backpack_discard_top(bp);
  else {
    backpack_push(bp, treasure_value);
    backpack_check_merge(bp, stats);
  }
}
