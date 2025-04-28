#include "Monster.h"
#include <iostream>
using namespace std;


Monster::Monster(int pw, int bounty, const std::string &newSwansong, const string &newName, int sk, int hp, int ar, const string &newDescription): Character(newName, sk, hp, ar, newDescription) {
    setPower(pw);
    setBounty(bounty); 
    setSwansong(newSwansong);
};

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