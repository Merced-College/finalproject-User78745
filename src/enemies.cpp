/*
Author: Brice Yang / Yen Her
Class: enemies

Description:
Creates enemies into the game, which the player can combat in order to progress through the dungeon.
Includes functions for getting HP, taking damage, getting name, getting description, and displaying a warning
*/

#include "enemies.h"
#include <iostream>
using namespace std;

Enemies::Enemies(int hp, std::string name, std::string description, std::string warningStr) {
    this->hp = hp;
    this->name = name;
    this->description = description;
    this->warningStr = warningStr; 
}

int Enemies::getHp(){
    return hp;
}

void Enemies::takeDamage(int damage){
    hp -= damage;
    if(hp < 0){
        hp = 0;
    }
}

std::string Enemies::getName(){
    return name;
}

std::string Enemies::getDescription(){
    return description;
}

std::string Enemies::displayWarning(){
    //cout << warningStr << endl;
    return warningStr;
}