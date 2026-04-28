/*
Author: Yen Her
Class: player

Description:
Creates the player class which handles combat (on the user side) and the inventory system of the game.
*/

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

Inventory& Player::getInventory(){
    return inventory;
}

const Inventory& Player::getInventory() const {
    return inventory;
}