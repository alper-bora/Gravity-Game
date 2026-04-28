/*
 * ============================================================
 *  GRAVITY - Boulder Physics Module
 * ============================================================
 *  Handles all boulder gravity mechanics:
 *    (a) Direct Fall  - Boulder falls if cell below is empty
 *    (b) Side Fall    - Boulder on top of another boulder slides
 *                       to the side if side+below-side are empty
 *    (c) Static       - Player can stand under a static boulder
 *    (d) No Escape    - If player moves DOWN from under a boulder,
 *                       boulder immediately falls into vacated cell
 * ============================================================
 */

#ifndef BOULDER_H
#define BOULDER_H

#include "types.h"

/*
 * boulder_update_all()
 * --------------------
 * Apply gravity to ALL boulders on the field.
 *
 * IMPORTANT: Process boulders from BOTTOM to TOP of the field
 * (row = FIELD_ROWS-2 down to row = 1) so that chain-falls
 * resolve correctly in a single pass.
 *
 * For each boulder at (row, col):
 *
 *   (a) DIRECT FALL:
 *       If cell (row+1, col) is EMPTY:
 *         -> Move boulder down: set (row,col)=EMPTY, (row+1,col)=BOULDER
 *         -> If (row+1,col) was the PLAYER's position -> GAME OVER
 *         -> If (row+1,col) was a ROBOT's position -> destroy robot, +900 points
 *
 *   (b) SIDE FALL (only when sitting on another boulder):
 *       If cell (row+1, col) is BOULDER:
 *         -> Check LEFT:  if (row, col-1) is EMPTY AND (row+1, col-1) is EMPTY
 *         -> Check RIGHT: if (row, col+1) is EMPTY AND (row+1, col+1) is EMPTY
 *         -> If both sides are valid: pick one randomly
 *         -> If only one side is valid: use that side
 *         -> Move boulder to (row, col±1), then it will fall further next frame
 *
 *   (d) NO ESCAPE:
 *       This is handled implicitly - when the player moves DOWN,
 *       their old cell becomes EMPTY, and the boulder above will
 *       fall into it on the next boulder_update_all() call.
 *
 * TODO: Implement this function
 */
/* void boulder_update_all(GameState *state); */

#endif /* BOULDER_H */
