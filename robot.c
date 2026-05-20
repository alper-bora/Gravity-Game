/*
 * ============================================================
 *  GRAVITY - Robot Module Implementation
 * ============================================================
 */

#include "robot.h"
#include "display.h"
#include "game.h"
#include "types.h"
#include "utils.h"

void robot_update_all(gameStats *stats) {
  for (int i = 0; i < NUM_ROBOTS; i++) {
    if (stats->robots[i].r == 0 && stats->robots[i].c == 0) {
      continue;
    }
    switch (random_range(0, 3)) {
    case 0:
      if (stats->field[stats->robots[i].r - 1][stats->robots[i].c] ==
              CELL_EMPTY ||
          stats->field[stats->robots[i].r - 1][stats->robots[i].c] ==
              CELL_PLAYER) {
        stats->field[stats->robots[i].r][stats->robots[i].c] = CELL_EMPTY;
        stats->field[stats->robots[i].r - 1][stats->robots[i].c] = CELL_ROBOT;
        stats->robots[i].r = stats->robots[i].r - 1;
        if (stats->robots[i].r == stats->player_row &&
            stats->robots[i].c == stats->player_col) {
          stats->is_game_over = 1;
        }
        break;
      }
    case 1:
      if (stats->field[stats->robots[i].r + 1][stats->robots[i].c] ==
              CELL_EMPTY ||
          stats->field[stats->robots[i].r + 1][stats->robots[i].c] ==
              CELL_PLAYER) {
        stats->field[stats->robots[i].r][stats->robots[i].c] = CELL_EMPTY;
        stats->field[stats->robots[i].r + 1][stats->robots[i].c] = CELL_ROBOT;
        stats->robots[i].r = stats->robots[i].r + 1;
        if (stats->robots[i].r == stats->player_row &&
            stats->robots[i].c == stats->player_col) {
          stats->is_game_over = 1;
        }
        break;
      }
    case 2:
      if (stats->field[stats->robots[i].r][stats->robots[i].c - 1] ==
              CELL_EMPTY ||
          stats->field[stats->robots[i].r][stats->robots[i].c - 1] ==
              CELL_PLAYER) {
        stats->field[stats->robots[i].r][stats->robots[i].c] = CELL_EMPTY;
        stats->field[stats->robots[i].r][stats->robots[i].c - 1] = CELL_ROBOT;
        stats->robots[i].c = stats->robots[i].c - 1;
        if (stats->robots[i].r == stats->player_row &&
            stats->robots[i].c == stats->player_col) {
          stats->is_game_over = 1;
        }
        break;
      }
    case 3:
      if (stats->field[stats->robots[i].r][stats->robots[i].c + 1] ==
              CELL_EMPTY ||
          stats->field[stats->robots[i].r][stats->robots[i].c + 1] ==
              CELL_PLAYER) {
        stats->field[stats->robots[i].r][stats->robots[i].c] = CELL_EMPTY;
        stats->field[stats->robots[i].r][stats->robots[i].c + 1] = CELL_ROBOT;
        stats->robots[i].c = stats->robots[i].c + 1;
        if (stats->robots[i].r == stats->player_row &&
            stats->robots[i].c == stats->player_col) {
          stats->is_game_over = 1;
        }
        break;
      }
    }
  }
}