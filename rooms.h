// rooms.h
#ifndef ROOMS_H
#define ROOMS_H

#include <string>
#include <map>
#include <vector>

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

// Function to initialize the vector of rooms
std::vector<Room> initializeRooms();

#endif // ROOMS_H