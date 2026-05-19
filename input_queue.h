/*
 * ============================================================
 *  GRAVITY - Input Queue Module
 * ============================================================
 *  The input queue holds 15 elements. Every 3 seconds, the
 *  first element is inserted into the maze at a random position.
 *  A new random element is generated and added to the end.
 *
 *  Element generation probabilities (out of 40):
 *    '1' (treasure 1): 6/40
 *    '2' (treasure 2): 5/40
 *    '3' (treasure 3): 4/40
 *    'X' (robot):      1/40
 *    'O' (boulder):   10/40
 *    ':' (earth):      9/40
 *    ' ' (empty):      5/40
 *
 *  Conversion rules when an element is inserted:
 *    '1' -> random empty/earth square becomes treasure 1
 *    '2' -> random empty/earth square becomes treasure 2
 *    '3' -> random empty/earth square becomes treasure 3
 *    'X' -> random empty/earth square becomes robot
 *    'O' -> random empty/earth square becomes boulder
 *           AND a random existing boulder becomes earth
 *           (total boulder count stays constant!)
 *    ':' -> random empty square becomes earth
 *    ' ' -> random earth square becomes empty
 * ============================================================
 */

#ifndef INPUT_QUEUE_H
#define INPUT_QUEUE_H

#include "types.h"

typedef struct {
  char elements[INPUT_QUEUE_SIZE];
  int front;
  int count;
} InputQueue;

void input_queue_init(InputQueue *q);

char input_queue_generate_element(void);

void input_queue_insert(InputQueue *q, gameStats *stats);
#endif
