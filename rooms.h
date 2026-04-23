//this is the header file for the Rooms class
#pragma once
#ifndef ROOM_H
#define ROOM_H
#include <string>

class Rooms{
    public:
    //AI change - added constants and & to the constructor parameters
        Rooms(const std::string& roomName, const std::string& roomID, const std::string& description);
        std::string getRoomName();
        std::string getRoomID();
        std::string getDescription();
    //All pointers are AI generated
        Rooms* getNorth();
        Rooms* getSouth();
        Rooms* getEast();
        Rooms* getWest();
        void setNorth(Rooms* room);
        void setSouth(Rooms* room);
        void setEast(Rooms* room);
        void setWest(Rooms* room);
    private:
        std::string roomName;
        std::string roomID;
        std::string description;
        Rooms* north;
        Rooms* south;
        Rooms* east;
        Rooms* west;
};

#endif