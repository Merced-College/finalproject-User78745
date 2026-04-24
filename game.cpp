#include "game.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "rooms.h"
using namespace std;


// Create five instances of the room class, this will be our rooms
Rooms room1("Entrance", "R001", "A dark and eerie entrance to the dungeon. The air is thick with the smell of damp stone and decay.");
Rooms room2("The Dining Hall", "R002", "A large, grand dining hall with a long table at the center. The walls are adorned with faded tapestries, and the air is filled with the scent of decay and rot.");
Rooms room3("The Armory", "R003", "A small, cramped armory filled with rusted weapons and armor. The air is thick with the smell of metal and dust.");
Rooms room4("The Treasury", "R004", "A luxurious treasury filled with gold and precious gems. The air is thick with the scent of wealth and opulence.");
Rooms room5("The Escape Route", "R005", "A hidden passage that leads to freedom. The air is fresh and clean, a stark contrast to the rest of the dungeon.");

//Function to build the world be connecting all the rooms together. Called beforehand to set up the world. 
void Game::buildWorld(){
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
}

//figure out what room we are currently in?



Game::Game() : gameOver(false) {
    buildWorld();
    currentRoom = &room1; //Start in the entrance room, this helps keep track of where we are in the world! VERY IMPORTANT!
}

bool Game::isGameOver() const {
    return gameOver;
}

void Game::start() {
    buildWorld(); // Sets up rooms, enemies, and allies.
    cout << "Game Object Ran!" << endl;
}

void Game::showHelp() const { // Lists available commands
    cout << 
        "Welcome to Help Screen!\n" << 
        "Available Commands:\n" <<
        "0: Quit Game\n" <<
        "1: Describe Current Room\n" <<
        "2: Show Player Status\n" <<
        "3: Move in a Direction \n" <<
        "4: Attack Enemy\n" <<
        "5: Talk to Ally\n" <<
        "6: Show Help Screen\n";  
}

void Game::status() const {
    cout << "No clue what you mean by Game::status()." << endl;
}

void Game::describeCurrentRoom() const { // Gives a description of the current room
    cout << currentRoom->getDescription() << endl; 
}

//function made to move the player from room to room based on the direction they choose. Checks if the move is valid and updates the current room accordingly.
void Game::move(const std::string& direction) {
    std::string dir = normalizeDirection(direction);
    Rooms* next = nullptr;
    if (dir == "north") next = currentRoom->getNorth();
    else if (dir == "south") next = currentRoom->getSouth();
    else if (dir == "east") next = currentRoom->getEast();
    else if (dir == "west") next = currentRoom->getWest();
    else {
        cout << "Invalid direction. Please enter north, south, east, or west." << endl;
        return;
    }
    if (next) {
        currentRoom = next;
        cout << "You moved " << direction << "." << endl;
    } else {
        cout << "You can't move " << direction << " from here." << endl;
    }
}

// Helper function to normalize direction input
std::string Game::normalizeDirection(const std::string& direction) const {
    std::string d = direction;
    std::transform(d.begin(), d.end(), d.begin(), ::tolower);
    return d;
}

void Game::attackEnemy() {
    
}

void Game::talkToAlly() {
    
}

void Game::setGameOver() {
    gameOver = true;
}

void Game::choice() { // Deals with User Input and choices.
    int choice; 
    
    cout << "Choose an option ('6' For Help): "; // Choice Prompt
    cin >> choice; // Choice value
    if (cin.fail()) { // Checks if the input is valid, if not it clears the error and ignores the rest of the input, then prompts the user to try again.    
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number." << endl;
        return;
    }
    cout << "Choice is: " << choice << endl; // Confirms and displays player choice
    cout << " " << endl; // Adds a blank line for better readability

    switch (choice) { // Switch statement to handle player choice
        case 0: // Quit option. If Choice == 0.
            setGameOver();
            break; 
        case 1: // Describe Current Room. If Choice == 1.
            describeCurrentRoom();
            break;
        case 2: // Show Status. If Choice == 2.
            status();
            break;
        case 3: // Asks for direction input, then moves the User. If Choice == 3. --> Changed to normalizDirection()
        { // Apparently these brackets are needed to declare a variable within the case statement
            string direction;
            cout << "Enter a direction to move (north, south, east, west): "; // Direction Prompt, needs normalization to be added
            cin >> direction;
            move(string(direction));
            break;
        } 
        case 4: // Attacks Enemy. If Choice == 4.
            attackEnemy();
            break;
        case 5: // Initiates Ally Dialogue. If Choice == 5.
            talkToAlly();
            break;
        case 6: // Shows help screen. If Choice == 6.
            showHelp();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }

    cout << " " << endl; // Adds a blank line for better readability

}