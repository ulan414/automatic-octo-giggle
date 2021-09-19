#include "Character.h"



Character::Character() {
    name = "Player";
    HP = 0;
    maxHP = 0;
    atk = 0;
    exp = 0;
    level = 0;
    gold = 0;
    itemAtk = 0;        //attack of first item
    itemAtk2 = 0;       //attack of second item
    itemAtk3 = 0;       //attack of third item
}

void Character::initialize(string name) {
    this->name = name;//keyword "this", helps to override variables with same naming;
    HP = 10;
    maxHP = 10;
    atk = 2;
    exp = 0;
    level = 1;
};

void Character::gainExp(int expAdd) {//function for increasing  exp
    exp = exp + expAdd;
    levelUp();
}
void Character::gainGold(int GOLD) {   //function for increasing  gold
    gold=gold+GOLD;
}

void Character::levelUp() {         //function for level up
    //exp->level->add stats;
    while (exp >= level * 10) {
        level++;
        exp = 0;
        maxHP = maxHP + 5;
        HP = maxHP;
        atk = atk + 1;
    }
}

string Character::showStats() {

   int ATK =atk + item.getAtk() + item2.getAtk2() + item3.getAtk3(); //total attack
    string string1 = "Name: " + name + "\n" + "HP: " + to_string(HP) + "/" + to_string(maxHP) +
        "\n" + "Atk: " + to_string(ATK) + "\n" + "exp: " + to_string(exp) + "\n" + "level: " + to_string(level) + "\n"
     + "Gold: "+to_string(gold)+"\n"+"Item: " + item.getName() + "\n" + "Item2: "+item2.getName2()+"\n" +"Item3: " + item3.getName3() + "\n";
    //all characteristics are above
    return string1;
}
                                                //below a lot of setters and getters
string Character::getFirstItem() {
    return  item.getName();                     //for Game.cpp. For checking if items are same
}
string Character::getSecondItem() {
    return item2.getName2();                    //for Game.cpp. For checking if items are same
}
string Character::getThirdItem() {
    return item3.getName3();                   //for Game.cpp. For checking if items are same
}
int Character::getMaxHP() {
    return maxHP;                               //For healing in Game.cpp
}
void Character::setHP(int HP) {
    Character::HP = HP;                        //For healing in Game.cpp
}
int Character::getHP() {
    return HP;                                  //For figtings
}
void Character::setGold(int gold) {             //For increase and decrease gold
    Character::gold = gold;
}
int Character::getGold() {                      //to buy a first aid kit
    return gold;
}

int Character::getAttk() {                      //For fightings
    return atk;
}
int Character::getItemAtk() {                   //to know the attack of the weapon. it didn’t work right through the class item.
    return itemAtk;
}
void Character::setItemAtk(int atk) {
    Character::itemAtk = atk;
}
int Character::getItemAtk2() {
    return itemAtk2;
}
void Character::setItemAtk2(int atk2) {
    Character::itemAtk2 = atk2;
}
int Character::getItemAtk3() {
    return itemAtk3;
}
void Character::setItemAtk3(int atk3) {
    Character::itemAtk3 = atk3;
}
//In your Inventory you can store only best 3 items (they must be automatically equipped).
//more atk = better item
const Item& Character::getItem() const {     //to create 3 items
    return item;                             
}

void Character::setItem(const Item& item) {   
    Character::item = item;
}

const Item& Character::getItem2() const {
    return item2;
}

void Character::setItem2(const Item& item2) {
    Character::item2 = item2;
}
const Item& Character::getItem3() const {
    return item3;
}

void Character::setItem3(const Item& item3) {
    Character::item3 = item3;
}

