#pragma once
#include <string>


class Enemies {
    public:
        Enemies(int hp, std::string name = "Enemy", std::string description = "Bad guy.", std::string warningStr = "Danger.");
        int getHp();;
        std::string getDescription();
        void takeDamage(int damage);
        std::string displayWarning();
        std::string getName();

    private:
        int hp;
        std::string name;
        std::string description;
        std::string warningStr;
};