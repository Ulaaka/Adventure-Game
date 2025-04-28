#include "Character.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
#include "Item.h"
#include "Armour.h"
#include "Location.h"

int Character::getArmourProtection(){
    int total = 0;
    for (auto idk = inventory.begin(); idk != inventory.end(); ) {
        if (Armour* arm = dynamic_cast<Armour*>(*idk)) {
            int amount = arm->getArmour();
            total += amount;
            idk = inventory.erase(idk);
        } else {
            ++idk;
        }
    }
    return total;
};
void Character::addItem(Item* item){
    if (item){
    inventory.push_back(item);
    }
};

void Character::removeItem(Item* item){
    if (!inventory.empty()){
    inventory.erase(remove(inventory.begin(), inventory.end(), item), inventory.end());
    }
};

void Character::dropItem(Item* item){
    auto it = find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end() && currentLocation) {
        currentLocation->addItem(*it);
        inventory.erase(it);
    }
};

Location* Character::getLocation() const{
    return currentLocation;
};

bool Character::moveTo(Location* newLocation){
    if (newLocation){
        currentLocation = newLocation;
        return true;
    }
    return false;
}

void Character::setSkill(int sk){
    skill = sk;

};
int Character::getSkill() const {
    return skill;

};
void Character::setHitpoints(int hp){
    hitpoints = hp;

};
int Character::getHitpoints() const{
    return hitpoints;

};
void Character::setName(const string &newName){
    name = newName;
};
string Character::getName() const{
    return name;
};
void Character::setArmour(int ar){
    armour = ar;

};
int Character::getArmour() const{
    return armour;
};
string Character::getInventory(){
    // defining the sort
    sort(
    inventory.begin(), 
    inventory.end(),
    [](const Item* a, const Item* b) {
        return a->getName() < b->getName();
    }
    );
    string result;
    for (const auto& item : inventory) {
        result += item->getName()+ "\n";
    }
    if (result.empty()){
        return "Empty inventory";
    } else {
        return result;
    }
};

void Character::setDescription(const string &newDescription){
    description = newDescription;
};

string Character::getDescription() const{
    return description;
};

int Character::rollDice(){
// was too lazy to call dice of 6 sides twice
  int randomNum = rand() % 11;
  return randomNum + 1;
};
void Character::takeHit(int hit){
    int numberSet = this->getHitpoints() - hit;
    this->setHitpoints(numberSet);
};

vector<Item*> Character::accessInventory(){
    return inventory;
};

