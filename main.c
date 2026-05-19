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

int main() {
  srand(time(NULL));
  gameStats stats;
  Backpack bp;
  InputQueue q;
  game_init(&stats);
  backpack_init(&bp);
  input_queue_init(&q);
  while (!game_check_over(&stats)) {
    game_update(&stats, &bp, &q);
    display_render(&stats, &bp, &q);
    sleep_ms(100);
  }
  display_game_over(&stats);
  return 0;
}
