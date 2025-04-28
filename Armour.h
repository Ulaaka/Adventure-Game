#ifndef Armour_H
#define Armour_H
#include "Item.h"
using namespace std;
#include <string>


class Armour : public Item{
private:
int armourProtection;

public:
    void setArmour(int ar);
    int getArmour() const;
};
#endif