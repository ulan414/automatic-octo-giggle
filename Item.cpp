#include "Item.h"


Item::Item() {
    atk=0;
    atk2 = 0;
    atk3 = 0;
}
                                                //below 3 same functions to create 3 items
Item* Item::createItem(string name, int atk) {  //function to create first item
        this->name = name;
            this->atk = atk;
        return this;
}
Item* Item::createItem2(string name2, int atk2) {//function to create second item
    this->name2 = name2;
    this->atk2 = atk2;
    return this;
}
Item* Item::createItem3(string name3, int atk3) {//function to create third item
    this->name3 = name3;
    this->atk3 = atk3;
    return this;
}
                       //below a lot of getters and setters. They are just for creating 3 items and get characteristics of them
const string& Item::getName2() const {
    return name2;
}

void Item::setName2(const string& name2) {
    Item::name2 = name2;
}


const string& Item::getName() const {
    return name;
}

void Item::setName(const string& name) {
    Item::name = name;
}
const string& Item::getName3() const {
    return name3;
}

void Item::setName3(const string& name3) {
    Item::name3 = name3;
}



int Item::getAtk() const {
    return atk;
}

void Item::setAtk(int atk) {
    Item::atk =atk;
}
int Item::getAtk2() const {
    return atk2;
}

void Item::setAtk2(int atk2) {
    Item::atk2 = atk2;
}
int Item::getAtk3() const {
    return atk3;
}

void Item::setAtk3(int atk3) {
    Item::atk3 = atk3;
}

int Item::getHp() const {
    return HP;
}

void Item::setHp(int hp) {
    HP = hp;
}
