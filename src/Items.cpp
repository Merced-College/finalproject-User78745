/*
Author: Brice Yang
Class: items

Description:
Creation of simple items objects for the inventory system.
Includes the function to get the names and description for the items.
*/

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