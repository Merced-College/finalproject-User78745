#include "game.h"
#include <iostream>
#include <string>
using namespace std;

Game::Game() : gameOver(false) {
    
}

bool Game::isGameOver() const {
    return gameOver;
}

void Game::start() {
    //buildWorld(); // Sets up rooms, enemies, and allies.
    cout << "Game Object Ran!" << endl;
}

void Game::showHelp() const { // Lists available commands
    cout << 
        "Welcome to Help Screen\n" << 
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
    cout << "It's massive." << endl; 
}

void Game::move(const std::string& direction) {
    
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
    cout << "Choice is: " << choice << endl; // Confirms and displays player choice
    cout << " " << endl; // Adds a blank line for better readability

    switch (choice) { // Switch statement to handle player choice
        case 0: // Quit option. If Choice == 0.
            setGameOver();
            break; 
        case 1: // Show Help. If Choice == 1.
            describeCurrentRoom();
            break;
        case 2: // Show Status. If Choice == 2.
            status();
            break;
        case 3: // Asks for direction input, then moves the User. If Choice == 3.
        { // Apparently these brackets are needed to declare a variable within the case statement
            string direction;
            cout << "Enter a direction to move (north, south, east, west): "; // Direction Prompt, needs normalization to be added
            cin >> direction;
            move(string(direction));
            cout << "You moved " << direction << "." << endl;
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