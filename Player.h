//Header file for the Player class
#pragma once
#include <string>

class Player{
    public:
        Player(int hp, std::string name = "Player");
        int getHp();
        void takeDamage(int damage);

    private:
        int hp;
        std::string name;
};
