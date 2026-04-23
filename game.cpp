#include "game.h"
#include <iostream>
#include <string>
using namespace std;

Game::Game() : gameOver(false) {
    //buildWorld();
}

bool Game::isGameOver() const {
    return gameOver;
}

void Game::start() {
    cout << "Game Object Ran!" << endl;
}

void Game::showHelp() const {
    cout << "Legit, on big G, you don't need help." << endl;
}

void Game::status() const {
    cout << "No clue what you mean by Game::status()." << endl;
}

void Game::describeCurrentRoom() const {
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