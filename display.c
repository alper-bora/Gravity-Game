/*
 * ============================================================
 *  GRAVITY - Display / Rendering Implementation
 * ============================================================
 */
#include "display.h"
#include "input_queue.h"
#include "types.h"
#include "utils.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>

void display_clear() {
  COORD coord = {0, 0};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void display_render(gameStats *stats, Backpack *bp, InputQueue *q) {
  display_clear();
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  for (int i = 0; i < FIELD_ROWS; i++) {
    for (int j = 0; j < FIELD_COLS; j++) {
      switch (stats->field[i][j]) {
      case CELL_PLAYER:
        SetConsoleTextAttribute(hConsole,
                                FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("%c", stats->field[i][j]);
        break;
      case CELL_EARTH:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
        printf("%c", stats->field[i][j]);
        break;
      case CELL_ROBOT:
        SetConsoleTextAttribute(hConsole,
                                FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("%c", stats->field[i][j]);
        break;
      case CELL_WALL:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
        printf("%c", stats->field[i][j]);
        break;
      case CELL_TREASURE_1:
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY |
                                              FOREGROUND_RED | FOREGROUND_BLUE);
        printf("%c", stats->field[i][j]);
        break;
      case CELL_TREASURE_2:
        SetConsoleTextAttribute(
            hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        printf("%c", stats->field[i][j]);
        break;
      case CELL_TREASURE_3:
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY |
                                              FOREGROUND_RED | FOREGROUND_BLUE);
        printf("%c", stats->field[i][j]);
        break;
      case CELL_BOULDER:
      case CELL_BOULDER_FALLING:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
        printf("%c", CELL_BOULDER);
        break;
      default:
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED |
                                              FOREGROUND_BLUE);
        printf("%c", stats->field[i][j]);
        break;
      }
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED |
                                          FOREGROUND_BLUE);
    if (i == 0)
      printf("  ---INPUT QUEUE---");
    if (i == 1) {
      printf("  ");
      for (int k = 0; k < INPUT_QUEUE_SIZE; k++) {
        int idx = (q->front + k) % INPUT_QUEUE_SIZE;
        printf("%c ", q->elements[idx]);
      }
    }
    if (i == 5)
      printf("  ---BACKPACK---");
    if (i == 6) {
      printf("  ");
      for (int k = bp->top; k >= 0; k--) {
        printf("%d ", bp->items[k]);
      }
    }
    if (i == 16)
      printf("  Teleports remaining: %d", stats->teleports);
    if (i == 17)
      printf("  Total score: %d", stats->score);
    if (i == 18)
      printf("  Time: %.1fs", stats->time_elapsed);
    printf("\n");
  }
}

void display_game_over(gameStats *stats) {
  system("cls");
  printf("***GAME OVER***\n");
  printf("Final score: %d\n", stats->score);
  printf("Time survived: %.1fs\n", stats->time_elapsed);
  printf("Press any key to exit...\n");
  _getch();
}