
#ifndef Character_H
#define Character_H
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
class Location; 
class Item;

class Character {
protected:
    string name;
    string description;
    int armour;
    int skill;
    int hitpoints;
    Location* currentLocation;
    vector<Item*> inventory; 
    void setName(const string &newName);
    void setSkill(int sk);
    void setHitpoints(int hp);
    void setArmour(int ar);
    void setDescription(const string &newDescription);

public:
    virtual ~Character() = default;

    Character(const string &newName, int sk, int hp, int ar, const string &newDescription);
    int getArmourProtection();
    void addItem(Item* item);
    void removeItem(Item* item);
    void dropItem(Item* item);
    Location* getLocation() const;
    bool moveTo(Location* newLocation);
    int getSkill() const ;
    int getHitpoints() const;
    string getName() const;
    int getArmour() const;
    void takeHit(int hit);
    string getInventory();
    string getDescription() const;
    int rollDice();
    vector<Item*> accessInventory();
};

#endif