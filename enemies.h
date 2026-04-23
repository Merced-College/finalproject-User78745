#pragma once
#include <string>

class Enemies {
    public:
        Enemies(int hp, std::string name = "Enemy");
        int getHp();
        void takeDamage(int damage);

    private:
        int hp;
        std::string name;
};