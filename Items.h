//Header file for the Item class
#pragma once
#include <string>

class Item{
    public:
        Item(std::string name = "Item", std::string description = "description");
        
    private:
        std::string name;
        std::string description;
};
