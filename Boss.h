#ifndef Boss_H
#define Boss_H
#include "Monster.h"
using namespace std;
#include <string>


class Boss : public Monster{
private:
    Item* eldritchRing;
    void setEldritchRing(Item* itemToSet);
public:
    Item* getEldritchRing();
    Boss(int pw, int bounty, const std::string &newSwansong, const string &newName, int sk, int hp, int ar, const string &newDescription, Item* itemToSet);

};

#endif