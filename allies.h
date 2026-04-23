#pragma once
#include <string>

class Allies{
    public:
        Allies(std::string name = "Ally");
        void dialouge(std::string message);

    private:
        int hp;
        std::string name;
};