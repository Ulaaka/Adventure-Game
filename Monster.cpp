#include "Monster.h"
#include <iostream>
using namespace std;

string Monster::getSwansong() const{
    return swansong;
};
void Monster::setSwansong(const std::string &newSwansong){
    swansong = newSwansong;

};
int Monster::getBounty() const{
    return bountyMonster;
};

void Monster::setBounty(int bounty){
    bountyMonster = bounty;
};

void Monster::setPower(int pw){
    power = pw;
};
int Monster::getPower() const{
    return power;
};