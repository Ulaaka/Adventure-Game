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
    Potion* redPotion = new Potion();
    redPotion -> setStrength(40);
    redPotion -> setName("Red Healing Potion");

    Treasure* diamond = new Treasure();
    diamond -> setValue(100);
    diamond -> setName("Diamond");

    Monster* raider = new Monster();
    raider -> setName("Raider");
    raider -> setSkill(3);
    raider -> setHitpoints(30);
    raider -> setPower(10);
    raider -> setArmour(5);
    raider -> setSwansong("The final blow before falling.");
    raider -> setDescription("A swift and ruthless attacker.");
    raider->setBounty(10);
    raider -> addItem(redPotion);
    raider -> addItem(diamond);
    locationMap[6] -> addMonster(raider);

// Warrior setting
    Treasure* scroll = new Treasure();
    scroll -> setValue(30);
    scroll -> setName("Ancient Scroll");

    Treasure* Crown = new Treasure();
    Crown -> setValue(150);
    Crown -> setName("Gold Crown");

    Monster* warrior = new Monster();
    warrior -> setName("Warrior");
    warrior -> setSkill(4);
    warrior -> setHitpoints(40);
    warrior -> setPower(12);
    warrior -> setArmour(8);
    warrior -> setSwansong("Dies honourably in battle.");
    warrior -> setDescription("A stalwart defender of ancient traditions.");
    warrior->setBounty(9);
    warrior -> addItem(scroll);
    warrior -> addItem(Crown);
    locationMap[5] -> addMonster(warrior);

// Brute setting
    Armour* LeatherArmour = new Armour();
    LeatherArmour->setArmour(5);
    LeatherArmour->setName("Leather Armour");

    Monster* brute = new Monster();
    brute -> setName("Brute");
    brute -> setSkill(2);
    brute -> setHitpoints(29);
    brute -> setPower(15);
    brute -> setArmour(10);
    brute -> setSwansong("Falls with a deafening roar.");
    brute -> setDescription("A formidable opponent with crushing strength.");
    brute->setBounty(12);
    brute -> addItem(LeatherArmour);
    locationMap[29] -> addMonster(brute);

// Troll setting
    Weapon* greatAxe = new Weapon();
    greatAxe->setPower(15);
    greatAxe->setName("Great Axe");

    Monster* troll = new Monster();
    troll -> setName("Troll");
    troll -> setSkill(2);
    troll -> setHitpoints(60);
    troll -> setPower(18);
    troll -> setArmour(12);
    troll -> setSwansong("Its final roar shakes the earth.");
    troll -> setDescription("An ancient creature lurking beneath the shadows.");
    troll->setBounty(11);
    troll -> addItem(greatAxe);
    locationMap[29] -> addMonster(troll);

// Bandit setting
    Treasure* silverKey = new Treasure();
    silverKey->setValue(20);
    silverKey->setName("Silver Key");

    Weapon* ironSword = new Weapon();
    ironSword->setPower(12);
    ironSword->setName("Iron Sword");

    Monster* bandit = new Monster();
    bandit -> setName("Bandit");
    bandit -> setSkill(4);
    bandit -> setHitpoints(45);
    bandit -> setPower(10);
    bandit -> setArmour(7);
    bandit -> setSwansong("A cunning thief with a taste for blood.");
    bandit -> setDescription("Slumps quietly after a fatal misstep.");
    bandit->setBounty(8);
    bandit -> addItem(silverKey);
    bandit -> addItem(ironSword);
    locationMap[2] -> addMonster(bandit);

// Wraith setting
    Treasure* mysticAmulet = new Treasure();
    mysticAmulet->setValue(40);
    mysticAmulet->setName("Mystic Amulet");

    Monster* wraith = new Monster();
    wraith -> setName("Wraith");
    wraith -> setSkill(2);
    wraith -> setHitpoints(35);
    wraith -> setPower(8);
    wraith -> setArmour(4);
    wraith -> setSwansong("An ethereal entity from beyond the grave.");
    wraith -> setDescription("Fades into the mist with a haunting whisper.");
    wraith->setBounty(15);
    wraith -> addItem(mysticAmulet);
    locationMap[30] -> addMonster(wraith);

