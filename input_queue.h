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

/* TODO: Define an InputQueue struct:
 *   - elements[INPUT_QUEUE_SIZE]  (array of char, the queue contents)
 *   - front                       (index of first element)
 *   - count                       (number of elements in queue)
 */

/*
 * input_queue_init()
 * ------------------
 * Fill the queue with INPUT_QUEUE_SIZE random elements
 * using the generation probabilities listed above.
 *
 * TODO: Implement
 */
/* void input_queue_init(InputQueue *q); */

/*
 * input_queue_generate_element()
 * ------------------------------
 * Generate a single random element based on the probability
 * distribution (out of 40 total):
 *   Roll a random number 0-39:
 *     0-5   -> '1'
 *     6-10  -> '2'
 *     11-14 -> '3'
 *     15    -> 'X'
 *     16-25 -> 'O'
 *     26-34 -> ':'
 *     35-39 -> ' '
 *
 * TODO: Implement
 */
/* char input_queue_generate_element(void); */

/*
 * input_queue_insert()
 * --------------------
 * Take the front element out of the queue and apply it to the maze.
 * Then generate a new element and add it to the back.
 *
 * Steps:
 *   1. Dequeue the front element
 *   2. Apply conversion rules (see header comment above)
 *   3. Generate a new element and enqueue it
 *
 * TODO: Implement
 */
/* void input_queue_insert(InputQueue *q, GameState *state); */

#endif /* INPUT_QUEUE_H */
