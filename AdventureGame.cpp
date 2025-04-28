#include <iostream>
#include "Character.h"
#include "Boss.h"
#include "Gameworld.h"
#include "Item.h"
#include "Location.h"
#include "Monster.h"
#include "Player.h"
#include "Potion.h"
#include "Treasure.h"
#include "Weapon.h"

using namespace std;
int main() {
    Gameworld gameworld;
    gameworld.loadWorld();
    string input;
    Player* player = new Player("Nyamaa", 6, 50, 0, "", 0, gameworld.getStartingLocation());
    
    while (!gameworld.isGameOver()){
        Location* currentLocation = player->getLocation();
        cout << "Current location: " << currentLocation->getName() << endl;

        cout << currentLocation->getDescription() << endl;
        cout << currentLocation->showExits() << "\n" << endl;

        getline (cin,input);
        for (size_t i = 0; i < input.size(); ++i){
            input[i] = toupper(input[i]);
        }
        if (input == "QUIT"){
            gameworld.setGameOver(true);
        } else if(input == "COLLECT"){
            cout << "player inventory before:\n" << player->getInventory() << endl;
            player->collectItems(currentLocation);
            cout << "player inventory after:\n" << player->getInventory() << endl;

        } else if(input == "INV" || input == "INVENTORY") {
            cout << "player inventory:" << player->getInventory() << "\n" << endl;

        } else if (input == "DRINK"){
            cout << player->drinkPotions() << endl;

        } else if (input == "FIGHT"){
            bool result = player->combat();
            gameworld.setGameOver(result);
        } else {
            bool result = player->moveTo(input);
            if (!result){
                cout << "there is no existing exits in that direction" << endl;
            }
        }
    }
    return 0;
}