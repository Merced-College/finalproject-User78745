//Header file for the Item class
#pragma once
#include <string>

class Item{
    public:
        Item(std::string name = "Item", std::string description = "description");
        std::string getName();
        std::string getDescription();

    private:
        std::string name;
        std::string description;
};
