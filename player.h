/*
 * ============================================================
 *  GRAVITY - Player Module
 * ============================================================
 *  Handles:
 *    - Player movement (4 directions via cursor keys)
 *    - Boulder pushing
 *    - Treasure collection (into backpack)
 *    - Teleportation (Space key)
 *    - Earth digging (converting earth to empty on move)
 * ============================================================
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

/*
 * player_process_input()
 * ----------------------
 * Read keyboard input and process player action:
 *
 * Arrow Keys (UP/DOWN/LEFT/RIGHT):
 *   - If target cell is empty or earth -> move player there
 *     - If earth: convert to empty ' ' first
 *     - If treasure: collect into backpack, then move
 *   - If target cell is a boulder (LEFT/RIGHT only):
 *     - Check the cell BEYOND the boulder in the same direction
 *     - If that cell is empty -> push boulder, move player
 *   - If target cell is wall, boulder (UP/DOWN), or robot -> don't move
 *
 * Space Key:
 *   - If teleports > 0:
 *     - Move player to a random empty square
 *     - Decrement teleport count
 *
 * NOTE: Player can only push boulders LEFT or RIGHT, not UP or DOWN.
 * NOTE: After player moves, boulders above old position may start falling!
 *
 * TODO: Implement this function
 */
/* void player_process_input(GameState *state); */

/*
 * player_collect_treasure()
 * -------------------------
 * Called when player moves onto a treasure cell.
 *   - Add the treasure value to the backpack
 *   - Immediately check for merging (two identical items on top)
 *   - Update score if merge happens
 *   - If backpack is full, discard top item first to make room
 *
 * TODO: Implement this function
 */
/* void player_collect_treasure(GameState *state, int treasure_value); */

#endif /* PLAYER_H */
