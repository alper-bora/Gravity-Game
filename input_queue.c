/*
 * ============================================================
 *  GRAVITY - Input Queue Implementation
 * ============================================================
 */

#include "input_queue.h"
#include "types.h"
#include "utils.h"
#include <stdlib.h>

void input_queue_init(InputQueue *q) {
  q->front = 0;
  q->count = INPUT_QUEUE_SIZE;
  for (int i = 0; i < INPUT_QUEUE_SIZE; i++) {
    q->elements[i] = input_queue_generate_element();
  }
}

char input_queue_generate_element() {
  int r = rand() % 40;
  if (r < 6)
    return '1';
  if (r < 11)
    return '2';
  if (r < 15)
    return '3';
  if (r < 16)
    return 'X';
  if (r < 26)
    return 'O';
  if (r < 35)
    return ':';
  return ' ';
}

void input_queue_insert(InputQueue *q, gameStats *stats) {
  char elem = q->elements[q->front];
  q->front = (q->front + 1) % INPUT_QUEUE_SIZE;
  int row = 0;
  int col = 0;
  int r = rand() % 2;

  switch (elem) {
  case '1':
    if (r) {
      find_random_cell(stats->field, CELL_EMPTY, &row, &col);
    } else
      find_random_cell(stats->field, CELL_EARTH, &row, &col);
    stats->field[row][col] = CELL_TREASURE_1;
    break;
  case '2':
    if (r) {
      find_random_cell(stats->field, CELL_EMPTY, &row, &col);
    } else
      find_random_cell(stats->field, CELL_EARTH, &row, &col);
    stats->field[row][col] = CELL_TREASURE_2;
    break;
  case '3':
    if (r) {
      find_random_cell(stats->field, CELL_EMPTY, &row, &col);
    } else
      find_random_cell(stats->field, CELL_EARTH, &row, &col);
    stats->field[row][col] = CELL_TREASURE_3;
    break;
  case 'X':
    for (int i = 0; i < NUM_ROBOTS; i++) {
      if (stats->robots[i].r == 0 && stats->robots[i].c == 0) {
        find_random_cell(stats->field, CELL_EMPTY, &row, &col);
        stats->field[row][col] = CELL_ROBOT;
        stats->robots[i].r = row;
        stats->robots[i].c = col;
        break;
      }
    }
    break;
  case 'O':
    if (r) {
      find_random_cell(stats->field, CELL_EMPTY, &row, &col);
    } else
      find_random_cell(stats->field, CELL_EARTH, &row, &col);
    stats->field[row][col] = CELL_BOULDER;
    find_random_cell(stats->field, CELL_BOULDER, &row, &col);
    stats->field[row][col] = CELL_EARTH;
    break;
  case ':':
    find_random_cell(stats->field, CELL_EMPTY, &row, &col);
    stats->field[row][col] = CELL_EARTH;
    break;
  case ' ':
    find_random_cell(stats->field, CELL_EARTH, &row, &col);
    stats->field[row][col] = CELL_EMPTY;
    break;
  }

  int back = (q->front + q->count - 1) % INPUT_QUEUE_SIZE;
  q->elements[back] = input_queue_generate_element();
}
