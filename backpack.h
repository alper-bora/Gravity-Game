/*
 * ============================================================
 *  GRAVITY - Backpack Module (LIFO Stack)
 * ============================================================
 *  The backpack is a stack (Last In, First Out) with capacity 8.
 *
 *  Merging Rules:
 *    When two identical treasures are on top of the stack,
 *    they are consumed and points are awarded:
 *      - Two 1s -> 10 points
 *      - Two 2s -> 40 points
 *      - Two 3s -> 90 points + 1 extra teleport
 *
 *    After a merge, check again! The new top two items might
 *    also match, creating a chain merge.
 *
 *  Overflow:
 *    If the backpack is full (8 items) and the player collects
 *    a new treasure, the TOP item is discarded first.
 * ============================================================
 */

#ifndef BACKPACK_H
#define BACKPACK_H

#include "types.h"

/* TODO: Define a Backpack struct:
 *   - items[BACKPACK_CAPACITY]  (array of int, storing treasure values 1/2/3)
 *   - top                       (index of top element, -1 when empty)
 */

/*
 * backpack_init()
 * ---------------
 * Initialize backpack: set top = -1 (empty).
 *
 * TODO: Implement
 */
/* void backpack_init(Backpack *bp); */

/*
 * backpack_is_full()
 * ------------------
 * Returns 1 if backpack has BACKPACK_CAPACITY items, 0 otherwise.
 *
 * TODO: Implement
 */
/* int backpack_is_full(Backpack *bp); */

/*
 * backpack_is_empty()
 * -------------------
 * Returns 1 if backpack has no items, 0 otherwise.
 *
 * TODO: Implement
 */
/* int backpack_is_empty(Backpack *bp); */

/*
 * backpack_push()
 * ---------------
 * Push a treasure value (1, 2, or 3) onto the top of the stack.
 * Precondition: backpack must NOT be full (caller handles overflow).
 *
 * TODO: Implement
 */
/* void backpack_push(Backpack *bp, int value); */

/*
 * backpack_pop()
 * --------------
 * Remove and return the top item from the stack.
 * Precondition: backpack must NOT be empty.
 *
 * TODO: Implement
 */
/* int backpack_pop(Backpack *bp); */

/*
 * backpack_peek()
 * ---------------
 * Return the top item WITHOUT removing it.
 * Precondition: backpack must NOT be empty.
 *
 * TODO: Implement
 */
/* int backpack_peek(Backpack *bp); */

/*
 * backpack_discard_top()
 * ----------------------
 * Remove the top item and discard it (no score).
 * Used when backpack is full and player picks up a new treasure.
 *
 * TODO: Implement
 */
/* void backpack_discard_top(Backpack *bp); */

/*
 * backpack_check_merge()
 * ----------------------
 * Check if the top two items in the backpack are identical.
 * If yes:
 *   - Pop both items
 *   - Add score based on treasure type (10 / 40 / 90)
 *   - If treasure type was 3, also add +1 teleport
 *   - Recursively check again (chain merges!)
 *
 * Returns: total points earned from this merge chain
 *
 * TODO: Implement
 */
/* int backpack_check_merge(Backpack *bp, GameState *state); */

#endif /* BACKPACK_H */
