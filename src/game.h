#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <unordered_map>

#include "allies.h"
#include "enemies.h"
#include "Player.h"
#include "rooms.h"
#include "Items.h"

class Game {
public:
    Game(); 
    bool isGameOver() const; // checks if game is running/over 

    void start();
    void showHelp() const;
    void showInventory() const;
    void describeCurrentRoom() const;
    void move(const std::string& direction);
    void checkEnemy(Rooms* next);
    void attackEnemy(Rooms* next);
    void talkToAlly();
    void choice();
    void checkEnd(Rooms* Room);
    void enemyCombat();
    void setGameOver();
    

private:
    void buildWorld(); 
    void fightEnemy(Rooms* next); 
    std::string normalizeDirection(const std::string& direction) const;
    Player player{100, "Hero"};
    std::unordered_map<std::string, std::unique_ptr<Item>> items;

    Rooms* currentRoom;
    bool gameOver;
};

#endif