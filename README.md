# Project: Gravity (EED 1010)

A maze-based strategy game where players collect treasures while navigating a dynamic environment affected by gravity.

## Game Overview
The game is played on a 25x55 field. The goal is to achieve the highest score by collecting treasures while avoiding computer-controlled robots and falling boulders.

### Game Elements
- **P (Player):** Controlled by the user.
- **X (Computer Robots):** Move randomly and attempt to catch the player.
- **1, 2, 3 (Treasures):** Collected to increase score and gain teleport rights.
- **O (Boulder):** Affected by gravity; can fall or be pushed.
- **: (Earth):** Can be converted to empty squares by moving over them.
- **# (Wall):** Static boundaries.

## Controls
- **Cursor Keys:** Move the player.
- **Left/Right Cursor Keys:** Push a boulder (if an empty square is behind it).
- **Space:** Teleport to a random earth square (requires teleport rights).

## Mechanics
- **Backpack:** Holds up to 8 treasures. Identical treasures at the top are converted into score and teleport rights.
- **Gravity:** Boulders fall if there is an empty square below them. They can also slide off other boulders.
- **Input Queue:** New game elements are introduced every 3 seconds.
- **Game Over:** Occurs if a boulder falls on the player or a robot reaches the player.

## Scoring
- **Treasure 1:** 10 points (for a pair)
- **Treasure 2:** 40 points (for a pair)
- **Treasure 3:** 90 points + 1 teleport right (for a pair)
- **Robot destruction:** 900 points if a boulder falls on a robot.

## Build and Run
This project is written in C. To compile and run:
```bash
gcc *.c -o gravity_game
./gravity_game
```
