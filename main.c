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

#include "types.h"
#include "game.h"
#include "player.h"
#include "robot.h"
#include "boulder.h"
#include "input_queue.h"
#include "backpack.h"
#include "display.h"
#include "utils.h"

int main(void) {
    /* TODO: Seed the random number generator */

    /* TODO: Initialize the game state (calls game_init) */

    /* TODO: Main game loop
     *   - Target: 10 frames per second (100ms per frame)
     *   - Each iteration:
     *       1. Process player input (keyboard)
     *       2. Update robots (random movement)
     *       3. Update boulders (gravity/fall logic)
     *       4. Update input queue timer & insertion
     *       5. Check game over conditions
     *       6. Render the screen
     *       7. Wait for remaining frame time
     */

    /* TODO: Show game over screen with final score */

    return 0;
}
