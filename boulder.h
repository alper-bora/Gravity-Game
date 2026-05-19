/*
 * ============================================================
 *  GRAVITY - Boulder Physics Module
 * ============================================================
 *  Handles all boulder gravity mechanics:
 *    (a) Direct Fall  - Boulder falls if cell below is empty
 *    (b) Side Fall    - Boulder on top of another boulder slides
 *                       to the side if side+below-side are empty
 *    (c) Static       - Player can stand under a static boulder
 *    (d) No Escape    - If player moves DOWN from under a boulder,
 *                       boulder immediately falls into vacated cell
 * ============================================================
 */

#ifndef BOULDER_H
#define BOULDER_H

#include "backpack.h"
#include "types.h"

void boulder_update_all(gameStats *stats, Backpack *bp);

#endif
