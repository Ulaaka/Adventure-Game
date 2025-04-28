#ifndef Treasure_H
#define Treasure_H
#include "Item.h"
using namespace std;
#include <string>


class Treasure : public Item{
private:
int treasureValue;

public:
    void setValue(int val);
    int getValue() const;
};
#endif