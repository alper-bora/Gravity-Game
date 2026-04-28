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

/*
 * random_range()
 * ---------------
 * Generate a random integer in [min, max] inclusive.
 *
 * TODO: Implement
 */
/* int random_range(int min, int max); */

/*
 * find_random_cell()
 * ------------------
 * Find a random cell in the field that contains the specified
 * cell type. Returns the row and col via pointers.
 *
 * Example: find a random earth cell for placing a boulder.
 *
 * WARNING: If no cell of that type exists, this could loop
 * forever. Add a max-attempt limit as a safety measure.
 *
 * TODO: Implement
 */
/* void find_random_cell(char field[FIELD_ROWS][FIELD_COLS],
 *                       char target_type,
 *                       int *out_row, int *out_col); */

/*
 * get_elapsed_ms()
 * ----------------
 * Get the current time in milliseconds (for frame timing).
 * On Windows, use GetTickCount() or timeGetTime().
 *
 * TODO: Implement
 */
/* unsigned long get_elapsed_ms(void); */

/*
 * sleep_ms()
 * ----------
 * Sleep for the specified number of milliseconds.
 * On Windows: Sleep(ms)  (from windows.h)
 *
 * TODO: Implement
 */
/* void sleep_ms(int ms); */

/*
 * keyboard_hit()
 * ---------------
 * Check if a key has been pressed without blocking.
 * On Windows: _kbhit()  (from conio.h)
 *
 * Returns: non-zero if a key is available, 0 otherwise.
 *
 * TODO: Implement
 */
/* int keyboard_hit(void); */

/*
 * keyboard_get()
 * ---------------
 * Read a key from the keyboard (blocking).
 * On Windows: _getch()  (from conio.h)
 *
 * NOTE: Arrow keys send TWO characters on Windows:
 *   First call returns 0 or 224
 *   Second call returns the actual key code:
 *     UP    = 72
 *     DOWN  = 80
 *     LEFT  = 75
 *     RIGHT = 77
 *
 * TODO: Implement
 */
/* int keyboard_get(void); */

#endif /* UTILS_H */
