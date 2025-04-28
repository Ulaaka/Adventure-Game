
#ifndef Location_H
#define Location_H
using namespace std;
#include <string>
#include <map>
#include <vector>

class Monster; 
class Item;

class Location {
private:
    string locationName;
    string locationDescription;
    map<string, Location*> exits;
public:	
    vector<Item*> LocationInventory;
    vector<Monster*> monsters;

    void setName(const string &newName);
    string getName() const;
    void setDescription(const string &newDesc);
    string getDescription() const;
    void addExit(const string &direction, Location* loc);
    string showExits() const;
    void addMonster(Monster* monster);
    void delMonster(Monster* monster);
    Location* getExit(const std::string& direction) const;

    // receiving the dropped item
    void addItem(Item* item);
};

#endif