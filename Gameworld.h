#ifndef Gameworld_H
#define Gameworld_H
using namespace std;
#include <string>
#include "Location.h"


class Gameworld {
private:
    bool gameOver = false;
    Location* firstLocation;
public:
    bool isGameOver();
    void setGameOver(bool gameOver);
    void loadWorld();

    Location* getStartingLocation() const {
        return firstLocation;
    };

};

#endif