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
 *
 * TODO: Implement
 */
/* void display_clear(void); */

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
 *        Format:  Input
 *                 <<<<<<<<<<<<<<<
 *                 |2|O|1|1|O|2|X|3|:|:|1|O|3| |O|
 *                 >>>>>>>>>>>>>>>
 *
 *      - Backpack display (vertical stack, top = top of backpack)
 *        Format:  |   |
 *                 | 2 |
 *                 | 1 |
 *                 | 3 |
 *                 +---+
 *                 Backpack
 *
 *      - Teleport count
 *      - Score
 *      - Time elapsed
 *
 * TODO: Implement
 */
/* void display_render(GameState *state); */

/*
 * display_game_over()
 * -------------------
 * Show the game over screen with final score and time.
 *
 * TODO: Implement
 */
/* void display_game_over(GameState *state); */

#endif /* DISPLAY_H */
