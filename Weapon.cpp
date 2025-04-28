#include "Weapon.h"
#include <iostream>
using namespace std;

Weapon::Weapon(const std::string &newName, int ap): Item(newName){
    setPower(ap);
};

void Weapon::setPower(int ap){
    attackPower = ap;

};
int Weapon::getPower() const{
    return attackPower;
};