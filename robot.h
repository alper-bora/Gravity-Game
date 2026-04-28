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

/*
 * robot_update_all()
 * ------------------
 * Move each robot one step in a random valid direction.
 *
 * For each robot:
 *   1. Pick a random direction (UP/DOWN/LEFT/RIGHT)
 *   2. Check if target cell is EMPTY (not earth, not treasure, not boulder, not wall)
 *   3. If valid: move robot to new cell, clear old cell
 *   4. If invalid: robot stays in place (or try another direction - your choice)
 *
 * NOTE: If a robot enters the player's cell, it's GAME OVER.
 *       However, robots should only move into truly empty cells,
 *       so this typically happens when player walks into a robot.
 *
 * TODO: Implement this function
 */
/* void robot_update_all(GameState *state); */

#endif /* ROBOT_H */
