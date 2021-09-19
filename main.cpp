//Develop text-based RPG game:
//Classes:
//Character: name, HP, maxHP, Atk, Level, exp
//Enemy:
//Game: mainMenu(), int option (for menu), bool playing
//#include <iostream>
#include "Game.h"



int main() {
    Game game;

    while (game.isPlaying()) {
        game.mainMenu();
    }

    return 0;
}
