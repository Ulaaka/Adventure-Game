#ifndef Monster_H
#define Monster_H
#include <string>
#include "Character.h"

using namespace std;
class Monster : public Character{
private:
int bountyMonster;
string swansong;
int power;

void setPower(int pw);
void setBounty(int bounty);
void setSwansong(const std::string &newSwansong);
public:
    Monster(int pw, int bounty, const std::string &newSwansong, const string &newName, int sk, int hp, int ar, const string &newDescription);
    int getBounty() const;
    string getSwansong() const;
    int getPower() const;
};
#endif