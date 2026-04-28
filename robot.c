/*
 * ============================================================
 *  GRAVITY - Robot Module Implementation
 * ============================================================
 */

#include "robot.h"
#include "utils.h"

/*
 * TODO: Implement robot_update_all()
 *
 * Pseudocode:
 *   for each robot i in state->robots[]:
 *     1. Generate a random direction (0-3)
 *     2. Calculate target cell from robot's current position
 *     3. If target cell is EMPTY (' '):
 *        - Set old cell to EMPTY
 *        - Set new cell to ROBOT 'X'
 *        - Update robot's stored position
 *     4. Otherwise: robot stays put
 *
 * HINT: You might want robots to attempt multiple directions
 *       before giving up, or just skip if first choice is blocked.
 *
 * IMPORTANT: Check if robot moves to player's position -> game over
 */
