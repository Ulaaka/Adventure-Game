#ifndef Weapon_H
#define Weapon_H
#include "Item.h"
using namespace std;
#include <string>


class Weapon : public Item{
private:
int attackPower;
void setPower(int ap);

public:
    int getPower() const;
    Weapon(const std::string &newName, int ap);
};
#endif