/*
 * ============================================================
 *  GRAVITY - Utility Functions Implementation
 * ============================================================
 */

#include "utils.h"
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif

/*
 * TODO: Implement random_range()
 *   -> return min + rand() % (max - min + 1);
 */

/*
 * TODO: Implement find_random_cell()
 *
 * Pseudocode:
 *   int attempts = 0;
 *   do {
 *     int r = random_range(1, FIELD_ROWS - 2);
 *     int c = random_range(1, FIELD_COLS - 2);
 *     if (field[r][c] == target_type) {
 *       *out_row = r;
 *       *out_col = c;
 *       return;
 *     }
 *     attempts++;
 *   } while (attempts < 10000);
 *   // Fallback: linear scan if random search keeps failing
 */

/*
 * TODO: Implement get_elapsed_ms()
 *   -> return (unsigned long)GetTickCount();
 */

/*
 * TODO: Implement sleep_ms()
 *   -> Sleep(ms);
 */

/*
 * TODO: Implement keyboard_hit()
 *   -> return _kbhit();
 */

/*
 * TODO: Implement keyboard_get()
 *   -> return _getch();
 */
