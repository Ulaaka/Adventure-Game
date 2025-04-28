#ifndef Treasure_H
#define Treasure_H
#include "Item.h"
using namespace std;
#include <string>


class Treasure : public Item{
private:
int treasureValue;
void setValue(int val);
public:
    Treasure(const std::string &newName, int val);
    int getValue() const;
};
#endif