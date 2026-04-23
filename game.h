#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <unordered_map>

#include "allies.h"
#include "enemies.h"
#include "player.h"
#include "rooms.h"

class Game {
public:
    Game();
    void start();
    bool isGameOver() const;
    void showHelp() const;
    void status() const;
    void describeCurrentRoom() const;
    void move(const std::string& direction);
    void attackEnemy();
    void talkToAlly();

private:
    void buildWorld();
    void fightEnemy();
    void enemyAttack();
    std::string normalizeDirection(const std::string& direction) const;

    Player player;
    std::unordered_map<std::string, std::shared_ptr<Rooms>> rooms;
    std::unordered_map<std::string, std::shared_ptr<Enemies>> enemies;
    std::unordered_map<std::string, std::shared_ptr<Allies>> allies;
    std::shared_ptr<Rooms> currentRoom;
    bool gameOver;
};

#endif