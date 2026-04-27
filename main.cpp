#include <iostream>
#include <string>
#include "game.h"
using namespace std;
//1st - Had to change the tasks.json to handle all cpp files in the folder, instead of just main.cpp

int main() {
    Game game;
    
    game.start(); // Starts the game, initializes the world, and displays the initial room description.
    while(!game.isGameOver()) { // Game loop, runs while gameOver is false
        game.choice(); // Prompts for Player Choice then executes action.
    }
     
    cout << "Game Successfully Quitted!" << endl;
    return 0; 
}
