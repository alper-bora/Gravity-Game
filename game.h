/*
 * ============================================================
 *  GRAVITY - Game Initialization & State Management
 * ============================================================
 *  Handles:
 *    - Game field initialization (walls, earth, boulders,
 *      treasures, empty squares, robots, player placement)
 *    - Game state reset
 *    - Game over condition checking
 * ============================================================
 */

#ifndef GAME_H
#define GAME_H

#include "types.h"

void game_init(gameStats *stats);

int game_check_over(gameStats *stats);

/*
 * Called once per frame. Orchestrates all per-frame updates:
 *   1. Process player input
 *   2. Move robots
 *   3. Apply boulder gravity
 *   4. Tick the input queue timer and insert if needed
 *   5. Check game over conditions
 */
void game_update(gameStats *stats);

#endif /* GAME_H */
