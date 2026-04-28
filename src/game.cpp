/*
Author: Yen Her/Brice Yang
Class: game

Description:
The main logic class of the game. Everything in this class handles all decision-making in the game. It links every other class in the program together.
Functions here handle all logic of world building, combat, inventory, movement, and player choices.
*/

#include "game.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "objectInstances.h"
using namespace std;


//Function to build the world be connecting all the rooms together. Called beforehand to set up the world. 
void Game::buildWorld(){

    // Sets Room Directions
    room1.setEast(&room2);
    room1.setSouth(&room3);
    room2.setWest(&room1);
    room2.setSouth(&room4);
    room3.setNorth(&room1);
    room3.setEast(&room4);
    room4.setNorth(&room2);
    room4.setWest(&room3);
    room4.setSouth(&room5);
    room5.setNorth(&room4);
    room5.setSouth(&room6);
    room6.setNorth(&room5);

    // Sets up Enemies in Rooms
    //room1.setEnemy(&enemy1); // No enemy in entrance room. For now.
    room2.setEnemy(&enemy2);
    room3.setEnemy(&enemy3);
    room4.setEnemy(&enemy4);
    room5.setEnemy(&enemy5);

    // Sets up Allied NPCs
    room1.setAlly(&ally1);

    //Set up Inventory
    items["sword"] = std::make_unique<Item>("Sword");
    items["apple"] = std::make_unique<Item>("Apple");
    items["key"] = std::make_unique<Item>("Key");

    player.getInventory().addItem(items["sword"].get());
    player.getInventory().addItem(items["apple"].get());
    player.getInventory().addItem(items["key"].get());
}

Game::Game() : gameOver(false) {
    buildWorld();
    currentRoom = &room1; //Start in the entrance room, this helps keep track of where we are in the world! VERY IMPORTANT!
}

bool Game::isGameOver() const {
    return gameOver;
}

void Game::start() {
    cout << "Game Object Ran!" << endl;
}

void Game::showHelp() const { // Lists available commands
    cout << 
        "Welcome to Help Screen!\n" << 
        "Available Commands:\n" <<
        "0: Quit Game\n" <<
        "1: Describe Current Room\n" <<
        "2: Check Inventory\n" <<
        "3: Move in a Direction \n" <<
        "4: Talk to Ally\n" <<
        "5: Show Help Screen\n";  
}

void Game::showInventory() const {
    player.getInventory().display();
}

void Game::describeCurrentRoom() const { // Gives a description of the current room
    cout << currentRoom->getDescription() << endl; 
}

//function made to move the player from room to room based on the direction they choose. Checks if the move is valid and updates the current room accordingly.
void Game::move(const std::string& direction) {
    normalizeDirection(direction);
    Rooms* next = nullptr;
    if (direction == "north") next = currentRoom->getNorth();
    else if (direction == "south") next = currentRoom->getSouth();
    else if (direction == "east") next = currentRoom->getEast();
    else if (direction == "west") next = currentRoom->getWest();
    else {
        cout << "Invalid direction. Please enter north, south, east, or west.\n" << endl;
        return;
    }
    if (next) {
        checkEnemy(next); // Checks if there is an enemy in the next room and initiates combat if there is.
        if(next->getEnemy() == nullptr){  // Checks if there is an enemy. If none, move to next room.
            currentRoom = next;
            checkEnd(currentRoom);
            cout << "You entered into: " << currentRoom->getRoomName() << "." << endl;
        }
    } else {
        cout << "You can't move " << direction << " from here." << endl;
    }
}

// Helper function to normalize direction input
std::string Game::normalizeDirection(const std::string& direction) const {
    std::string normalized = direction;
    std::transform(normalized.begin(), normalized.end(), normalized.begin(), ::tolower);
    return normalized;
}

void Game::checkEnemy(Rooms* next) { // Checks if there should be an Enemy within the next room. Then displays a warning and choice to enter combat.
    Enemies* enemy = next->getEnemy();
    if (enemy) {
        cout << enemy->displayWarning() << endl;
        cout << "Do you want to enter combat? (0:No|1:Yes): ";

        int choice;
        cin >> choice;
        if (choice == 1) {
            fightEnemy(next);
        } else if(choice == 0){
            cout << "You return back to the room you were in, avoiding combat." << endl;
        } else{
            cout << "Invalid choice. Try again." << endl;
            checkEnemy(next);
        }
    }
}

void Game::attackEnemy(Rooms* next) { // Attacks the enemy within the room
    Enemies* enemy = next->getEnemy();
    if (!enemy) {
        cout << "You attack the air." << endl;
        return;
    }

    int damage = 25; // Player attack Damage.
    enemy->takeDamage(damage);
    cout << "You hit the " << enemy->getName() << " for "<< damage << " damage." << endl;

    if (enemy->getHp() == 0) { // Sets the room pointer to null after the enemy is defeated
        cout << "Enemy defeated!\n" << endl;
        next->setEnemy(nullptr);
    } else {
        cout << "Enemy HP remaining: " << enemy->getHp() << endl;
    }
}

void Game::fightEnemy(Rooms* next){ // Handles Enemy Combat
    while(next->getEnemy() != nullptr){ // While there is still an enemy in the room, continue combat.
        cout << "What will you do? (0: Attack | 1: THERE IS NO OTHER OPTION): ";
        int choice;
        cin >> choice;
        if(choice == 0){
            attackEnemy(next);
        } else if(choice == 1){
            cout << "FIGHT!" << endl;
            fightEnemy(next);
        } else{
            cout << "Invalid choice. Try again." << endl;
            fightEnemy(next);
        }
    }
}

void Game::talkToAlly() {
    Allies* ally = currentRoom->getAlly();
    if (ally) {
        cout << ally->getMessage() << endl;
    } else {
        cout << "There is no one to talk to here." << endl;
    }
}

void Game::checkEnd(Rooms* Room){
    if(Room->getRoomName() == "Freedom!"){
        setGameOver();
    }
}

void Game::setGameOver() {
    gameOver = true;
}

void Game::choice() { // Deals with User Input and choices.
    int choice; 
    cout << "Choose an option ('5' For Help): "; // Choice Prompt
    cin >> choice; // Choice value
    if (cin.fail()) { // Checks if the input is valid, if not it clears the error and ignores the rest of the input, then prompts the user to try again.    
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n" << endl;
        return;
    }

    cout << " " << endl; // Adds a blank line for better readability
    switch (choice) { // Switch statement to handle player choice
        case 0: // Quit option.
            setGameOver();
            break; 
        case 1: // Describe Current Room.
            describeCurrentRoom();
            break;
        case 2: // Show Inventory.
            showInventory();
            break;
        case 3:{ // Asks for direction input, then moves the User. --> Changed to normalizDirection()
            string direction;
            cout << "Enter a direction to move (north, south, east, west): "; // Direction Prompt.
            cin >> direction;
            move(string(direction));
            break;
        } 
        case 4: // Initiates Ally Dialogue.
            talkToAlly();
            break;
        case 5: // Shows help screen.
            showHelp();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
    cout << " " << endl; // Adds a blank line for better readability

}