//Header file for the Player class
#pragma once
#include <string>
#include "inventory.h"

class Player{
    public:
        Player(int hp, std::string name = "Player");
        int getHp();
        void takeDamage(int damage);
        Inventory& getInventory();
        const Inventory& getInventory() const;

    private:
        int hp;
        std::string name;
        Inventory inventory;
};
