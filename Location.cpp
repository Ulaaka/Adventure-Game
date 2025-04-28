#include "Location.h"
#include <iostream>
#include "Item.h"
#include "Monster.h"
using namespace std;


Location::Location(const string &newName, const string &newDesc){
    setName(newName);
    setDescription(newDesc);
};

void Location::setName(const string &newName){
    locationName = newName;
};
string Location::getName() const{
    return locationName;

};
void Location::setDescription(const string &newDesc){
    locationDescription = newDesc;
};
string Location::getDescription() const{
    return locationDescription;

};
void Location::addExit(const string& direction, Location* loc) {
    exits[direction] = loc;
}
string Location::showExits() const{
    if (exits.empty()) {
        return "No exits";
    }
    string List = "Exits: ";
    for (const auto& exit : exits) {
        List += get<0>(exit) + ", "; 
    }
    return List;

};

void Location::addMonster(Monster* monster){
    if (monster) {
        monsters.push_back(monster);
    }

};
void Location::delMonster(Monster* monster){
    monsters.erase(std::remove(monsters.begin(), monsters.end(), monster), monsters.end());
};
void Location::addItem(Item* item){
    if (!item) {
        return;
    }
    LocationInventory.push_back(item);

}

Location* Location::getExit(const std::string& direction) const {
    auto it = exits.find(direction);
    if (it != exits.end()){
        return it ->second;
    } else {
        return nullptr;
    }
}

