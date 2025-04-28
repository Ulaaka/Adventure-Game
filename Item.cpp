#include "Item.h"
#include <iostream>
using namespace std;

void Item::setName(const string &newName) {
    name = newName;
}

string Item::getName() const {
    return name;
}