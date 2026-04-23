#include "allies.h"
#include <iostream>

Allies::Allies(std::string name){
    this->name = name;
}


void Allies::dialouge(std::string message){
    std::cout << name << ": " << message << std::endl;
}

