#include "Weapon.h"
#include <iostream>
using namespace std;

Weapon::Weapon(int ap) {
    setPower(ap); 
}

void Weapon::setPower(int ap){
    attackPower = ap;

};
int Weapon::getPower() const{
    return attackPower;
};