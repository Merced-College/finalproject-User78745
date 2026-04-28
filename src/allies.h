#pragma once
#include <string>

class Allies{
    public:
        Allies(std::string name = "Ally", std::string message = "Hello there! Nice to meet you.");
        std::string getMessage();


    private:
        int hp;
        std::string name;
        std::string message;
};