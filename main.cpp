#include <iostream>
#include <string>
#include "Player.h"
#include "rooms.h"
#include "enemies.h"
#include "allies.h"
#include "game.h"
using namespace std;
//1st - Had to change the tasks.json to handle all cpp files in the folder, instead of just main.cpp

int main() {
    cout << "Main is running!" << endl;
    
    
    Game game;
    
    while(!game.isGameOver()) { // Game loop, runs while gameOver is false
        game.start();
        game.setGameOver(); // Sets gameOver to true
    }
     
    cout << "Game Successfully Quited!" << endl;
    return 0; 
}
