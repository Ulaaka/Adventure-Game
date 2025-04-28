#include "Boss.h"
#include "Item.h"
#include <iostream>
using namespace std;

Item* Boss::getEldritchRing(){
    return eldritchRing;
};
Item* Boss::setEldritchRing(Item* itemToSet){
    eldritchRing = itemToSet;
};

