/*
 * ============================================================
 *  GRAVITY - Backpack Module Implementation
 * ============================================================
 */

#include "backpack.h"

/*
 * TODO: Implement backpack_init()
 *   -> Set top = -1
 */

/*
 * TODO: Implement backpack_is_full()
 *   -> Return (bp->top == BACKPACK_CAPACITY - 1)
 */

/*
 * TODO: Implement backpack_is_empty()
 *   -> Return (bp->top == -1)
 */

/*
 * TODO: Implement backpack_push()
 *   -> bp->top++
 *   -> bp->items[bp->top] = value
 */

/*
 * TODO: Implement backpack_pop()
 *   -> int val = bp->items[bp->top]
 *   -> bp->top--
 *   -> return val
 */

/*
 * TODO: Implement backpack_peek()
 *   -> return bp->items[bp->top]
 */

/*
 * TODO: Implement backpack_discard_top()
 *   -> Just call backpack_pop() and ignore the return value
 */

/*
 * TODO: Implement backpack_check_merge()
 *
 * Pseudocode:
 *   total_score = 0
 *   while (bp->top >= 1):   // at least 2 items
 *     if bp->items[bp->top] == bp->items[bp->top - 1]:
 *       merged_value = backpack_pop(bp)
 *       backpack_pop(bp)  // remove the second copy
 *       switch (merged_value):
 *         case 1: total_score += SCORE_MERGE_1; break
 *         case 2: total_score += SCORE_MERGE_2; break
 *         case 3: total_score += SCORE_MERGE_3; state->teleports++; break
 *       // Loop again to check for chain merge!
 *     else:
 *       break  // no more merges
 *   return total_score
 */
