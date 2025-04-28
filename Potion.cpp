#include "Potion.h"
#include <iostream>
using namespace std;


Potion::Potion(const std::string &newName, int hp) : Item(newName){
    setStrength(hp);
}

void Potion::setStrength(int hp){
    healingStrenght = hp;

};
int Potion::getStrength() const{
    return healingStrenght;
};