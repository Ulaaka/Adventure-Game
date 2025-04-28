#include "Treasure.h"
#include <iostream>
using namespace std;



Treasure::Treasure(const std::string &newName, int val):Item(newName){
    setValue(val);
};

void Treasure::setValue(int val){
    treasureValue = val;
};

int Treasure::getValue() const{
    return treasureValue;
};