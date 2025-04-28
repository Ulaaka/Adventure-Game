#include "Player.h"
#include "Potion.h"
#include "Location.h"
#include "Monster.h"
#include "Weapon.h"
#include "Gameworld.h"
#include "Boss.h"
#include <iostream>
using namespace std;

void Player::setScore(int s){
    playerScore = s;
};
int Player::getScore() const{
    return playerScore;
};
void Player::setLocation(Location* loc){
    if (loc){
        playerLocation = loc;
    }
};
Location* Player::getLocation() const{
    return playerLocation;
};

void Player::collectItems(Location* loc){
    if (!loc) return;
    auto items = loc->LocationInventory;
    for (Item* item : items) {
        this->addItem(item);
    };
    loc->LocationInventory.clear();
};

bool Player::moveTo(const std::string &direction){
    Location* existingExit = playerLocation->getExit(direction);
    if (existingExit){
        playerLocation = existingExit;
        return true;
    } else {
        return false;
    }
};

string Player::drinkPotions(){
    string result;
    for (auto idk = inventory.begin(); idk != inventory.end(); ) {
        if (Potion* potion = dynamic_cast<Potion*>(*idk)) {
            int amount = potion->getStrength();
            setHitpoints(getHitpoints() + amount);
            result += "HP boosted by " + to_string(amount);
            idk = inventory.erase(idk);
        } else {
            ++idk;
        }
    }
    if (result.empty()){
        return "no potion found";
    } else {
        return result;
    }
};

int Player::playerAttackGenerator(){
    int skillPoint = this->getSkill();
// need to choose the weapon with the highest power?
    int power = 0; 
    for (auto& item : inventory) {
        if (Weapon* weapon = dynamic_cast<Weapon*>(item)) {
            power = max(power, weapon->getPower());
        }
    }
    int totalDamage = skillPoint + power;
    return totalDamage;
};

int Player::monsterAttackGenerator(Monster* mangas){
    int totalDamage = mangas -> getSkill();
    return totalDamage;
};

bool Player::combat(){
    const auto& monstersLocation = playerLocation->monsters;
    if (monstersLocation.empty()) {
        cout << "No monsters found!" << endl;
        return false;
    } else{
        Monster* MaxMonster = monstersLocation[0];
        if (monstersLocation.size() >= 2){
            for (size_t i = 1; i < monstersLocation.size(); ++i) {
                if (monstersLocation[i]->getHitpoints() > MaxMonster->getHitpoints()) {
                    MaxMonster = monstersLocation[i];
                }
            }
        }
        cout << "The name of the monster to fight: "<< MaxMonster->getName() << "\n" << endl;
        while ( this->getHitpoints() > 0 && MaxMonster->getHitpoints() > 0) {
            cout << "Your HP: ";
            cout << this->getHitpoints() << endl;
            cout << "Monster's HP: ";
            cout << MaxMonster->getHitpoints() << endl;

            int playerAttack = playerAttackGenerator() + this->rollDice();
            cout << "Your total attack: " << playerAttack << endl;
            int monsterAttack = monsterAttackGenerator(MaxMonster) + MaxMonster->rollDice();
            cout << "Monster's total attack: " << monsterAttack << endl;

            if (playerAttack > monsterAttack) {
                cout << "Your attack won!" << endl;
                int endDamage = 1;
                if (playerAttack != 6){
                    endDamage = (playerAttack - MaxMonster->getArmour());
                }
                cout << "Your damage on Monster is " << endDamage << endl;
                MaxMonster -> takeHit(endDamage);         
            } else if (playerAttack < monsterAttack){
                cout << "Monsters attack won!" << endl;
                int endDamage = (MaxMonster->getPower() - (this -> getArmour() + this -> getArmourProtection()));
                cout << "Monster's damage on you is " << endDamage << endl;
                this -> takeHit(endDamage);         
            } else {
                cout << "The attacks cancel out " << endl;
                continue;
            }
        cout <<"Your remaining HP" << this->getHitpoints() << endl;
        cout <<"Monster's remaining HP" << MaxMonster->getHitpoints() << endl;
        }
        if (this -> getHitpoints() <= 0){
            cout << "Game Over" << endl;
            return true;
        } else {      
            cout << MaxMonster->getSwansong() << "\n" << endl;
            auto inventoryMonster = MaxMonster->accessInventory();

            for (Item* item : inventoryMonster) {
                MaxMonster->dropItem(item);
            };

            playerScore+=MaxMonster->getBounty();
            cout << "Your score: " << playerScore << "\n" << endl;

            playerLocation->delMonster(MaxMonster); 

            if (Boss* defeatedMonster = dynamic_cast<Boss*>(MaxMonster)){
                cout << "You have defeated the final boss, congrats.\n" << endl;
                return true;
            }
            return false;
        }
    }
};