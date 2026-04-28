/*
 * ============================================================
 *  GRAVITY - Display / Rendering Implementation
 * ============================================================
 */

#include "display.h"
#include <stdio.h>

/* Windows-specific includes for console manipulation */
#ifdef _WIN32
#include <windows.h>
#endif

/*
 * TODO: Implement display_clear()
 *
 * Option A (simple but causes flicker):
 *   system("cls");
 *
 * Option B (flicker-free, recommended):
 *   COORD coord = {0, 0};
 *   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
 */

/*
 * TODO: Implement display_render()
 *
 * Pseudocode:
 *   display_clear()
 *
 *   for each row 0..FIELD_ROWS-1:
 *     for each col 0..FIELD_COLS-1:
 *       print field[row][col]
 *
 *     // After printing the field row, print sidebar info
 *     // on specific rows:
 *     //   Row 0-2:  Input Queue display
 *     //   Row 5-14: Backpack display
 *     //   Row 16:   Teleport count
 *     //   Row 17:   Score
 *     //   Row 18:   Time
 *
 *     print newline
 *
 * OPTIONAL: Use Windows console colors for visual clarity
 *   SetConsoleTextAttribute(handle, color_code)
 *   Example colors:
 *     Player 'P'    -> Green
 *     Robots 'X'    -> Red
 *     Boulders 'O'  -> Yellow/Brown
 *     Treasures     -> Cyan/Magenta
 *     Earth ':'     -> Dark Yellow
 *     Walls '#'     -> White/Gray
 */

/*
 * TODO: Implement display_game_over()
 *
 *   Clear screen
 *   Print "GAME OVER"
 *   Print final score
 *   Print time survived
 *   Print "Press any key to exit..."
 */
