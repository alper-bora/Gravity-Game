/*
 * ============================================================
 *  GRAVITY - Player Module
 * ============================================================
 *  Handles:
 *    - Player movement (4 directions via cursor keys)
 *    - Boulder pushing
 *    - Treasure collection (into backpack)
 *    - Teleportation (Space key)
 *    - Earth digging (converting earth to empty on move)
 * ============================================================
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

void player_process_input(gameStats *stats, Backpack *bp);

void player_collect_treasure(gameStats *stats, Backpack *bp,
                             int treasure_value);

#endif /* PLAYER_H */
