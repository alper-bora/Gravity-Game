/*
 * ============================================================
 *  GRAVITY - Robot Module
 * ============================================================
 *  Handles:
 *    - Robot random movement (4 directions, no diagonals)
 *    - Robots can only move into empty squares
 *    - Robots cannot collect treasures or push boulders
 *    - Elements robots cannot pass act like walls
 * ============================================================
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "types.h"

void robot_update_all(gameStats *stats);

#endif /* ROBOT_H */
