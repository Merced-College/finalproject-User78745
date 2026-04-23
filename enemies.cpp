#include "enemies.h"

Enemies::Enemies(int hp, std::string name){
    this->hp = hp;
    this->name = name;
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