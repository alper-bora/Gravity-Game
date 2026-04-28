/*
 * ============================================================
 *  GRAVITY - Game Initialization & State Management
 * ============================================================
 */

#include "game.h"
#include "player.h"
#include "robot.h"
#include "boulder.h"
#include "input_queue.h"
#include "backpack.h"
#include "utils.h"

/*
 * TODO: Implement game_init()
 *
 * Steps:
 *   1. Clear the entire field
 *   2. Place walls '#' on all border cells
 *        - Top row (row 0), bottom row (row 24)
 *        - Left col (col 0), right col (col 54)
 *   3. Fill all interior cells with earth ':'
 *   4. Randomly pick 180 earth cells -> set to boulder 'O'
 *   5. Randomly pick 30 earth cells  -> set to treasure
 *        (randomly choose '1', '2', or '3' with equal probability)
 *   6. Randomly pick 200 earth cells -> set to empty ' '
 *   7. Randomly pick 7 earth cells   -> set to robot 'X'
 *        (store their positions in the robots array)
 *   8. Randomly pick 1 earth cell    -> set to player 'P'
 *        (store position in player_row, player_col)
 *   9. Initialize backpack: backpack_init()
 *  10. Set teleports = INITIAL_TELEPORTS
 *  11. Set score = 0, time_elapsed = 0, is_game_over = 0
 *  12. Fill input queue: input_queue_init()
 *  13. Set insert_timer = INPUT_INSERT_INTERVAL * TARGET_FPS
 *
 * HINT: Write a helper to pick a random earth cell:
 *       Pick random row/col, if it's earth ':', return it.
 *       Otherwise try again.
 */

/*
 * TODO: Implement game_check_over()
 */

/*
 * TODO: Implement game_update()
 */
