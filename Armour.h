#ifndef Armour_H
#define Armour_H
#include "Item.h"
using namespace std;
#include <string>


class Armour : public Item{
private:
int armourProtection;
void setArmour(int ar);
public:
    Armour(const std::string &newName, int ar);
    int getArmour() const;
};
#endif