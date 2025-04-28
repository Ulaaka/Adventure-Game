#include "Armour.h"
#include <iostream>
using namespace std;

void Armour::setArmour(int ar){
    armourProtection = ar;
};
int Armour::getArmour() const{
    return armourProtection;
};