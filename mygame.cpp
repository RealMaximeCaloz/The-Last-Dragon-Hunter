#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits> // Needed for std::numeric_limits
#include <cstdlib> // For rand() function
#include <ctime> // For seeding the random number generator

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
        int calculatedMaxHealth = maxHealth + 5;
        std::cout << "Calculated Max Health: " << calculatedMaxHealth << std::endl; // Debugging output
        return calculatedMaxHealth;
    }
    
    // Method to set player's health
    void setHealth(int newHealth) {
        // Add any necessary validation logic here
        std::cout << "Setting health to: " << newHealth << std::endl; // Debugging output
        health = newHealth;
    }

    // Method to set player's xpRequiredToNextLevel
    void setXpRequiredToNextLevel(double multiplier) {
        xpRequiredToNextLevel = static_cast<int>(xpRequiredToNextLevel*multiplier); // Cast to int to truncate the decimal part
        std::cout << "Setting XP Required to reach next level to: " << xpRequiredToNextLevel << std::endl; // Debugging output
    }

    // Method to calculate player's attack based on level and total XP
    int calculateAttack() const {
        // Example logic: attack increases by 1 with each level
        return attack + 1;
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
            std::cout << "Your attack is now: " << getAttack() << "\n";
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
        std::cout << "You deal good damage to " << monster.name << ".\n";
    }
    else if (userInput == 2){
        // Player attacks with a risky attack, 70% chance to deal less damage, 30% chance to deal bonus damage
        std::cout << "Player launches a risky powerful attack!\n";

        int randomNumber = rand() % 100;

        // Risky attack fails and deals reduced damage
        if (randomNumber < 65){
            int damage = static_cast<int>(player.getAttack()*0.5);
            if (damage < 1){
                damage = 1;
            }
            monster.health -= damage;
            std::cout << "Player almost misses and deals poor damage to " << monster.name << ".\n";
        }
        // Risky attack succeeds and deals bonus damage
        else{
            int damage = static_cast<int>(player.getAttack()*2);
            monster.health -= damage;
            std::cout << "Player deals massive damage to " << monster.name << "!\n";        
        }
    }
}

void monsterTurn(Player& player, Monster& monster){
    // Monster's turn
    std::cout << "\nMonster's turn:\n";
    std::cout << "Monster attacks!\n";
    std::cout << "Player health before attack: " << player.getHealth() << "\n"; // Debugging output
    player.setHealth(player.getHealth() - monster.attack); // Update player's health using setHealth method
    std::cout << "Player health after attack: " << player.getHealth() << "\n"; // Debugging output
    if (player.getHealth() <= 0) {
        // Player defeated
        std::cout << "Game over! You have been defeated. Your journey ends here...\n";
        std::cout << "Press any key to exit the game.";
        waitForKeypress();
        exit(0); // End the game if player loses all their health
    }
}

void battleLogic(Player& player, Monster& monster, int currentRoomID) {
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
            // Break out of battleLogic if monster is defeated
            return;
        }

        //Monster's turn
        monsterTurn(player, monster);
    }
}

// Main game loop

// Include Player and Room structures

int main() {
    // Create player object
    Player player(2, 1, 25, 25, 0); // Initial player stats (Attack, level, maxHealth, health, totalXP)

    // Define rooms
    std::vector<Room> rooms = {
        // Define room data here...
        // Room 0: Start room
        {
            0,
            "Welcome. You wake up and look around. You are in a dimly lit corridor. \nWhat do you want to do?",
            {{"Go east", 1}}, // Possible action: Go east to room 1
            0, // No XP gain
            {} // No monsters
        },

        // Room 1: Room with a monster
        {
            1,
            "You enter a large chamber. A baby dragon blocks your path!",
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
    std::cout << "\n" << std::endl;
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

        // // Get player input and navigate to the next room
        // std::cout << "Enter the number of your action: ";
        // int userInput;


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

        // Check for game over conditions, level up, etc.
    }

    return 0;
}