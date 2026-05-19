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

struct Backpack
{
 int items[BACKPACK_CAPACITY];
 int top;
};

void backpack_init(Backpack *bp);

int backpack_is_full(Backpack *bp);

int backpack_is_empty(Backpack *bp);

void backpack_push(Backpack *bp, int value);

int backpack_pop(Backpack *bp);

int backpack_peek(Backpack *bp);

void backpack_discard_top(Backpack *bp);

int backpack_check_merge(Backpack *bp, gameStats *stat);

#endif /* BACKPACK_H */
