/*
 * ============================================================
 *  GRAVITY - Display / Rendering Implementation
 * ============================================================
 */
#include "display.h"
#include "types.h"
#include "utils.h"
#include <stdio.h>
#include <windows.h>

void display_clear() {
  COORD coord = {0, 0};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void display_render(gameStats *stats) {
  display_clear();
  for (int i = 0; i < FIELD_ROWS; i++) {
    for (int j = 0; j < FIELD_COLS; j++) {
      printf("%c", stats->field[i][j]);
    }
    if (i == 0)
      printf("---INPUT QUEUE---");
    if (i == 1) {
      for (int k = 0; k < INPUT_QUEUE_SIZE; k++) {
        printf("%d ", stats->input_queue[k]);
      }
    }
    if (i == 5)
      printf("---BACKPACK---");
    if (i == 6) {
      for (int k = 0; k < BACKPACK_CAPACITY; k++) {
        printf("%d ", stats->backpack[k]);
      }
    }
    if (i == 16)
      printf("Teleports remaining: %d", stats->teleports);
    if (i == 17)
      printf("Total score: %d", stats->score);
    if (i == 18)
      printf("Time: %ld", get_elapsed_ms());
    printf("\n");
  }
}

void display_game_over(gameStats *stats) {
  system("cls");
  printf("***GAME OVER***");
  printf("Final score: %d", stats->score);
  printf("Time survived: %ld", get_elapsed_ms());
  printf("Press any key to exit...");
}