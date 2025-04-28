#ifndef Player_H
#define Player_H
#include "Character.h"
using namespace std;
#include <string>

class Location;
class Potion;
class Monster;

class Player : public Character{
private:
int playerScore;
Location* playerLocation;

public:
    void setScore(int s);
    int getScore() const;
    void setLocation(Location* loc);
    Location* getLocation() const;
    void collectItems(Location* loc);
    bool moveTo(const std::string &direction);
    string drinkPotions();
    int playerAttackGenerator();
    int monsterAttackGenerator(Monster* mangas);
    bool combat();
};
#endif