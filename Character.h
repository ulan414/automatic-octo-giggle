#include <iostream>
using namespace std;
#include <string>


class Item {
public:
    Item();
    Item* createItem(string name, int atk);
    Item* createItem2(string name2, int atk2);
    Item* createItem3(string name3, int atk3);

    const string& getName() const;

    void setName(const string& name);

    const string& getName2() const;

    void setName2(const string& name2);

    const string& getName3() const;

    void setName3(const string& name3);

    int getAtk() const;

    void setAtk(int atk);

    int getAtk2() const;

    void setAtk2(int atk2);

    int getAtk3() const;

    void setAtk3(int atk2);

    int getHp() const;

    void setHp(int hp);

private:
    string name;
    int atk;
    string name2;
    int atk2;
    string name3;
    int atk3;
    int HP;


};

