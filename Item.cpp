#include "Item.h"
#include <iostream>
using namespace std;


Item::Item(const std::string &newName){
    setName(newName);
}
void Item::setName(const string &newName) {
    name = newName;
}

string Item::getName() const {
    return name;
}