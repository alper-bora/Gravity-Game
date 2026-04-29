/*
 * ============================================================
 *  GRAVITY - Display / Rendering Module
 * ============================================================
 *  Handles:
 *    - Rendering the 25x55 game field to the console
 *    - Drawing the sidebar (Input Queue, Backpack, Score, etc.)
 *    - Screen clearing and cursor positioning
 *    - Color output (optional, for visual clarity)
 * ============================================================
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include "types.h"

/*
 * display_clear()
 * ---------------
 * Clear the console screen.
 * On Windows: system("cls") or SetConsoleCursorPosition()
 *
 * HINT: For flicker-free rendering, instead of clearing the
 *       whole screen, move cursor to (0,0) and overwrite.
 *       Use SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)
 */
void display_clear(void);

/*
 * display_render()
 * ----------------
 * Draw the complete game screen:
 *
 *   1. The 25x55 game field:
 *      - '#' for walls
 *      - ':' for earth
 *      - ' ' for empty
 *      - 'O' for boulders
 *      - 'P' for player
 *      - 'X' for robots
 *      - '1','2','3' for treasures
 *
 *   2. To the right of the field, draw:
 *      - Input Queue display (showing the 15 elements)
 *      - Backpack display (vertical stack, top = top of backpack)
 *      - Teleport count
 *      - Score
 *      - Time elapsed
 */
void display_render(gameStats *stats);

/*
 * display_game_over()
 * -------------------
 * Show the game over screen with final score and time.
 */
void display_game_over(gameStats *stats);

#endif /* DISPLAY_H */
