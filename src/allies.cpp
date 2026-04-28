/*
Author: Yen Her
Class: allies

Description:
Creation of a simple ally object used for dialogues and hints for the player
Includes function to get dialouge
*/

#include "allies.h"
#include <iostream>

Allies::Allies(std::string name, std::string message){
    this->name = name;
    this-> message = message;
}

std::string Allies::getMessage(){
    return message;
}



