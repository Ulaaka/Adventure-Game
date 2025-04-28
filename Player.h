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
void setScore(int s);
void setLocation(Location* loc);

public:
    Player(const string &newName, int sk, int hp, int ar, const string &newDescription, int s, Location* loc);
    int getScore() const;
    Location* getLocation() const;
    void collectItems(Location* loc);
    bool moveTo(const std::string &direction);
    string drinkPotions();
    int playerAttackGenerator();
    int monsterAttackGenerator(Monster* mangas);
    bool combat();
};
#endif