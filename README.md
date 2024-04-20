# Text-Based Adventure Game Engine + Game: The Last Dragon Hunter

# Project Overview
This project was made with C++ and the MSYS2 compiler.

This project is a game engine that allows users to create text-based adventure games.

The game engine allows players to interact with a text-based UI in order to progress through an adventure as the main character.

The player can navigate to different rooms and areas, and their choices dictate how the game plays out.

The game engine also comes coded with a battle engine, allowing for thrilling battle encounters with foes.

As the player accumulates victories, they will level up, resulting in strengthened personal attributes.

A game has also been created with this game engine. 

The game is called The Last Dragon Hunter and follows the story of a 220 year old dragon hunter, left alone to fend off organized attacks by the repopulating dragons.

Down below, you can see a screenshot of the game and game engine in action:
![game](https://github.com/RealMaximeCaloz/Portfolio/blob/4692cc69ce89ab5b3396e04c3d928a71023e3056/the_last_dragon_hunter_gameplay_screenshot.png)

The game engine works as follows:

There is a main loop in mygame.cpp which handles all the logic for displaying the text descriptions of each room, and the navigation between each room.

If the player enters a room where there is an enemy encounter defined, the Battle Engine will activate and handle the logic for the player and the foe taking turns dealing damage to each other.

In the rooms.cpp file, there is a list of all the rooms the player can potentially enter during gameplay. Each room leads to one or more other rooms, depending on player input.

Each room is defined with the following structure:
```
{
    roomID,
    "String Description displayed when you enter the room",
    {{"String for choice 1", roomID_to_navigate_to_after_choice},{"String for choice 2", roomID_to_navigate_to_after_choice}}, 
    0, // XP gain when you enter this room
    {{"Monster name String", monster_health, monster_attack, "String description displayed if you win the battle", XP_reward_after_battle,roomID_to_navigate_to_after_battle}}
}
```

The roomID is an integer allowing easy referencing to a specific room.

The String Description is what is displayed on the UI whenever the player enters a given room.

The Strings representing choices are usually displayed after the description, before user input is requested.

An XP gain integer is defined (usually as 0) in case the player finds some sort of special item (e.g. a potion) that would grant them extra XP upon room entry.

A Monster struct is defined within the rooms with an enemy encounter.


The infrastructure mentionned above offers text-based adventure game creators a flexible and relatively simple development experience, comprehensible even for non-developers.

# Installation
1. Clone this repository:
```
$ git clone https://github.com/RealMaximeCaloz/.git
``` 

# How to Run "The Last Dragon Hunter"
1. Open CMD prompt.
2. Navigate (cd) to folder where mygame.exe is located.
3. Run the command `mygame.exe`.
4. Enjoy the game!

# How to build your own game with this Game Engine
1. Change the rooms in `rooms.cpp`, filling them up with the story descriptions, enemy encounters, and other details you would like to include. 

Each room has the following structure:
```
{
    roomID,
    "String Description displayed when you enter the room",
    {{"String for choice 1", roomID_to_navigate_to_after_choice},{"String for choice 2", roomID_to_navigate_to_after_choice}}, 
    0, // XP gain when you enter this room
    {{"Monster name String", monster_health, monster_attack, "String description displayed if you win the battle", XP_reward_after_battle,roomID_to_navigate_to_after_battle}}
}
```
2. Make sure you have the MSYS2 C++ compiler (https://www.msys2.org/) installed.
3. Build the game (.exe file) with the command below.
```
g++ -fdiagnostics-color=always -g "path_to_your_project_folder\rooms.cpp" "path_to_your_project_folder\mygame.cpp" -o "path_to_your_project_folder\mygame.exe"
```
4. Open CMD prompt.
5. Navigate (cd) to folder where mygame.exe is located.
6. Run the command `mygame.exe`.
7. Enjoy your game game!
