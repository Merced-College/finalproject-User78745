#include "allies.h"
#include <iostream>

Allies::Allies(std::string name, std::string message){
    this->name = name;
    this-> message = message;
}

std::string Allies::getMessage(){
    return message;
}



