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
string description;

public:
    string getSwansong() const;
    void setSwansong(const std::string &newDescription);
    int getBounty() const;
    void setBounty(int bounty);
    void setPower(int pw);
    int getPower() const;
};
#endif