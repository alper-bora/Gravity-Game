/*
 * ============================================================
 *  GRAVITY - Backpack Module Implementation
 * ============================================================
 */

#include "backpack.h"
#include "types.h"

void backpack_init(Backpack *bp)
{
 bp->top = -1;
}

int backpack_is_full(Backpack *bp)
{
 if (bp->top == BACKPACK_CAPACITY - 1) return 1;
 return 0;
}

int backpack_is_empty(Backpack *bp)
{
 if (bp->top == -1) return 1;
 return 0;
}


void backpack_push(Backpack *bp, int value)
{
 if (!backpack_is_full(bp))
 {
  bp->top++;
  bp->items[bp->top] = value;
 }
}

int backpack_pop(Backpack *bp)
{
 if (!backpack_is_empty(bp))
 {
  int val = bp->items[bp->top];
  bp->top--;
  return val;
 }
 return -1;
}

int backpack_peek(Backpack *bp)
{
 if (!backpack_is_empty(bp)) return bp->items[bp->top];
 return -1;
}

void backpack_discard_top(Backpack *bp)
{
 backpack_pop(bp);
}

int backpack_check_merge(Backpack *bp, gameStats *stat)
{
 int total_score = 0;
 while (bp->top >= 1)
 {
  if (bp->items[bp->top] == bp->items[bp->top - 1])
  {
   int merged_value = backpack_pop(bp);
   backpack_pop(bp); // Pop the second one too
   switch (merged_value)
   {
    case 1: total_score += SCORE_MERGE_1; break;
    case 2: total_score += SCORE_MERGE_2; break;
    case 3: 
     total_score += SCORE_MERGE_3; 
     stat->teleports++; 
     break;
   }
  }
  else break;
 }
 return total_score;
}