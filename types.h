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
#define FIELD_ROWS 25
#define FIELD_COLS 55

/* ---- Game Initialization Counts ---- */
#define NUM_BOULDERS 180
#define NUM_TREASURES 30
#define NUM_EMPTY_SQUARES 200
#define NUM_ROBOTS 7

/* ---- Input Queue ---- */
#define INPUT_QUEUE_SIZE 15
#define INPUT_INSERT_INTERVAL 3 /* seconds between insertions */

/* ---- Backpack ---- */
#define BACKPACK_CAPACITY 8

/* ---- Timing ---- */
#define TARGET_FPS 10
#define FRAME_DELAY_MS (1000 / TARGET_FPS) /* 100ms per frame */

/* ---- Starting Teleports ---- */
#define INITIAL_TELEPORTS 3

/* ---- Scoring ---- */
#define SCORE_MERGE_1 10     /* Two 1s merged */
#define SCORE_MERGE_2 40     /* Two 2s merged */
#define SCORE_MERGE_3 90     /* Two 3s merged (also grants +1 teleport) */
#define SCORE_ROBOT_KILL 900 /* Boulder falls on robot */

typedef enum {
  CELL_EMPTY = ' ',
  CELL_EARTH = ':',
  CELL_WALL = '#',
  CELL_BOULDER = 'O',
  CELL_PLAYER = 'P',
  CELL_ROBOT = 'X',
  CELL_TREASURE_1 = '1',
  CELL_TREASURE_2 = '2',
  CELL_TREASURE_3 = '3'
} cellTypes; // Cell type enums

typedef enum {
  DIR_UP,
  DIR_DOWN,
  DIR_LEFT,
  DIR_RIGHT
} direction; // Direction enums

typedef struct {
  int r, c;
} Robot;

typedef struct {
  int items[BACKPACK_CAPACITY];
  int top;
} Backpack; // Backpack struct

typedef struct {
  char field[FIELD_ROWS][FIELD_COLS];
  int player_row;
  int player_col;
  int score;
  int teleports;
  float time_elapsed;
  int is_game_over;
  int backpack[BACKPACK_CAPACITY];
  int input_queue[INPUT_QUEUE_SIZE];
  Robot robots[7];
  int num_robots;
  float insert_timer;
} gameStats; // Game statistics struct

#endif
