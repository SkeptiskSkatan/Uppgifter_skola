#include <iostream>
#include <string>
#include <vector>

class Character {
public:
    std::string name;
    int health;
    int attackPower;


    /* constructor declaration and definition inside the class
    Character(std::string& nameC, int& healthC, int& attackPowerC) {

        name = nameC;
        health = healthC;
        attackPower = attackPowerC;
    }
    */


    // declaration inside the class and definition outside
    Character(const std::string& nameC, int healthC, int attackPowerC);


    void attack() {
    
        std::cout << name <<" attacks for " << attackPower << " damage!\n";
    };

    void displayInfo() {
    
        std::cout << name << "\n" << health << "\n" << attackPower << "\n";

    };

    virtual void specialAbility() { std::cout << "no specail ability"; };

};


// declaration inside the class and definition outside
Character::Character(const std::string& nameC, int healthC, int attackPowerC) {

    name = nameC;
    health = healthC;
    attackPower = attackPowerC;

}

class Warrior : public Character {
public:

    Warrior(const std::string& name, int health, int attackPower) : Character(name, health, attackPower) {};


    void specialAbility() override{

        std::cout << "Rage: doubles attack power for this turn!\n";

    };

};



class Mage : public Character {
public:


    Mage(const std::string& name, int health, int attackPower) : Character(name, health, attackPower) {};

    void specialAbility() override {

        std::cout << "Fireball: deals 40 magic damage!\n";

    };

};




class Rogue : public Character {
public:

    Rogue(const std::string& name, int health, int attackPower) : Character(name, health, attackPower) {};



    void specialAbility() override {

        std::cout << "Backstab: guaranteed critical hit!\n";

    };

};



int main()
{


    Warrior w("ww", 10, 100);
    Mage m("mm", 10, 100);
    Rogue r("rr", 10, 100);


    std::vector <Character*> party = { &w, &m, &r };


    for (Character* c : party) {

        c->displayInfo();
        c->attack();
        c->specialAbility();
    };

}