// Knight setting
    Armour* plateArmour = new Armour();
    plateArmour->setArmour(20);
    plateArmour->setName("Plate Armour");

    Monster* knight = new Monster();
    knight -> setName("Knight");
    knight -> setSkill(5);
    knight -> setHitpoints(50);
    knight -> setPower(18);
    knight -> setArmour(12);
    knight -> setSwansong("A noble warrior sworn to protect his honour.");
    knight -> setDescription("Falls with dignity in his final charge.");
    knight->setBounty(10);
    knight -> addItem(greatAxe);
    knight -> addItem(plateArmour);
    locationMap[31] -> addMonster(knight);

// Sprite setting
    Treasure* goldCoin = new Treasure();
    goldCoin->setValue(50);
    goldCoin->setName("Gold Coin");

    Treasure* Gemstone = new Treasure();
    Gemstone->setValue(75);
    Gemstone->setName("Gemstone");

    Potion* blueHealingPotion = new Potion();
    blueHealingPotion->setStrength(50);
    blueHealingPotion->setName("Blue Healing Potion");

    Monster* sprite = new Monster();
    sprite -> setName("Sprite");
    sprite -> setSkill(1);
    sprite -> setHitpoints(25);
    sprite -> setPower(10);
    sprite -> setArmour(3);
    sprite -> setSwansong("A mischievous and elusive fae creature.");
    sprite -> setDescription("Disappears with a final burst of light.");
    sprite->setBounty(16);
    sprite -> addItem(goldCoin);
    sprite -> addItem(Gemstone);
    sprite -> addItem(blueHealingPotion);
    locationMap[9] -> addMonster(sprite);

    Item* theRing = new  Item();
    theRing->setName("The great Eldritch Ring.");

    Boss* theBoss = new Boss();
    theBoss -> setName("The final boss");
    theBoss -> setSkill(12);
    theBoss -> setHitpoints(60);
    theBoss -> setPower(40);
    theBoss -> setArmour(15);
    theBoss -> setSwansong("Farewell, brother.");
    theBoss -> setDescription("The great Mongolian warrior");
    theBoss->setBounty(100);
    theBoss -> addItem(theRing);
    locationMap[20] -> addMonster(theBoss);

// adding items to the location:
    Treasure* silverCoin = new Treasure();
    silverCoin -> setValue(25);
    silverCoin -> setName("Silver Coin");
    locationMap[1] -> addItem(silverCoin);

    Treasure* sholarMedallion = new Treasure();
    sholarMedallion->setValue(50);
    sholarMedallion->setName("Scholar's Medallion");
    locationMap[2]->addItem(sholarMedallion);

    Treasure* rubyGemstone = new Treasure();
    rubyGemstone->setValue(70);
    rubyGemstone->setName("Ruby Gemstone");
    locationMap[15]->addItem(rubyGemstone);

    Treasure* celestialOrb = new Treasure();
    celestialOrb->setValue(150);
    celestialOrb->setName("Celestial Orb");
    locationMap[31]->addItem(celestialOrb);

    Armour* steelShield = new Armour();
    steelShield->setArmour(10);
    steelShield->setName("Steel Shield");
    locationMap[14]->addItem(steelShield);

    Potion* greanHealingPotion = new Potion();
    greanHealingPotion->setStrength(30);
    greanHealingPotion->setName("Green Healing Potion");
    locationMap[19]->addItem(greanHealingPotion);

    Potion* ultimateHealing = new Potion();
    ultimateHealing->setStrength(200);
    ultimateHealing->setName("Ultimate Healing");
    locationMap[32]->addItem(ultimateHealing);

    Weapon* rustySword = new Weapon();
    rustySword->setPower(5);
    rustySword->setName("Rusty Sword");
    locationMap[19]->addItem(rustySword);

    Weapon* dagger = new Weapon();
    dagger->setPower(8);
    dagger->setName("Ceremonial Dagger");
    locationMap[3]->addItem(dagger);

    Weapon* sword = new Weapon();
    sword->setPower(12);
    sword->setName("Knight's Sword");
    locationMap[14]->addItem(sword);

    Weapon* spear = new Weapon();
    spear->setPower(10);
    spear->setName("Gladiator's Spear");
    locationMap[9]->addItem(spear);

    Weapon* axe = new Weapon();
    axe->setPower(14);
    axe->setName("Battle Axe");
    locationMap[7]->addItem(axe);

    Weapon* hammer = new Weapon();
    hammer->setPower(18);
    hammer->setName("Master's Hammer");
    locationMap[26]->addItem(hammer);

    Weapon* staff = new Weapon();
    staff->setPower(15);
    staff->setName("Enchanted Staff");
    locationMap[31]->addItem(staff);

    firstLocation = locationMap[19];
};
