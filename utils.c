/*
 * ============================================================
 *  GRAVITY - Utility Functions Implementation
 * ============================================================
 */

#include "utils.h"
#include "types.h"
#include <stdlib.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#endif

int random_range(int min, int max) { return min + rand() % (max - min + 1); }

void find_random_cell(char field[FIELD_ROWS][FIELD_COLS], cellTypes target_type,
                      int *out_row, int *out_col) {
  int attempts = 0;
  do {
    int r = random_range(1, FIELD_ROWS - 2);
    int c = random_range(1, FIELD_COLS - 2);
    if (field[r][c] == target_type) {
      *out_row = r;
      *out_col = c;
      return;
    }
    attempts++;
  } while (attempts < 10000);
}

long get_elapsed_ms() { return (long)GetTickCount(); }

void sleep_ms(int time) {
  Sleep(time);
  return;
}

int keyboard_hit() { return _kbhit(); }

int keyboard_get() { return _getch(); }
