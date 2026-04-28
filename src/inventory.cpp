#include <iostream>
#include "inventory.h"
#include <utility>

void Inventory::addItem(Item* item){
    if (item == nullptr){
        return;
    }
    else{
        items.push_back(item); //The push equivalent for vectors
        sortInventory(); //Just to make it automatic for the player
    }
}

//Code had to revised by A.I to use pointers
void Inventory::sortInventory(){
    int n = items.size();

    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i+1; j<n; j++){
            if(items[j]->getName() < items[min]->getName()){
                min = j;
            }
        }
        Item* temp = items[i];
        items[i] = items[min];
        items[min] = temp;
    }
}

void Inventory::display() const {
    if(items.empty()){
        std::cout << "Inventory is empty. \n";
        return;
    }
    std::cout << "Inventory:\n";
    for(int i = 0; i < items.size(); i++){
        std::cout << i + 1 << ". " << items[i]->getName() << "\n";
    }
}