#include <iostream>
#include <string>
#include <map>
#include <vector>


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

    // Method to calculate player's health based on level and total XP
    int calculateMaxHealth() const {
        // Example logic: health increases by 5 with each level
        int calculatedMaxHealth = maxHealth + level * 5;
        std::cout << "Calculated Max Health: " << calculatedMaxHealth << std::endl; // Debugging output
        return calculatedMaxHealth;
    }
    
    // Method to set player's health
    void setHealth(int newHealth) {
        // Add any necessary validation logic here
        std::cout << "Setting health to: " << newHealth << std::endl; // Debugging output
        health = newHealth;
    }

    // // Method to set player's totalXP
    // void updateTotalXP(int amount) {
    //     // Add any necessary validation logic here
    //     totalXP += amount;
    //     std::cout << "Setting totalXP to: " << totalXP << std::endl; // Debugging output
    // }

    // Method to set player's xpRequiredToNextLevel
    void setXpRequiredToNextLevel(double multiplier) {
        xpRequiredToNextLevel = static_cast<int>(xpRequiredToNextLevel*multiplier); // Cast to int to truncate the decimal part
        std::cout << "Setting XP Required to reach next level to: " << xpRequiredToNextLevel << std::endl; // Debugging output
    }

    // Method to calculate player's attack based on level and total XP
    int calculateAttack() const {
        // Example logic: attack increases by 1 with each level
        return attack + level * 1;
    }

    // Method to gain XP
    void gainXP(int amount) {
        totalXP += amount;
        // Logic for leveling up if totalXP reaches a certain threshold
        if (totalXP >= xpRequiredToNextLevel){
            level++;
            setXpRequiredToNextLevel(1.25);
            std::cout << "LEVEL UP! You are now level " << level << std::endl; // Debugging output
            attack = calculateAttack();
            maxHealth = calculateMaxHealth();
        }
    }
};



// Rooms section

// Define a struct for monster details
struct Monster {
    std::string name;
    int health;
    int attack;
    std::string description;
    int xpReward;
    int nextRoomID;
};

// Define the Room struct
struct Room {
    int id; // Unique identifier for the room
    std::string description;
    std::map<std::string, int> actions; // Maps action names to room IDs
    int xpGain;
    std::vector<Monster> monsters;
};


// Game Engine Section:

// Battle Engine Definition
void battleLogic(Player& player, Monster& monster, int currentRoomID) {
    // Display initial battle message
    std::cout << "A battle begins!\n";
    std::cout << "Player health: " << player.getHealth() << "\n";

    // Battle loop
    while (true) {
        // Player's turn
        std::cout << "\nPlayer's turn:\n";
        std::cout << "What do you want to do?\n";
        std::cout << "1. Attack\n";
        int userInput;
        std::cin >> userInput;

        if (userInput == 1) {
            // Player attacks
            std::cout << "Player attacks!\n";
            monster.health -= player.getAttack();
            std::cout << "Monster health: " << monster.health << "\n";
            if (monster.health <= 0) {
                // Monster defeated
                std::cout << "You defeated the monster!\n";
                // No need to return anything here
                return;
            }
        } else {
            std::cout << "Invalid action. Please try again.\n";
            continue;
        }

        // Monster's turn
        std::cout << "\nMonster's turn:\n";
        std::cout << "Monster attacks!\n";
        std::cout << "Player health before attack: " << player.getHealth() << "\n"; // Debugging output
        player.setHealth(player.getHealth() - monster.attack); // Update player's health using setHealth method
        std::cout << "Player health after attack: " << player.getHealth() << "\n"; // Debugging output
        if (player.getHealth() <= 0) {
            // Player defeated
            std::cout << "Game over! You have been defeated.\n";
            exit(0); // End the game
        }
    }
}

// Main game loop

// Include Player and Room structures

int main() {
    // Create player object
    Player player(2, 1, 100, 100, 0); // Initial player stats (Attack, level, maxHealth, health, totalXP)

    // Define rooms
    std::vector<Room> rooms = {
        // Define room data here...
        // Room 0: Start room
        {
            0,
            "Welcome. You wake up and look around. You are in a dimly lit corridor. What do you want to do?",
            {{"Go east", 1}}, // Possible action: Go east to room 1
            0, // No XP gain
            {} // No monsters
        },

        // Room 1: Room with a monster
        {
            1,
            "You enter a large chamber. A fearsome dragon blocks your path!",
            {{"Fight the dragon", 2}, {"Flee", 0}}, // Possible actions: Fight the dragon (go to room 2), or flee (go back to room 0)
            0, // No XP gain
            {{"Baby Dragon", 10, 1, "You defeat the dragon and gain 100 XP!", 100, 2}} // Monster details: Name, health, attack, description, XP reward, next room ID
        },

        // Room 2: Room after defeating the dragon
        {
            2,
            "You emerge victorious from the chamber. You see a path leading further into the dungeon.",
            {{"Go forward", 3}}, // Possible action: Go forward to room 3
            0, // No XP gain
            {} // No monsters
        },

        // Room 3: Final room
        {
            3,
            "You find yourself in a treasure room. Riches beyond imagination lie before you!",
            {}, // No possible actions (end of the game)
            0, // No XP gain
            {} // No monsters
        }
    };

    // Game loop
    int currentRoomID = 0; // Start in the first room
    while (true) {
        // Display room description
        std::cout << rooms[currentRoomID].description << std::endl;

        // Check for monsters in the room and initiate battle if necessary
        // if battle, enable battle engine
        // Check for monsters in the room
        // Inside the main loop where you check for monsters in the room and initiate battle if necessary
        if (!rooms[currentRoomID].monsters.empty()) {
            Monster& monster = rooms[currentRoomID].monsters[0]; // Assuming there's only one monster per room for simplicity
            // Call the battleLogic function
            battleLogic(player, monster, currentRoomID); // No need to capture the return value
            std::cout << "You take the time to heal your wounds after battle.\n";
            // Update player's totalXP by the XP reward from the defeated monster
            player.gainXP(monster.xpReward);
            player.setHealth(player.getMaxHealth()); // Restore player health after battle
            // Update room ID to next room ID after defeating the monster
            currentRoomID = monster.nextRoomID;
            // Display description of the new room
            std::cout << rooms[currentRoomID].description << std::endl;

        }

        // If no battle, display possible actions
        // Display possible actions
        std::cout << "Possible actions:\n";
        int actionNumber = 1;
        for (const auto& action : rooms[currentRoomID].actions) {
            std::cout << actionNumber << ". " << action.first << std::endl;
            actionNumber++;
        }

        // Get player input and navigate to the next room
        std::cout << "Enter the number of your action: ";
        int userInput;
        std::cin >> userInput;

        // Process player input and update currentRoomID
        if (userInput >= 1 && userInput <= rooms[currentRoomID].actions.size()) {
            auto it = rooms[currentRoomID].actions.begin(); // it = iterator to select correct action
            std::advance(it, userInput - 1); // Move iterator to the selected action
            currentRoomID = it->second; // associates current room ID with the ID of the next room to navigate to
        } else {
            std::cout << "Invalid action number. Please try again.\n";
        }

        // Check for game over conditions, level up, etc.
    }

    return 0;
}