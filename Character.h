
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
public:
    virtual ~Character() = default;

    int getArmourProtection();
    void addItem(Item* item);
    void removeItem(Item* item);
    void dropItem(Item* item);
    Location* getLocation() const;
    bool moveTo(Location* newLocation);
    void setSkill(int sk);
    int getSkill() const ;
    void setHitpoints(int hp);
    int getHitpoints() const;
    void setName(const string &newName);
    string getName() const;
    void setArmour(int ar);
    int getArmour() const;
    void takeHit(int hit);
    string getInventory();
    void setDescription(const string &newDescription);
    string getDescription() const;
    int rollDice();
    vector<Item*> accessInventory();
};

#endif