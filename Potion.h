#ifndef Potion_H
#define Potion_H
#include "Item.h"
using namespace std;
#include <string>


class Potion : public Item{
private:
int healingStrenght;
void setStrength(int hp);

public:
    Potion(const std::string &newName, int hp);
    int getStrength() const;
};
#endif