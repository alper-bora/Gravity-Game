/*
 * ============================================================
 *  GRAVITY - Boulder Physics Implementation
 * ============================================================
 */

#include "boulder.h"
#include "utils.h"

/*
 * TODO: Implement boulder_update_all()
 *
 * Pseudocode:
 *   for row = FIELD_ROWS - 2 down to 1:        // skip walls (bottom/top)
 *     for col = 1 to FIELD_COLS - 2:            // skip walls (left/right)
 *       if field[row][col] == BOULDER:
 *
 *         // --- (a) Direct Fall ---
 *         if field[row+1][col] == EMPTY:
 *           field[row][col] = EMPTY
 *           field[row+1][col] = BOULDER
 *           // check if boulder landed on player -> game over
 *           // check if boulder landed on robot  -> destroy robot, +900 pts
 *
 *         // --- (b) Side Fall ---
 *         else if field[row+1][col] == BOULDER:
 *           can_left  = (field[row][col-1] == EMPTY && field[row+1][col-1] == EMPTY)
 *           can_right = (field[row][col+1] == EMPTY && field[row+1][col+1] == EMPTY)
 *
 *           if can_left && can_right:
 *             pick random side
 *           else if can_left:
 *             side = LEFT
 *           else if can_right:
 *             side = RIGHT
 *           else:
 *             continue  // boulder is stuck
 *
 *           field[row][col] = EMPTY
 *           field[row][col + side_offset] = BOULDER
 *           // the moved boulder will fall further on next update
 *
 * HINT: You may need multiple passes or a "changed" flag to handle
 *       chain reactions within a single frame. Alternatively, one
 *       pass per frame creates a nice visual "falling" effect.
 */
