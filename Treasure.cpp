#include "Treasure.h"
#include <iostream>
using namespace std;

void Treasure::setValue(int val){
    treasureValue = val;
};

int Treasure::getValue() const{
    return treasureValue;
};