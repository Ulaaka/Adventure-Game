#include "Potion.h"
#include <iostream>
using namespace std;

void Potion::setStrength(int hp){
    healingStrenght = hp;

};
int Potion::getStrength() const{
    return healingStrenght;
};