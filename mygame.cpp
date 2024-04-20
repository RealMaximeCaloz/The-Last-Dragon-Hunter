#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits> 
#include <cstdlib> 
#include <ctime>
#include "rooms.h"

// Player section
class Player {
private:
    int attack;
    int level;
    int maxHealth;
    int health;
    int totalXP;
    int xpRequiredToNextLevel = 100;

public:
    // Constructor
    Player(int initialAttack, int initialLevel, int initialMaxHealth, int initialHealth, int initialTotalXP)
        : attack(initialAttack), level(initialLevel), maxHealth(initialHealth), health(initialHealth), totalXP(initialTotalXP) {
            health = maxHealth;
    }

    // Getter methods
    int getAttack() const { return attack; }
    int getLevel() const { return level; }
    int getMaxHealth() const { return maxHealth; }
    int getHealth() const { return health; }
    int getTotalXP() const { return totalXP; }

    // Method to calculate player's health
    int calculateMaxHealth() const {
        int calculatedMaxHealth = maxHealth + 5;
        return calculatedMaxHealth;
    }
    
    // Method to set player's health
    void setHealth(int newHealth) {
        health = newHealth;
    }

    // Method to set player's xpRequiredToNextLevel
    void setXpRequiredToNextLevel(double multiplier) {
        xpRequiredToNextLevel = static_cast<int>(xpRequiredToNextLevel*multiplier); // Cast to int to truncate the decimal part
    }

    // Method to calculate player's attack based on level and total XP
    int calculateAttack() const {
        return attack + 1;
    }

    // Method to gain XP
    void gainXP(int amount) {
        totalXP += amount;
        // Logic for leveling up if totalXP reaches a certain threshold
        if (totalXP >= xpRequiredToNextLevel){
            level++;
            setXpRequiredToNextLevel(1.75);
            std::cout << "LEVEL UP! You are now level " << level << std::endl; // Debugging output
            attack = calculateAttack();
            std::cout << "Your attack is now: " << getAttack() << "\n";
            maxHealth = calculateMaxHealth();
        }
    }
};

// Game Engine Section:
void waitForKeypress() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cin.get(); // Wait for a keypress
}

// Battle Engine Definition
void playerTurn(Player& player, Monster& monster){
    // Player's turn
    std::cout << "\nPlayer's turn:\n";
    std::cout << "What do you want to do?\n";
    std::cout << "1. Basic Attack\n";
    std::cout << "2. Wild Attack!\n";
    int userInput;

    // Loops until a valid numeric input is provided
    while (!(std::cin >> userInput) || (userInput != 1 && userInput != 2)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter a number: ";
    }

    if (userInput == 1){
        //Player attacks
        std::cout << "Player attacks!\n";
        monster.health -= player.getAttack();
        std::cout << "You deal " << player.getAttack() << " damage to " << monster.name << ".\n";
    }
    else if (userInput == 2){
        // Player attacks with a risky attack, which has a chance to deal bonus or reduced damage
        std::cout << "Player launches a risky powerful attack!\n";

        int randomNumber = rand() % 100;

        // Risky attack fails and deals reduced damage
        if (randomNumber < 65){
            int damage = static_cast<int>(player.getAttack()*0.5);
            if (damage < 1){
                damage = 1;
            }
            monster.health -= damage;
            std::cout << "Player almost misses and deals "<< damage << " damage to " << monster.name << ".\n";
        }
        // Risky attack succeeds and deals bonus damage
        else{
            int damage = static_cast<int>(player.getAttack()*2);
            monster.health -= damage;
            std::cout << "Player deals "<< damage << " damage to " << monster.name << ".\n";        
        }
    }
}

void monsterTurn(Player& player, Monster& monster){
    // Monster's turn
    std::cout << "\nMonster's turn:\n";
    std::cout << "Monster attacks!\n";
    player.setHealth(player.getHealth() - monster.attack); 
    std::cout << "Your health: " << player.getHealth() << "\n";
    if (player.getHealth() <= 0) {
        // Player defeated
        std::cout << "Game over! You have been defeated. Your journey ends here...\n";
        std::cout << "Press any key to exit the game.";
        waitForKeypress();
        exit(0); // End the game if player loses all their health
    }
}

void battleLogic(Player& player, Monster& monster, int currentRoomID) {
    // Keep monster's health in memory to reset its health after the battle, for future encounters
    int monsterMaxHealth = monster.health;

    // Display initial battle message
    std::cout << "A battle begins!\n";
    std::cout << "Player health: " << player.getHealth() << "\n";

    // Battle loop
    while (true) {
        // Player's turn
        playerTurn(player, monster);     

        if (monster.health <= 0) {
            // Monster is defeated
            std::cout << "You defeated the monster!\n";
            // Reset monster's health for potential future encounters against the same monster
            monster.health = monsterMaxHealth;
            // Break out of battleLogic if monster is defeated
            return;
        }
        //Monster's turn
        monsterTurn(player, monster);
    }
}

// Main game loop
int main() {
    // Create player object
    Player player(2, 1, 25, 25, 0); // Initial player stats (Attack, level, maxHealth, health, totalXP)

    // Initialize Rooms
    std::vector<Room> rooms = initializeRooms();

    // Game loop
    int currentRoomID = 0; // Start in the first room
    std::cout << "\n" << std::endl;
    while (true) {
        // Display room description
        std::cout << rooms[currentRoomID].description << std::endl;
        std::cout << "\n" << std::endl;

        // Check for monsters in the room and initiate battle if necessary
        if (!rooms[currentRoomID].monsters.empty()) {
            Monster& monster = rooms[currentRoomID].monsters[0];
            battleLogic(player, monster, currentRoomID);
            std::cout << "You take the time to heal your wounds after battle.\n\n";
            player.gainXP(monster.xpReward);
            player.setHealth(player.getMaxHealth()); // Restore player health after battle
            // Update room ID to next room ID after defeating the monster
            currentRoomID = monster.nextRoomID;
            // Display description of the new room
            std::cout << rooms[currentRoomID].description << std::endl;
            std::cout << "\n" << std::endl;
        }

        // Display possible actions
        std::cout << "Possible actions:\n";
        int actionNumber = 1;
        for (const auto& action : rooms[currentRoomID].actions) {
            std::cout << actionNumber << ". " << action.first << std::endl;
            actionNumber++;
        }

        int userInput;

        while (true){
            std::cout << "Enter the number of your action: ";
            if (!(std::cin >> userInput) || userInput < 1 || userInput > rooms[currentRoomID].actions.size()){
                std::cout << "Invalid action number. Please try again. ";
                std::cin.clear(); // Clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            } else{
                std::cout << "\n";
                auto it = rooms[currentRoomID].actions.begin(); // it = iterator to select correct action
                std::advance(it, userInput - 1); // Move iterator to the selected action
                currentRoomID = it->second; // associated current room ID with the ID of the next room to navigate to
                break; // Exit the loop if valid input is provided
            }
        }
    }
    return 0;
}