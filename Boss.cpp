#include "Boss.h"
#include "Item.h"
#include <iostream>
using namespace std;


Boss::Boss(int pw, int bounty, const std::string &newSwansong, 
const string &newName, int sk, int hp, int ar, const string &newDescription, Item* itemToSet):Monster(pw, bounty, newSwansong, newName, sk, hp, ar, newDescription){
    setEldritchRing(itemToSet);
};

Item* Boss::getEldritchRing(){
    return eldritchRing;
};
void Boss::setEldritchRing(Item* itemToSet){
    eldritchRing = itemToSet;
};

