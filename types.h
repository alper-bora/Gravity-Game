/*
 * ============================================================
 *  GRAVITY - Type Definitions & Constants
 * ============================================================
 *  Central header defining all game constants, enums, and
 *  data structures used across the project.
 * ============================================================
 */

#ifndef TYPES_H
#define TYPES_H

/* ---- Game Field Dimensions ---- */
#define FIELD_ROWS    25
#define FIELD_COLS    55

/* ---- Game Initialization Counts ---- */
#define NUM_BOULDERS      180
#define NUM_TREASURES      30
#define NUM_EMPTY_SQUARES 200
#define NUM_ROBOTS          7

/* ---- Input Queue ---- */
#define INPUT_QUEUE_SIZE       15
#define INPUT_INSERT_INTERVAL   3   /* seconds between insertions */

/* ---- Backpack ---- */
#define BACKPACK_CAPACITY  8

/* ---- Timing ---- */
#define TARGET_FPS        10
#define FRAME_DELAY_MS   (1000 / TARGET_FPS)  /* 100ms per frame */

/* ---- Starting Teleports ---- */
#define INITIAL_TELEPORTS  3

/* ---- Scoring ---- */
#define SCORE_MERGE_1     10   /* Two 1s merged */
#define SCORE_MERGE_2     40   /* Two 2s merged */
#define SCORE_MERGE_3     90   /* Two 3s merged (also grants +1 teleport) */
#define SCORE_ROBOT_KILL  900  /* Boulder falls on robot */

/* ---- Cell Types ---- */
/* TODO: Define an enum or #defines for each cell type:
 *   CELL_EMPTY   = ' '   (empty square)
 *   CELL_EARTH   = ':'   (earth square)
 *   CELL_WALL    = '#'   (wall - indestructible)
 *   CELL_BOULDER = 'O'   (boulder - subject to gravity)
 *   CELL_PLAYER  = 'P'   (player character)
 *   CELL_ROBOT   = 'X'   (computer/robot)
 *   CELL_TREASURE_1 = '1'
 *   CELL_TREASURE_2 = '2'
 *   CELL_TREASURE_3 = '3'
 */

/* ---- Direction Enum ---- */
/* TODO: Define directions for movement:
 *   DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT
 */

/* ---- Game State Structure ---- */
/* TODO: Define a GameState struct containing:
 *   - field[FIELD_ROWS][FIELD_COLS]  (the game grid)
 *   - player_row, player_col        (player position)
 *   - score                         (current score)
 *   - teleports                     (remaining teleport uses)
 *   - time_elapsed                  (game time in seconds)
 *   - is_game_over                  (boolean flag)
 *   - backpack                      (Backpack struct)
 *   - input_queue                   (InputQueue struct)
 *   - robots[]                      (array of Robot positions)
 *   - num_robots                    (current robot count)
 *   - insert_timer                  (frames until next queue insertion)
 */

#endif /* TYPES_H */
