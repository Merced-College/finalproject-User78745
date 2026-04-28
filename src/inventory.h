#pragma once

#include <vector>
#include "Items.h"

class Inventory{
    public:
        void addItem(Item* item);
        void sortInventory();
        void display() const;

    private:
        std::vector<Item*> items;
};
