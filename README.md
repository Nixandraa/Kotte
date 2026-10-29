# Bomberman World
**Student:** Nina Aleksandra Zarna

## How to play

- **Controls:** To move, use WASD or arrow keys. To drop a bomb, press SPACE. To remotely detonate a bomb, press ENTER. To restart the game, press R. To quit the game, press Q or ESC key.
- **Objective and rules:** To win the game, the player must kill 5 enemies by using a bomb. The player has a pool consisting of 5 bombs. Once detonated, the bomb returns to the player’s inventory. The player has 1 health point (HP), which means that any collision with an enemy or a bomb results in a loss. During the game, the player can gain a temporary invulnerability. The shield activates automatically for 5 seconds every 2 kills. 
- **Configurations / demo setup:** Default.

## Features and validation

| Feature | Check, observed result, and expected behaviour |
| --- | --- |
| 1. Player damage and death | I walked very close next to the enemy, without touching it, then I walked straight into it. I survived while passing next to enemy, but died when I touched the enemy, what was an expected behaviour. |
| 2. Round states and objective | I tried to first lose the game and then I tried to win. In both cases, the game became frozen after reaching the win/lose state. I couldn't move or place any bomb, enemies were not moving as well, what was an expected behaviour. |
| 3. Safe restart | I placed a bomb and then immediately bumped into the enemy, and then pressed R to restart the game. I performed this action multiple times. Every time, before restarting (when game was lost) I didn't have that bomb available, but after pressing restart, the bomb became available again, what was an expected behaviour. |
| 4. Solid bombs with owner escape | I placed a bomb, tried to leave,and then tried to move on top of the bomb again. I could move right away after placing the bomb, but couldn't go on top of it afterwards, what was an expected behaviour. |
| 5. Blast-range pickup | I placed a bomb, then I picked-up the buff before the bomb exploaded. After it exploaded, I placed another bomb and watched its blast. The first bomb, despite picking up the buff, had a blast before the buff (=3). The new bomb already had a buffed blast (=4), what was an expected behaviour.   |
| 6. Multiple bombs per owner | I placed 5 bombs (max capacity), and then tried to place 6th. When I reached the capacity, I couldn't place any other bomb. Once 1 bomb exploaded, I was able to place it back again so after explosion it returned to the pool, what was an expected behaviour.  |
| 8. Shield or temporary invulnerability | Once the shield was active I tried to bump into an enemy and stand inside the bomb. I tried to do the same while shield was inactive. While active, I wasn't getting any damage, but once the shield wore off, both enemy and bomb caused damage, what was an expected behaviour. |
| 13. Remote-detonated bombs | I placed the bomb, moved away and pressed enter to detonate it. Then, while no bomb was placed, I pressed enter multiple times. While bomb was active on the map, pressing enter caused detonation, but without any bomb on the map, pressing enter had no effect and didn't cause any game crash, what was an expected behaviour. |

**Known issues:** None known after testing.

## Sources and assistance

This project builds on the shared Kotte foundations.
While working on the project, I used the below websites for learning, syntax explanation, and debugging guidance. 
https://en.cppreference.com/
https://stackoverflow.com/
https://www.geeksforgeeks.org/
