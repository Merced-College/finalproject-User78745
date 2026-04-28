//Implementation file for the rooms class
#include "rooms.h"
#include "enemies.h"
#include "allies.h"

Rooms::Rooms(const std::string& name, const std::string& id, const std::string& desc, Enemies* enemy) {
    roomName = name;
    roomID = id;
    description = desc;
    north = nullptr;
    south = nullptr;
    east = nullptr;
    west = nullptr;
    this->enemy = enemy;
}

std::string Rooms::getRoomName(){
    return roomName;
}

std::string Rooms::getRoomID(){
    return roomID;
}

std::string Rooms::getDescription(){
    return description;
}

//Transveral Handlers
Rooms* Rooms::getNorth(){
    return north;
}
Rooms* Rooms::getSouth(){
    return south;
}
Rooms* Rooms::getEast(){
    return east;
}
Rooms* Rooms::getWest(){
    return west;
}

void Rooms::setNorth(Rooms* room){
    north = room;
}
void Rooms::setSouth(Rooms* room){
    south = room;
}
void Rooms::setEast(Rooms* room){
    east = room;
}
void Rooms::setWest(Rooms* room){
    west = room;
}

// Enemy Handlers
Enemies* Rooms::getEnemy(){
    return enemy;
}

void Rooms::setEnemy(Enemies* enemy){
    this->enemy = enemy;
}

//Ally Handler
Allies* Rooms::getAlly(){
    return ally;
}

void Rooms::setAlly(Allies* ally){
    this->ally = ally;
}
