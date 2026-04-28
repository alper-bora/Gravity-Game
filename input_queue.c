/*
 * ============================================================
 *  GRAVITY - Input Queue Implementation
 * ============================================================
 */

#include "input_queue.h"
#include "utils.h"
#include <stdlib.h>

/*
 * TODO: Implement input_queue_init()
 *   -> Loop INPUT_QUEUE_SIZE times
 *   -> For each slot, call input_queue_generate_element()
 *   -> Set front = 0, count = INPUT_QUEUE_SIZE
 */

/*
 * TODO: Implement input_queue_generate_element()
 *
 * Pseudocode:
 *   int r = rand() % 40;
 *   if (r < 6)  return '1';
 *   if (r < 11) return '2';
 *   if (r < 15) return '3';
 *   if (r < 16) return 'X';
 *   if (r < 26) return 'O';
 *   if (r < 35) return ':';
 *   return ' ';
 */

/*
 * TODO: Implement input_queue_insert()
 *
 * Pseudocode:
 *   char elem = q->elements[q->front]
 *   q->front = (q->front + 1) % INPUT_QUEUE_SIZE
 *
 *   switch (elem):
 *     case '1': case '2': case '3':
 *       find random empty/earth cell -> set to treasure
 *     case 'X':
 *       find random empty/earth cell -> set to robot
 *       add to robots array
 *     case 'O':
 *       find random empty/earth cell -> set to boulder
 *       find random existing boulder -> set to earth
 *       (net boulder count stays same)
 *     case ':':
 *       find random empty cell -> set to earth
 *     case ' ':
 *       find random earth cell -> set to empty
 *
 *   // Generate new element for back of queue
 *   int back = (q->front + q->count - 1) % INPUT_QUEUE_SIZE
 *   q->elements[back] = input_queue_generate_element()
 */
