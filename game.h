#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <unordered_map>

#include "allies.h"
#include "enemies.h"
#include "Player.h"
#include "rooms.h"

class Game {
public:
    Game(); // I belive this is uninitialized and needs parameters
    bool isGameOver() const; // checks if game is running/over // Should this really be a const? Probably not?
    void start();
    void showHelp() const;
    void status() const;
    void describeCurrentRoom() const;
    void move(const std::string& direction);
    void attackEnemy();
    void talkToAlly();
    void setGameOver();

private:
    void buildWorld(); // What in the ligma does this do?
    void fightEnemy(); 
    void enemyAttack();
    std::string normalizeDirection(const std::string& direction) const;

    // I will comment out this confusing "Player" stuff for now
    //Player player;
    //std::unordered_map<std::string, std::shared_ptr<Rooms>> rooms;
    //std::unordered_map<std::string, std::shared_ptr<Enemies>> enemies;
    //std::unordered_map<std::string, std::shared_ptr<Allies>> allies;
    //std::shared_ptr<Rooms> currentRoom;
    bool gameOver;
};

#endif