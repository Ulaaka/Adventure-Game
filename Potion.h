#ifndef Potion_H
#define Potion_H
#include "Item.h"
using namespace std;
#include <string>


class Potion : public Item{
private:
int healingStrenght;

public:
    void setStrength(int hp);
    int getStrength() const;
};
#endif