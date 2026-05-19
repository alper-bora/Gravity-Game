/*
 * ============================================================
 *  GRAVITY - Boulder Physics Implementation
 * ============================================================
 */

#include "boulder.h"
#include "backpack.h"
#include "game.h"
#include "types.h"
#include "utils.h"

/*
 * TODO: Implement boulder_update_all()
 *
 * Pseudocode:
 *   for row = FIELD_ROWS - 2 down to 1:        // skip walls (bottom/top)
 *     for col = 1 to FIELD_COLS - 2:            // skip walls (left/right)
 *       if field[row][col] == BOULDER:
 *
 *         // --- (a) Direct Fall ---
 *         if field[row+1][col] == EMPTY:
 *           field[row][col] = EMPTY
 *           field[row+1][col] = BOULDER
 *           // check if boulder landed on player -> game over
 *           // check if boulder landed on robot  -> destroy robot, +900 pts
 *
 *         // --- (b) Side Fall ---
 *         else if field[row+1][col] == BOULDER:
 *           can_left  = (field[row][col-1] == EMPTY && field[row+1][col-1] ==
 * EMPTY) can_right = (field[row][col+1] == EMPTY && field[row+1][col+1] ==
 * EMPTY)
 *
 *           if can_left && can_right:
 *             pick random side
 *           else if can_left:
 *             side = LEFT
 *           else if can_right:
 *             side = RIGHT
 *           else:
 *             continue  // boulder is stuck
 *
 *           field[row][col] = EMPTY
 *           field[row][col + side_offset] = BOULDER
 *           // the moved boulder will fall further on next update
 *
 * HINT: You may need multiple passes or a "changed" flag to handle
 *       chain reactions within a single frame. Alternatively, one
 *       pass per frame creates a nice visual "falling" effect.
 */

void boulder_update_all(gameStats *stats, Backpack *bp) {
  int fall_left = 0;
  int fall_right = 0;
  int side_offset = 0;
  for (int row = FIELD_ROWS - 2; row >= 1; row--) {
    for (int col = 1; col <= FIELD_COLS - 2; col++) {
      char current = stats->field[row][col];
      if (current == CELL_BOULDER || current == CELL_BOULDER_FALLING) {
        char below = stats->field[row + 1][col];

        if (current == CELL_BOULDER) {
          if (below == CELL_EMPTY) {
            stats->field[row][col] = CELL_EMPTY;
            stats->field[row + 1][col] = CELL_BOULDER_FALLING;
          }

          else if (stats->field[row + 1][col] == CELL_BOULDER) { // Side fall
            fall_left = (stats->field[row][col - 1] == CELL_EMPTY &&
                         stats->field[row + 1][col - 1] == CELL_EMPTY);
            fall_right = (stats->field[row][col + 1] == CELL_EMPTY &&
                          stats->field[row + 1][col + 1] == CELL_EMPTY);

            if (fall_left && fall_right) {
              side_offset = (random_range(0, 1) == 0) ? -1 : 1;
            }

            else if (fall_left) {
              side_offset = -1;
            }

            else if (fall_right) {
              side_offset = 1;
            }

            else {
              continue;
            }
            stats->field[row][col] = CELL_EMPTY;
            stats->field[row][col + side_offset] = CELL_BOULDER_FALLING;
          }
        }

        else if (current == CELL_BOULDER_FALLING) {
          if (below == CELL_EMPTY) {
            stats->field[row + 1][col] = CELL_BOULDER_FALLING;
            stats->field[row][col] = CELL_EMPTY;
          }

          else if (below == CELL_ROBOT) {
            stats->field[row + 1][col] = CELL_BOULDER;
            stats->field[row][col] = CELL_EMPTY;
            stats->score += 900;

            for (int i = 0; i < 7; i++) {
              if (stats->robots[i].r == row + 1 && stats->robots[i].c == col) {
                stats->robots[i].r = 0;
                stats->robots[i].c = 0;
                break; // Squishes the robot to the inside of the wall
              }
            }
          }

          else if (below == CELL_PLAYER) {
            stats->is_game_over = 1;
          }

          else {
            stats->field[row][col] = CELL_BOULDER;
          }
        }
      }
    }
  }
}