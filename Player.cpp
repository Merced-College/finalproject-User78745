#include "Player.h"

Player::Player(int hp, std::string name){
    this->hp = hp;
    this->name = name;
}

int Player::getHp(){
    return hp;
}

void Player::takeDamage(int damage){
    hp -= damage;
    if(hp < 0){
        hp = 0;
    }
}