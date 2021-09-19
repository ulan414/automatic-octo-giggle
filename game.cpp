#include "Game.h"
#include "ctime"   //for a randomizer
using namespace std;
Game::Game() {
    option = 0;
    playing = true;
    //some code
}

void Game::mainMenu() {
    cout << "Main menu" << endl << endl;            //I did not changed this
    cout << "1. Start" << endl;
    cout << "0. Quit" << endl << endl;

    cout << "Choose option: ";
    cin >> option;
    switch (option) {
    case 0: playing = false; break;
    case 1: {
        startGame();
        playMenu();
    };
    default: break;

    }
}

void Game::playMenu() {

    while (option != 0) {
        cout << "Play menu" << endl << endl;  //I did not changed this
        cout << "1. Explore" << endl;
        cout << "2. Show stats" << endl;
        cout << "0. Quit" << endl << endl;

        cout << "Choose option: ";
        cin >> option;
        switch (option) {
        case 0:
            mainMenu();
            break;
        case 1:
            exploreMenu();
            break;
        case 2: {
            showStats();
            break;
        }
        default:
            break;

        }
    }
}

void Game::exploreMenu() {

    while (option != 0) {
        cout << "Explore menu" << endl << endl;   //I changed Fight


        cout << "1. Fight" << endl;
        cout << "2. Shop" << endl;
        cout << "0. Go back" << endl << endl;

        cout << "Choose option: ";
        cin >> option;
        switch (option) {
        case 0:
            option = 5;
            playMenu();
            break;
        case 1: {
            Fight();    //calls the function Fight
            break;
        }
        case 2:
            cout << "Do you want to buy a first aid kit for 5 gold?"<<endl;  //instead of rest, I added first aid kit that can 
            cout << "1. YES"<<endl;                                          //be bought for golds
            cout << "2. NO" << endl;
            cin >> option;
            if (option == 1) {
                if (character.getGold() < 5) {          //checks if gold is enought
                    cout << "You dont have enought gold";
                    playMenu();
                }
                else {
                    character.setHP(character.getMaxHP());    //increases hp to maxhp and decreases gold by 5
                    character.setGold(character.getGold() - 5);
                }
            }
            else {
                playMenu();  //if you dont want to buy
            }
        default:
            break;

        }
    }
}
void Game::Fight() {
    srand(time(NULL)); //randomizer. time is seconds for more random
    int a = rand() % 20 + 1;  //random value for "hp" of enemie
    int b = rand() % 20 + 1;  //random value for "attack" of enemie
    while (option != 0) {     //everytime when this function work, new enemies will be hier
        cout << "Enemies" << endl << endl;

        cout << "You see an enemie. You can attack him or search for another enemie\n";
        cout << "Enemie: " << "HP: " << a << "\t" << "Attack: " << b << endl; 
        cout << "1. Attack"<<endl;
        cout << "2. Search for another enemie" << endl;  //launches this function again
        cout << "0. Go back" << endl << endl;

        cout << "Choose option: ";
        cin >> option;
        
        if (option == 0) {
            playMenu();
        }
        else if (option == 1) { 
            cout << "you made the first attack on the enemy. you hit him for "<< character.getAttk() << " damage\n";
            a = a - character.getAttk();
            if (a <= 0) {
                character.gainExp(10);      //exp increasing
                character.gainGold(10);     //gold increasing
                getItem();  //function to get and item
            }
            while (a > 0 || character.getHP()>0)   //loop until enemy has less than 0 hp or you have less than 0 hp
            {
                int i = 0;
                int j = 0;
                while (character.getHP() > 0) { //while loop until you have less than 0 hp
                    j++;
                    if (j == 2) {  //breaks after 1 cycle
                        break;
                    }
                    character.setHP(character.getHP() - b);        //hp decreasing
                    cout << "You was attacked for " << b << " damage\n";//showing damage
                    cout << "Your HP is " << character.getHP()<<endl; //showing your hp
                }
                if (character.getHP() <= 0) {  //you lose if you have less than 0 hp
                    cout << "you managed to dodge and run away at the last moment from the enemy with 1 HP" << endl;
                    character.setHP(1); //decrease your hp to 1 and you go to play menu
                    playMenu();
                }
                while (a > 0) {  //while loop until enemy has less than 0 hp
                    i++;
                    if (i == 2) { //break after 1 cycle
                        break;
                    }
                    a = a - character.getAttk();  //hp decreasing
                    cout << "You attacked for " << character.getAttk() << " damage\n";
                    cout << "enemys HP is " << a << endl;  //showing enemys hp
                }
                if (a <= 0) {
                    character.gainExp(10);      //exp increasing
                    character.gainGold(10);     //gold increasing
                    getItem();  //function to get and item
                }
            }
           
        }
        else if (option == 2) {
            Fight();  //if you search for another enemie, the function will work again
        }
    }
}


void Game::startGame() {
    cout << "Enter your name: ";
    string name;
    cin >> name;
    character.initialize(name);
}

