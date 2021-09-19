#include <iostream>
using namespace std;
#include <string>
#include "Character.h"


class Game {
public:
    Game();
    void mainMenu();
    int getOption() const;
    bool isPlaying() const;
    void playMenu();


private:
    int option; //choice of player
    bool playing; //if player is playing game?
    Character character;


    void showStats();

    void startGame();

    void exploreMenu();

    void getItem();

    void Fight();
};
