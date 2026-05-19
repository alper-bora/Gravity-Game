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

#include "input_queue.h"
#include "types.h"

void game_init(gameStats *stats);

int game_check_over(gameStats *stats);

void game_update(gameStats *stats, Backpack *bp, InputQueue *q);

#endif
