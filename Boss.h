#ifndef Boss_H
#define Boss_H
#include "Monster.h"
using namespace std;
#include <string>


class Boss : public Monster{
private:
    Item* eldritchRing;

public:
    Item* getEldritchRing();
    Item* setEldritchRing(Item* itemToSet);

};

#endif