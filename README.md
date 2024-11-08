
# Player Management System (C++)

This C++ program implements a simple player management system using binary search trees (BST) to store player information and their associated game data. The system allows for inserting players, saving their data to a file, searching for players, and displaying the players and their games. Additionally, it simulates random game data generation for each player.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Code Structure](#code-structure)
- [How to Use](#how-to-use)
- [File Format](#file-format)
- [Example](#example)
- [License](#license)

## Overview

The player management system consists of two main entities: **PlayerInfo** and **GameDetails**. 

- **PlayerInfo** stores personal details about a player such as their ID, name, phone number, email, and password.
- **GameDetails** stores data about the games a player has played, such as the game ID, hours played, and achievements unlocked.

The **PlayerTree** class is responsible for managing the collection of players using a binary search tree. Each player can have multiple games associated with them, forming another binary tree for games.

### Core Functions:
1. **Inserting Players**: Allows adding new players to the player tree.
2. **Searching Players**: Searches for players by their unique player ID.
3. **Saving Player Data**: Saves player and game data to a file.
4. **Displaying Players and Games**: Displays all players and their games on the console.
5. **Generating Random Game Data**: Generates random game data for players.

## Features

- **Player Management**: Players are inserted, searched, and displayed using binary search trees.
- **Game Data**: For each player, associated game data is stored in a binary tree, including random values for game hours and achievements.
- **File Export**: Player and game data can be saved to a CSV file (`players_data.txt`).
- **Search Functionality**: The system allows searching for a player by their unique player ID.
  
## Code Structure

### Structs

1. **`GameDetails`**:
    - Represents the game data for a player.
    - Attributes:
        - `gameID`: A unique identifier for each game.
        - `hoursPlayed`: The number of hours the player has played the game.
        - `achievementsUnlocked`: The number of achievements the player has unlocked in the game.
        - `leftChild` & `rightChild`: Pointers to the left and right children in the binary search tree of games.

    - **Constructor**: Initializes the `gameID`, `hoursPlayed`, and `achievementsUnlocked` with given values.

2. **`PlayerInfo`**:
    - Represents a player's personal information and the games they have played.
    - Attributes:
        - `playerID`: A unique identifier for the player.
        - `fullName`: The full name of the player.
        - `phone`: The player's phone number.
        - `email`: The player's email address.
        - `password`: The player's password.
        - `gamesPlayed`: Pointer to the root of the binary search tree that holds the player's games.
        - `leftChild` & `rightChild`: Pointers to the left and right children in the binary search tree of players.

    - **Constructor**: Initializes the player with the provided information.

### Class

- **`PlayerTree`**:
    - Manages the player data using a binary search tree.
    - **Methods**:
        - `insertPlayer(PlayerInfo *newPlayer)`: Inserts a new player into the player tree.
        - `savePlayers(const string &fileName)`: Saves player and game data to a file.
        - `displayPlayers()`: Displays all players and their games in the console.
        - `searchPlayer(const string &playerID)`: Searches for a player by their unique ID.
        - **Destructor**: Properly cleans up memory by deleting all player and game data.

### Functions

- **`generateRandomGameData(GameDetails *gameNode)`**:
    - Generates random game data such as the game ID, hours played, and achievements unlocked.
    - This function simulates game data for players, generating:
        - Random game IDs between `Game0` and `Game999`.
        - Random hours played between `1` and `100`.
        - Random achievements unlocked between `0` and `50`.

### File I/O
- The `savePlayers` method saves the player and their game data in a CSV format to the specified file.
- The data saved includes player information (ID, name, email, etc.) followed by each player's game data (game ID, hours played, achievements unlocked).

## How to Use

### Prerequisites

To run the program, you need to have a C++ compiler such as **g++** or an IDE such as **Visual Studio** or **CLion**.

### Steps

1. **Compile the Program**:
   Use the following command to compile the program:
   ```bash
   g++ -o player_management player_management.cpp
   ```

2. **Run the Program**:
   Once compiled, run the program:
   ```bash
   ./player_management
   ```

3. **View the Output**:
   - The program will display all players and their associated games.
   - It will generate random game data and assign it to each player.
   - It will also save the player and game data to a file named `players_data.txt`.
   - You can search for players using their unique player ID.

4. **Search Function**:
   The program allows searching for a player by entering their unique player ID.

### Example Output

```bash
Players inserted into the tree.

Games added to players.

Displaying all players and their games:

Player ID: 123, Name: Ali
  Game ID: Game123, Hours Played: 20.5, Achievements: 10

Player ID: 456, Name: Babar
  Game ID: Game987, Hours Played: 45.0, Achievements: 25

Saving player data to file...
Players saved to players_data.txt

Searching for player with ID '123':
Found player: Ali
```

The player data is saved in the file `players_data.txt` in the following format:

```
123,Ali,9876543210,ali@email.com,passwordlesgo123
Game123,20.5,10
456,Babar,12345678910,bobzitheking@email.com,passwordlesgo456
Game987,45.0,25
```

## File Format

The saved file is a plain text file with the following format:

1. **Player Information**: Each player is represented by a line with their details (ID, name, phone, email, password).
2. **Game Data**: For each player, their associated games are listed with game ID, hours played, and achievements unlocked.

```
PlayerID,FullName,Phone,Email,Password
GameID,HoursPlayed,Achievements
...
```
![image](https://github.com/user-attachments/assets/68156ab9-9bc4-4219-8880-5bc7fb2beb7e)
