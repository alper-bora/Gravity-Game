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
    int temp;
    switch (random_range(0, 3)) {
    case 0:
      if (stats->robots[i].r - 1 == CELL_EMPTY) {
        stats->robots[i].r = temp;
        stats->robots[i].r = stats->robots[i].r - 1;
        temp = CELL_EMPTY;
        break;
      }
    case 1:
      if (stats->robots[i].r + 1 == CELL_EMPTY) {
        stats->robots[i].r = temp;
        stats->robots[i].r = stats->robots[i].r + 1;
        temp = CELL_EMPTY;
        break;
      }
    case 2:
      if (stats->robots[i].c - 1 == CELL_EMPTY) {
        stats->robots[i].c = temp;
        stats->robots[i].c = stats->robots[i].c - 1;
        temp = CELL_EMPTY;
        break;
      }
    case 3:
      if (stats->robots[i].c + 1 == CELL_EMPTY) {
        stats->robots[i].c = temp;
        stats->robots[i].c = stats->robots[i].c + 1;
        temp = CELL_EMPTY;
        break;
      }
    }
    if (stats->robots[i].r == stats->player_col &&
        stats->robots[i].c == stats->player_col) {
      game_check_over(&stats);
      display_game_over(&stats);
    }
  }
}