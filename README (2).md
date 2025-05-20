# Catan Game Explanation

## Overview
This project is a command-line implementation of the popular board game "Catan".  
The game is played by multiple players who take turns to build settlements, roads, and cities, trade resources, and play development cards.  
The goal is to be the first player to reach 10 victory points.

---

## Map of the game
The map of the game is also here under the name **"BOARD MAP"**.  
In the map you can find the resources and all the corners and edges ID.

---

## How to run it

### To run the game
- Open the terminal in the file where all the files are
- Write: `make`
- Then: `./Main`

### To run the tests
- Open the terminal in the file where all the files are
- Create a new folder named `test`
- Write: `cmake ..`
- Then: `make`
- Then: `./test_catan`

---

## Commands
Commands are used to interact with the game.  
Each command corresponds to an action a player can take.  
Here is a list of available commands:

### Roll Dice
- **Command:** `1`
- **Description:** Roll the dice to generate resources. If 7 is rolled, the robber is activated.

### Build Road
- **Command:** `2`
- **Example:** `2 5` (build road on edge 5)

### Build Settlement
- **Command:** `3`
- **Example:** `3 10` (build settlement on corner 10)

### Upgrade Settlement to City
- **Command:** `4`
- **Example:** `4 15` (upgrade settlement on corner 15)

### Draw Development Card
- **Command:** `5`

### Trade with Bank
- **Command:** `6`
- **Example:** `6 WOOD BRICK`

### Play Development Card
- **Command:** `play_card [card_type]`
- **Valid Types:** `road_building`, `year_of_plenty`, `monopoly`

### End Turn
- **Command:** `8`

### Exit
- **Command:** `7`

---

## Development Cards

### Road Building
Allows the player to build two roads for free.

### Year of Plenty
Allows the player to take any two resources.

### Monopoly
Takes all of one resource from all other players.

---

## Robber
When a dice roll is `7`:
- No resources are distributed
- Players with more than 7 resources discard half
- The current player moves the robber to block a tile

---

## Victory Points
Victory points determine the winner.  
The first player to reach 10 points wins.

- Settlements: 1 point
- Cities: 2 points
- Longest Road: 2 points
- Largest Army: 2 points
- Victory Point Cards: 1 point

---

## Functions

### Board Class Functions
- `initialize()`: Sets up board
- `printBoard()`
- `addPlayer(int id)`
- `rollDice()`
- `distributeResources(int diceRoll)`
- `moveRobber(int tileId)`
- `handleRobber()`
- `addSettlement(int cornerId, int playerId)`
- `upgradeSettlement(int cornerId, int playerId)`
- `addRoad(int edgeId, int playerId)`
- `drawDevelopmentCard(int playerId)`
- `processCommand(...)`
- `processCommandWithBankTrade(...)`
- `playDevelopmentCard(...)`
- `playRoadBuilding(...)`
- `playYearOfPlenty(...)`
- `playMonopoly(...)`
- `calculateLongestRoad(int playerId)`
- `endGame() const`

### Player Class Functions
- `Player(int id)`
- `addDevelopmentCard(...)`
- `hasResources(...)`
- `spendResources(...)`
- `gainResources(...)`
- `tradeWithBank(...)`
- `calculateVictoryPoints()`

---

## Connections Between Functions
- The main game loop (`main()`) takes player input and calls `processCommand()`
- `distributeResources()` gives resources after dice roll
- Development cards are handled by specific functions
- Victory is calculated using `calculateVictoryPoints()` and `calculateLongestRoad()`