void Game::getItem() {
    Item item;
    srand(time(NULL));  //randomizer
    int a = rand() % 6 + 1;   //random value from 1 to 6. to find random item
    cout << character.getFirstItem() << character.getSecondItem() << character.getThirdItem();
    if (a == 1) {

        if (character.getItemAtk() < 1) {  //checks if this item is better than previous
            if (character.getSecondItem() != "Sword" && character.getThirdItem() != "Sword") {//checks if second or third items already have this item
                character.setItem(*item.createItem("Sword", 1)); //creating new item
                character.setItemAtk(1); //The value did not changed from the above row and I changed in this way
            }
        }    //below is exactly the same code with a different attack value
             //6 items and only 3 unique best items can be in inventory and they increase attack of the character
        else if (character.getItemAtk2() < 1)
        {
            if (character.getFirstItem() != "Sword" && character.getThirdItem() != "Sword") {
                character.setItem2(*item.createItem2("Sword", 1));
                character.setItemAtk2(2);
            }
        }
        else if (character.getItemAtk3() < 1)
        {
            if (character.getFirstItem() != "Sword" && character.getSecondItem() != "Sword") {
                character.setItem3(*item.createItem3("Sword", 1));
                character.setItemAtk3(1);
            }
            
        }
        cout << "you killed a wolf. You found sword and your exp and gold increased by 10\n";
    }
    else if (a == 2) {
        if (character.getSecondItem() != "spear" && character.getThirdItem() != "spear") {
            if (character.getItemAtk() < 2) {
                character.setItem(*item.createItem("spear", 2));
                character.setItemAtk(2);
            }
        }
        else if (character.getItemAtk2() < 2)
        {
            if (character.getFirstItem() != "spear" && character.getThirdItem() != "spear") {
                character.setItem2(*item.createItem2("spear", 2));
                character.setItemAtk2(2);
            }
        }
        else if (character.getItemAtk3() < 2)
        {
            if (character.getFirstItem() != "spear" && character.getSecondItem() != "spear") {
                character.setItem3(*item.createItem3("spear", 2));
                character.setItemAtk3(2);
            }
        }
            cout << "you killed a wolf. You found spear and your exp and gold increased by 10\n";
        
    }
    else if (a == 3) 
    {
            if (character.getItemAtk() < 3) {
                if (character.getFirstItem() != "bow" && character.getSecondItem() != "bow") {
                    character.setItem(*item.createItem("bow", 3));
                    character.setItemAtk(3);
                }
            }
            else if (character.getItemAtk2() < 3)
            {
                if (character.getFirstItem() != "bow" && character.getThirdItem() != "bow") {
                    character.setItem2(*item.createItem2("bow", 3));
                    character.setItemAtk2(3);
                }
            }
            else if (character.getItemAtk3() < 3)
            {
                if (character.getFirstItem() != "bow" && character.getSecondItem() != "bow") {
                    character.setItem3(*item.createItem3("bow", 3));
                    character.setItemAtk3(3);
                }
            }
            cout<< "you killed a wolf. You found bow and your exp and gold increased by 10\n";
        
    }
    else if (a == 4) {
        if (character.getItemAtk() < 4) {
            if (character.getFirstItem() != "sword and shield" && character.getSecondItem() != "sword and shield") {
                character.setItem(*item.createItem("sword and shield", 4));
                character.setItemAtk(4);
            }
        }
        else if (character.getItemAtk2() < 4)
        {
            if (character.getFirstItem() != "sword and shield" && character.getThirdItem() != "sword and shield") {
                character.setItem2(*item.createItem2("sword and shield", 4));
                character.setItemAtk2(4);
            }
        }
        else if (character.getItemAtk3() < 4)
        {
            if (character.getFirstItem() != "sword and shield" && character.getSecondItem() != "sword and shield") {
                character.setItem3(*item.createItem3("sword and shield", 4));
                character.setItemAtk3(4);
            }
        }
            cout << "you killed a wolf. You found sword and shield and your exp and gold increased by 10\n";
        
    }
    else if (a == 5) {
       
        if (character.getItemAtk() < 5) {
            if (character.getThirdItem() != "pistol" && character.getSecondItem() != "pistol") {
                character.setItem(*item.createItem("pistol", 5));
                character.setItemAtk(5);
            }
        }
        else if (character.getItemAtk2() < 5)
        {
            if (character.getFirstItem() != "pistol" && character.getThirdItem() != "pistol") {
                character.setItem2(*item.createItem2("pistol", 5));
                character.setItemAtk2(5);
            }
        }
        else if (character.getItemAtk3() < 5)
        {
            if (character.getFirstItem() != "pistol" && character.getSecondItem() != "pistol") {
                character.setItem3(*item.createItem3("pistol", 5));
                character.setItemAtk3(5);
            }
        }
            cout << "you killed a wolf. You found pistol and your exp and gold  increased by 10\n";
        
    }
    else if (a == 6) {
            if (character.getItemAtk() < 6) {
                if (character.getThirdItem() != "gun" && character.getSecondItem() != "gun") {
                    character.setItem(*item.createItem("gun", 6));
                    character.setItemAtk(6);
                }
            }
            else if (character.getItemAtk2() < 6)
            {
                if (character.getFirstItem() != "gun" && character.getThirdItem() != "gun") {
                    character.setItem2(*item.createItem2("gun", 6));
                    character.setItemAtk2(6);
                }
            }
            else if (character.getItemAtk3() < 6)
            {
                if (character.getFirstItem() != "gun" && character.getSecondItem() != "gun") {
                    character.setItem3(*item.createItem3("gun", 6));
                    character.setItemAtk3(6);
                }
            }
            cout << "you killed a wolf. You found gun and your exp and gold increased by 10\n";
        
    }
    cout << "after the fight your HP is: " << character.getHP() << endl << "Do you want to fight with next enemie?"<<endl;
        cout<<"1. YES"<<endl;
        cout<<"2. NO"<<endl;
        cin >> option;
        if (option == 1) {
            Fight();
        }
        else
        {
            playMenu();
        }
}

void Game::showStats() {
    cout << character.showStats();  //function to see characteristics
}

int Game::getOption() const {
    return option;
}

bool Game::isPlaying() const {
    return playing;
}
