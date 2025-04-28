#include "Gameworld.h"
#include "Location.h"
#include "Player.h"
#include "Item.h"
#include "Potion.h"
#include "Monster.h"
#include "Treasure.h"
#include "Weapon.h"
#include "Character.h"
#include "Armour.h"
#include "Boss.h"
#include <iostream>
using namespace std;

bool Gameworld::isGameOver(){
    return gameOver;
};

void Gameworld::setGameOver(bool state){
    gameOver = state;
};

void Gameworld::loadWorld(){

    map<int, Location*> locationMap;
    Location* centralNexus = new Location();
    centralNexus->setName("The Central Nexus");
    centralNexus->setDescription("An ancient crossroads where time and space intertwine.");
    locationMap[19] = centralNexus;

    Location* abercrombyGates = new Location();
    abercrombyGates->setName("The Great Abercromby Gates");
    abercrombyGates->setDescription("Massive stone gates carved with arcane runes.");
    locationMap[1] = abercrombyGates;

    Location*  guildhall  = new Location();
    guildhall->setName("The Guildhall of Scholars");
    guildhall->setDescription("A grand hall where traders, scribes, and mysterious figures gather.");
    locationMap[2] = guildhall;

    Location* thompsonObservatory = new Location();
    thompsonObservatory->setName("The Thompson Observatory");
    thompsonObservatory->setDescription("A domed tower where the stars reveal glimpses of fate.	");
    locationMap[5] = thompsonObservatory;

    Location* scholarAscent = new Location();
    scholarAscent->setName("The Scholar's Ascent");
    scholarAscent->setDescription("A winding staircase that tests the mind as much as the body.");
    locationMap[30] = scholarAscent;

    Location* fenwickRift = new Location();
    fenwickRift->setName("The Fenwick Rift");
    fenwickRift->setDescription("A tear in reality...");
    locationMap[29] = fenwickRift;

    Location* finalGateway = new Location();
    finalGateway->setName("The Final Gateway");
    finalGateway->setDescription("A portal leading to the realm beyond.	");
    locationMap[32] = finalGateway;

    Location* octagonSpire = new Location();
    octagonSpire->setName("The Octagon Spire");
    octagonSpire->setDescription("	A mystical tower containing knowledge beyond mortal comprehension");
    locationMap[31] = octagonSpire;

    Location* victoriaSpire = new Location();
    victoriaSpire->setName("The Victoria Spire");
    victoriaSpire->setDescription("A towering spire with a celestial beacon at its peak.");
    locationMap[20] = victoriaSpire;

    Location* chathamArchives = new Location();
    chathamArchives->setName("The Chatham Archives");
    chathamArchives->setDescription("Endless rows of scrolls, each documenting powerful relics lost to time.");
    locationMap[13] = chathamArchives;

    Location* sidneyVault = new Location();
    sidneyVault->setName("The Sidney Vault");
    sidneyVault->setDescription("A labyrinth of books and stone where scholars vanished centuries ago.");
    locationMap[15] = sidneyVault;

    Location* haroldTemple = new Location();
    haroldTemple->setName("The Forbidden Harold Temple");
    haroldTemple->setDescription("Ancient tomes whisper secrets from their dusty shelves.");
    locationMap[3] = haroldTemple;

    Location* holtEnclave = new Location();
    holtEnclave->setName("The Holt Enclave");
    holtEnclave->setDescription("A ruined amphitheater where echoes of past lectures still resonate.");
    locationMap[6] = holtEnclave;

    Location* mountfordKeep = new Location();
    mountfordKeep->setName("The Mountford Keep");
    mountfordKeep->setDescription("A towering fortress where ancient warriors once trained.");
    locationMap[14] = mountfordKeep;

    Location* rendallArena = new Location();
    rendallArena->setName("The Rendall Arena");
    rendallArena->setDescription("The echoes of battle cries ring through the ruined walls.");
    locationMap[9] = rendallArena;

    Location* reillyBattlegrounds = new Location();
    reillyBattlegrounds->setName("The Reilly Battlegrounds	");
    reillyBattlegrounds->setDescription("A coliseum of stone and steel, where warriors train and champions rise.");
    locationMap[7] = reillyBattlegrounds;

    Location* guildedForge = new Location();
    guildedForge->setName("The Guilded Forge");
    guildedForge->setDescription("A legendary forge where artifacts of immense power were once crafted.");
    locationMap[26] = guildedForge;

    centralNexus -> addExit("WEST",locationMap[1]);
    centralNexus -> addExit("NORTH",locationMap[2]);
    centralNexus -> addExit("EAST",locationMap[3]);

    locationMap[1] -> addExit("EAST",locationMap[19]);

    guildhall -> addExit("SOUTH",locationMap[19]);
    guildhall -> addExit("NORTH",locationMap[5]);
    guildhall -> addExit("EAST",locationMap[13]);
    guildhall -> addExit("WEST",locationMap[15]);

    thompsonObservatory -> addExit("SOUTH",locationMap[2]);
    thompsonObservatory -> addExit("NORTH",locationMap[30]);
    thompsonObservatory -> addExit("EAST",locationMap[31]);

    scholarAscent -> addExit("SOUTH",locationMap[5]);
    scholarAscent -> addExit("WEST",locationMap[29]);

    fenwickRift -> addExit("EAST",locationMap[30]);
    fenwickRift -> addExit("SOUTH",locationMap[32]);

    finalGateway -> addExit("NORTH",locationMap[29]);
    octagonSpire -> addExit("NORTH",locationMap[20]);
    octagonSpire -> addExit("WEST",locationMap[5]);

    victoriaSpire -> addExit("SOUTH",locationMap[31]);

    chathamArchives-> addExit("WEST",locationMap[2]);
    sidneyVault -> addExit("EAST",locationMap[2]);

    haroldTemple -> addExit("WEST",locationMap[19]);
    haroldTemple -> addExit("NORTH",locationMap[6]);
    haroldTemple -> addExit("EAST",locationMap[14]);
    haroldTemple -> addExit("SOUTH",locationMap[9]);

    holtEnclave -> addExit("SOUTH",locationMap[3]);
    holtEnclave -> addExit("EAST",locationMap[26]);

    mountfordKeep -> addExit("SOUTH",locationMap[7]);
    mountfordKeep -> addExit("NORTH",locationMap[26]);
    mountfordKeep -> addExit("WEST",locationMap[3]);

    rendallArena -> addExit("NORTH",locationMap[3]);
    rendallArena -> addExit("WEST",locationMap[7]);

    reillyBattlegrounds -> addExit("NORTH",locationMap[14]);
    reillyBattlegrounds -> addExit("EAST",locationMap[9]);

    guildedForge -> addExit("SOUTH",locationMap[14]);
    guildedForge -> addExit("WEST",locationMap[6]);

// Raider setting
    Potion* redPotion = new Potion("Red Healing Potion", 40);

    Treasure* diamond = new Treasure("Diamond", 100);

    Monster* raider = new Monster(10, 10, "The final blow before falling.", "Raider", 3, 30, 5, "A swift and ruthless attacker.");
    raider -> addItem(redPotion);
    raider -> addItem(diamond);
    locationMap[6] -> addMonster(raider);

// Warrior setting
    Treasure* scroll = new Treasure("Ancient Scroll", 30);

    Treasure* Crown = new Treasure("Gold Crown", 150);

    Monster* warrior = new Monster(12, 9, "Dies honourably in battle.", "Warrior", 4, 40, 8, "A stalwart defender of ancient traditions.");
    warrior -> addItem(scroll);
    warrior -> addItem(Crown);
    locationMap[5] -> addMonster(warrior);

// Brute setting
    Armour* LeatherArmour = new Armour("Leather Armour", 5);

    Monster* brute = new Monster(15, 12, "Falls with a deafening roar.", "Brute", 2, 29, 10, "A formidable opponent with crushing strength.");
    brute -> addItem(LeatherArmour);
    locationMap[29] -> addMonster(brute);

// Troll setting
    Weapon* greatAxe = new Weapon("Great Axe", 15);

    Monster* troll = new Monster(18, 11, "Its final roar shakes the earth.", "Troll", 2, 60, 12, "An ancient creature lurking beneath the shadows.");
    troll -> addItem(greatAxe);
    locationMap[29] -> addMonster(troll);

// Bandit setting
    Treasure* silverKey = new Treasure("Silver Key", 20);

    Weapon* ironSword = new Weapon("Iron Sword", 12);

    Monster* bandit = new Monster(10, 8, "A cunning thief with a taste for blood.", "Bandit", 4, 45, 7, "Slumps quietly after a fatal misstep.");
    bandit -> addItem(silverKey);
    bandit -> addItem(ironSword);
    locationMap[2] -> addMonster(bandit);

// Wraith setting
    Treasure* mysticAmulet = new Treasure("Mystic Amulet", 40);

    Monster* wraith = new Monster(8, 15, "An ethereal entity from beyond the grave.", "Wraith", 2, 35, 4, "Fades into the mist with a haunting whisper.");
    wraith -> addItem(mysticAmulet);
    locationMap[30] -> addMonster(wraith);

// Knight setting
    Armour* plateArmour = new Armour("Plate Armour", 20);

    Monster* knight = new Monster(18, 10, "A noble warrior sworn to protect his honour.", "Knight", 5, 50, 12, "Falls with dignity in his final charge.");
    knight -> addItem(greatAxe);
    knight -> addItem(plateArmour);
    locationMap[31] -> addMonster(knight);

// Sprite setting
    Treasure* goldCoin = new Treasure("Gold Coin", 50);

    Treasure* Gemstone = new Treasure("Gemstone", 75);

    Potion* blueHealingPotion = new Potion("Blue Healing Potion", 50);

    Monster* sprite = new Monster(10, 16, "A mischievous and elusive fae creature.", "Sprite", 1, 25, 3, "Disappears with a final burst of light.");
    sprite -> addItem(goldCoin);
    sprite -> addItem(Gemstone);
    sprite -> addItem(blueHealingPotion);
    locationMap[9] -> addMonster(sprite);

    Item* theRing = new  Item("The great Eldritch Ring.");
    Boss* theBoss = new Boss(40, 100, "Farewell, brother.", "The boss", 12, 60, 15, "The great Mongolian warrior", theRing);
    locationMap[20] -> addMonster(theBoss);

// adding items to the location:
    Treasure* silverCoin = new Treasure("Silver Coin", 25);
    locationMap[1] -> addItem(silverCoin);

    Treasure* sholarMedallion = new Treasure("Scholar's Medallion", 50);
    locationMap[2]->addItem(sholarMedallion);

    Treasure* rubyGemstone = new Treasure("Ruby Gemstone", 70);
    locationMap[15]->addItem(rubyGemstone);

    Treasure* celestialOrb = new Treasure("Celestial Orb", 150);
    locationMap[31]->addItem(celestialOrb);

    Armour* steelShield = new Armour("Steel Shield", 10);
    locationMap[14]->addItem(steelShield);

    Potion* greanHealingPotion = new Potion("Green Healing Potion", 30);
    locationMap[19]->addItem(greanHealingPotion);

    Potion* ultimateHealing = new Potion("Ultimate Healing", 200);
    locationMap[32]->addItem(ultimateHealing);


    Weapon* rustySword = new Weapon("Rusty Sword", 5);
    locationMap[19]->addItem(rustySword);

    Weapon* dagger = new Weapon("Ceremonial Dagger", 8);
    locationMap[3]->addItem(dagger);

    Weapon* sword = new Weapon("Knight's Sword", 12);
    locationMap[14]->addItem(sword);

    Weapon* spear = new Weapon("Gladiator's Spear", 10);
    locationMap[9]->addItem(spear);

    Weapon* axe = new Weapon("Battle Axe", 14);
    locationMap[7]->addItem(axe);

    Weapon* hammer = new Weapon("Master's Hammer", 18);
    locationMap[26]->addItem(hammer);

    Weapon* staff = new Weapon("Enchanted Staff", 15);
    locationMap[31]->addItem(staff);

    firstLocation = locationMap[19];
};
