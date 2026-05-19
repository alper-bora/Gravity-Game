/*
 * ============================================================
 *  GRAVITY - EED 1010 Project
 *  Main Entry Point
 * ============================================================
 *  This file contains:
 *    - main() function
 *    - Game loop with timing (10 FPS target)
 *    - High-level game state management
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "backpack.h"
#include "boulder.h"
#include "display.h"
#include "game.h"
#include "input_queue.h"
#include "player.h"
#include "robot.h"
#include "types.h"
#include "utils.h"

int main(void) {
  srand(time(NULL));
  gameStats stats;
  game_init(&stats);
  while (!game_check_over(&stats)) {
    display_render(&stats);
    sleep_ms(100);
  }
  display_game_over(&stats);
  return 0;
}
