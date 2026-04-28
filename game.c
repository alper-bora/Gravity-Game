/*
 * ============================================================
 *  GRAVITY - Game Initialization & State Management
 * ============================================================
 */

#include "game.h"
#include "backpack.h"
#include "boulder.h"
#include "input_queue.h"
#include "player.h"
#include "robot.h"
#include "types.h"
#include "utils.h"

void game_init(gameStats *stats) {
  // Placing the walls
  for (int i = 0; i < FIELD_ROWS; i++) {
    for (int j = 0; j < FIELD_COLS; j++) {
      if ((i == 0 || i == FIELD_ROWS - 1) || (j == 0 || j == FIELD_COLS - 1)) {
        stats->field[i][j] = '#';
      } else {
        stats->field[i][j] = ':';
      }
    }
  }

  // Randomly distributing cells
  for (int i = 0; i < 180; i++) {
    int r, c;
    find_random_cell(stats->field, CELL_EARTH, &r, &c);
    stats->field[r][c] = CELL_BOULDER;
  }

  for (int i = 0; i < 30; i++) {
    int r, c;
    find_random_cell(stats->field, CELL_EARTH, &r, &c);
    stats->field[r][c] = CELL_TREASURE_1 + random_range(0, 2);
  }

  for (int i = 0; i < 200; i++) {
    int r, c;
    find_random_cell(stats->field, CELL_EARTH, &r, &c);
    stats->field[r][c] = CELL_EMPTY;
  }

  for (int i = 0; i < 7; i++) {
    int r, c;
    find_random_cell(stats->field, CELL_EARTH, &r, &c);
    stats->field[r][c] = CELL_ROBOT;
    stats->robots[i].r = r;
    stats->robots[i].c = c;
  }

  find_random_cell(stats->field, CELL_EARTH, &stats->player_row,
                   &stats->player_col);
  stats->field[stats->player_row][stats->player_col] = CELL_PLAYER;

  // Stat initialization
  stats->teleports = INITIAL_TELEPORTS;
  stats->is_game_over = 0;
  stats->time_elapsed = 0;
  stats->score = 0;

  backpack_init(&(stats->backpack));
  input_queue_init(&(stats->input_queue));

  stats->insert_timer = INPUT_INSERT_INTERVAL * TARGET_FPS;
  return;
}

/*
 * TODO: Implement game_check_over()
 */

/*
 * TODO: Implement game_update()
 */
