#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct GameDetails {
    string gameID;
    int achievementsUnlocked;
    GameDetails *leftChild;
    float hoursPlayed;
    GameDetails *rightChild;

   
    GameDetails() {
        this->gameID = "";
        this->achievementsUnlocked = 0;
        this->leftChild = nullptr;
        this->hoursPlayed = 0.0;
        this->rightChild = nullptr;
    }

    GameDetails(string id, float hours, int achievements) {
        this->gameID = id;
        this->hoursPlayed = hours;
        this->achievementsUnlocked = achievements;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }

   
    ~GameDetails() {
        delete leftChild;
        delete rightChild;
    }
};

struct PlayerInfo {
    string playerID;
    string fullName;
    string phone;
    string email;
    string password;
    GameDetails *gamesPlayed;
    PlayerInfo *leftChild;
    PlayerInfo *rightChild;

   
    PlayerInfo() {
        this->playerID = "";
        this->fullName = "";
        this->phone = "";
        this->email = "";
        this->password = "";
        this->gamesPlayed = nullptr;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }

    PlayerInfo(string id, string name, string p, string e, string pass) {
        this->playerID = id;
        this->fullName = name;
        this->phone = p;
        this->email = e;
        this->password = pass;
        this->gamesPlayed = nullptr;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }

    
    ~PlayerInfo() {
        delete gamesPlayed; 
        delete leftChild;
        delete rightChild;
    }
};

class PlayerTree {
  public:
    PlayerInfo *root;

    PlayerTree() {
        this->root = nullptr;
    }

  

    void insertPlayer(PlayerInfo *newPlayer) {
        this->root = insertPlayerR(this->root, newPlayer);
    }

    void savePlayers(const string &fileName) {
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            savePlayersR(this->root, outFile);
            outFile.close();
            cout << "Players saved to " << fileName << endl;
        } else {
            cerr << "Error opening file!" << endl;
        }
    }

    void displayPlayers() {
        displayPlayersR(this->root);
    }

    PlayerInfo* searchPlayer(const string &playerID) {
        return searchPlayerR(this->root, playerID);
    }

   
    ~PlayerTree() {
        delete root;  
    }

  private:


    void savePlayersR(PlayerInfo *node, ofstream &outFile) {
        if (node != nullptr) {
            outFile << node->playerID << "," 
                    << node->fullName << "," 
                    << node->phone << "," 
                    << node->email << "," 
                    << node->password << endl;
            saveGamesR(node->gamesPlayed, outFile);
            savePlayersR(node->leftChild, outFile);
            savePlayersR(node->rightChild, outFile);
        }
    }

    void saveGamesR(GameDetails *gameNode, ofstream &outFile) {
        if (gameNode != nullptr) {
            outFile << gameNode->gameID << ","
                    << gameNode->hoursPlayed << ","
                    << gameNode->achievementsUnlocked << endl;
            saveGamesR(gameNode->leftChild, outFile);
            saveGamesR(gameNode->rightChild, outFile);
        }
    }

    void displayPlayersR(PlayerInfo *node) {
        if (node != nullptr) {
            displayPlayersR(node->leftChild);
            cout << "Player ID: " << node->playerID << ", Name: " << node->fullName << endl;
            displayGamesR(node->gamesPlayed);
            displayPlayersR(node->rightChild);
        }
    }

    void displayGamesR(GameDetails *gameNode) {
        if (gameNode == nullptr) {
            cout << "  No games played." << endl;
            return;  // Properly return when no games are present.
        }

       
        cout << "  Game ID: " << gameNode->gameID
             << ", Hours Played: " << gameNode->hoursPlayed
             << ", Achievements: " << gameNode->achievementsUnlocked << endl;

      
        if (gameNode->leftChild != nullptr || gameNode->rightChild != nullptr) {
            displayGamesR(gameNode->leftChild);
            displayGamesR(gameNode->rightChild);
        }
    }

    PlayerInfo* insertPlayerR(PlayerInfo *node, PlayerInfo *newPlayer) {
        if (node == nullptr) {
            return newPlayer;
        }

        if (newPlayer->playerID == node->playerID) {
            cout << "Error: Player with ID " << newPlayer->playerID << " already exists!" << endl;
            return node;
        }

        if (newPlayer->playerID < node->playerID) {
            node->leftChild = insertPlayerR(node->leftChild, newPlayer);
        } else {
            node->rightChild = insertPlayerR(node->rightChild, newPlayer);
        }

        return node;
    }

    PlayerInfo* searchPlayerR(PlayerInfo *node, const string &playerID) {
        if (node == nullptr || node->playerID == playerID) {
            return node;
        }

        if (playerID < node->playerID) {
            return searchPlayerR(node->leftChild, playerID);
        } else {
            return searchPlayerR(node->rightChild, playerID);
        }
    }
};


void generateRandomGameData(GameDetails *gameNode) {
    gameNode->gameID = "Game" + to_string(rand() % 1000);  // Random Game ID between 0 and 999
    gameNode->hoursPlayed = (rand() % 100) + 1;  // Random hours between 1 and 100
    gameNode->achievementsUnlocked = rand() % 50;  // Random achievements between 0 and 50
}

int main() {
    srand(time(0));  

    PlayerTree playerTree;

    PlayerInfo *player1 = new PlayerInfo("123", "Ali", "9876543210", "ali@email.com", "passwordlesgo123");
    PlayerInfo *player2 = new PlayerInfo("456", "Babar", "12345678910", "bobzitheking@email.com", "passwordlesgo456");

  
    playerTree.insertPlayer(player1);
    playerTree.insertPlayer(player2);

    cout << endl << endl << "Players inserted into the tree." << endl;

    
    GameDetails *game1 = new GameDetails("Game1", 20.5, 10);
    generateRandomGameData(game1);  
    player1->gamesPlayed = game1;

    GameDetails *game2 = new GameDetails("Game2", 45.0, 25);
    generateRandomGameData(game2); 
    player2->gamesPlayed = game2;

    cout << "Games added to players." << endl << endl << endl;

  
    cout << "Displaying all players and their games:" << endl << endl;
    playerTree.displayPlayers();
    cout << endl;

    // Save player data to a file
    cout << "Saving player data to file..." << endl;
    playerTree.savePlayers("players_data.txt");
    cout << endl;

   
    cout << "Searching for player with ID '123':" << endl;
    PlayerInfo *searchedPlayer = playerTree.searchPlayer("123");
    if (searchedPlayer != nullptr) {
        cout << "Found player: " << searchedPlayer->fullName << endl;
    } else {
        cout << "Player not found." << endl;
    }
    cout << endl;

    return 0;
}
