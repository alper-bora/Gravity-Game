/*
 * ============================================================
 *  GRAVITY - Utility Functions
 * ============================================================
 *  Shared helper functions used by multiple modules:
 *    - Random number generation helpers
 *    - Finding random cells of a specific type
 *    - Timing helpers
 *    - Keyboard input helpers (Windows-specific)
 * ============================================================
 */

#ifndef UTILS_H
#define UTILS_H

#include "types.h"

int random_range(int min, int max); // Returns a random number in a range.

void find_random_cell(char field[FIELD_ROWS][FIELD_COLS], cellTypes target_type,
                      int *out_row, int *out_col);
// Finds a random cell that contains the specified cell type. Returns
// row and column via pointers. A max limit is made to stop endless loops.

long get_elapsed_ms(void); // Gets the current time in ms

void sleep_ms(int ms); // Sleeps the CPU for specified time.

int keyboard_hit(void); // Checks if a key has been pressed (non-blocking).
                        // Returns non zero if a key is pressed, 0 otherwise.

int keyboard_get(void); // Read a key from the keyboard (blocking).
                        /* NOTE: Arrow keys send TWO characters on Windows:
                         *   First call returns 0 or 224
                         *   Second call returns the actual key code:
                         *     UP    = 72
                         *     DOWN  = 80
                         *     LEFT  = 75
                         *     RIGHT = 77
                         */

#endif