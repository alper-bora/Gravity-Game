/*
 * ============================================================
 *  GRAVITY - Player Module Implementation
 * ============================================================
 */

#include "player.h"
#include "backpack.h"
#include "utils.h"

/*
 * TODO: Implement player_process_input()
 *
 * Pseudocode:
 *   1. Check if a key has been pressed (use _kbhit() on Windows, or equivalent)
 *   2. Read the key
 *   3. Determine direction (arrow keys) or action (space for teleport)
 *   4. Calculate target cell (new_row, new_col)
 *   5. Based on target cell content:
 *      - EMPTY / EARTH: Move player, clear old cell, set new cell to 'P'
 *        - If EARTH: it becomes EMPTY
 *        - If TREASURE: call player_collect_treasure() first
 *      - BOULDER (only LEFT/RIGHT):
 *        - Check cell beyond boulder
 *        - If that cell is EMPTY: move boulder there, move player to boulder's old spot
 *      - WALL / ROBOT / out-of-bounds: do nothing
 *   6. SPACE key: teleport to random empty cell if teleports > 0
 *
 * IMPORTANT: After moving, check if a boulder was above the old position.
 *            The boulder system will handle this in boulder_update().
 */

/*
 * TODO: Implement player_collect_treasure()
 *
 * Steps:
 *   1. If backpack is full, call backpack_discard_top()
 *   2. Call backpack_push() with the treasure value
 *   3. Call backpack_check_merge() to see if top two items match
 *      - If they match, pop both, add score, and if treasure was '3', add a teleport
 *      - Keep checking for chain merges (merging may reveal another pair)
 */
