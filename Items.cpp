#include "Items.h"

Item::Item(std::string name, std::string description){
    this->name = name;
    this->description = description;
}

std::string Item::getName(){
    return name;
}

std::string Item::getDescription(){
    return description;
}