#include "Armour.h"
#include <iostream>
using namespace std;


Armour::Armour(const std::string &newName, int ar):Item(newName){
    setArmour(ar);
};

void Armour::setArmour(int ar){
    armourProtection = ar;
};
int Armour::getArmour() const{
    return armourProtection;
};