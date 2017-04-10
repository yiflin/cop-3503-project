#include <iostream>
/***************
Updates:
For Entity Class:
3/29 - Janine
-added constructors
-added printStats function

For Player Class:
3/29 - Janine
-made the class
-added constructors
-added get and set functions
    for hasSword
-added printStats function

For Dragon Class:
4/2 - Janine
-made class
-added the constructors
-added getter for isAsleep

For Sphinx Class;
4/2 - Janine
-made class
-added the constructors
-added members:
    riddleAns
    riddleNum
-added getRiddleAns

For Trolls Class:
4/2 - Janine
-made the class
***************/


using namespace std;

/***************
//Entity Class//
***************/
class Entity {
private:
    int strength;
    int stealth;

public:
    Entity();
    Entity(int, int);
    int getStrength();
    int getStealth();
    void add_strength(int);
    void add_stealth(int);
    void printStats();
};

Entity::Entity() {
    this->strength = 0;
    this->stealth = 0;
}

Entity::Entity(int str, int sth) {
    this->strength = str;
    this->stealth = sth;
}

void Entity::add_strength(int x){
  this->strength = x;
}
void Entity::add_stealth(int x){
  this->stealth = x;
}
int Entity::getStrength(){
  return strength;
}
int Entity::getStealth(){
  return stealth;
}

void Entity::printStats() {
    cout << "Strength: " << strength << endl;
    cout << "Stealth: " << stealth << endl;
}

/******************
//Player SubClass//
******************/
class Player : public Entity {
private:
    string name;
    bool hasSword;
public:
    Player();
    Player(int, int, string);
    void setName(string);
    void setHasSword(bool);
    string getName();
    bool getHasSword();
    void printStats();
};

Player::Player() : Entity() {
    this->name = "";
    this->hasSword = false;
}

Player::Player(int str, int stlt, string name) : Entity(str, stlt) {
    this->name = name;
    this->hasSword = false;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setHasSword(bool sword) {
    this->hasSword = sword;
}

string Player::getName() {
    return name;
}

bool Player::getHasSword() {
    return hasSword;
}

void Player::printStats() {
    cout << "Player Name: " << name << endl;
    Entity::printStats();
    cout << "Has Sword? ";
    if(hasSword) {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;

}

/******************
//Dragon Subclass//
******************/
class Dragon : public Entity {
private:
    bool isAsleep;
public:
    Dragon();
    void wake();    //setter of isAsleep
    bool getIsAsleep();
};

Dragon::Dragon() : Entity() {
    this->isAsleep = true;
}

void Dragon::wake() {
    isAsleep = false;
}

bool Dragon::getIsAsleep() {
    return isAsleep;
}

/******************
//Sphinx Subclass//
******************/
class Sphinx : public Entity {
private:
    string riddle;
    string riddleAns;
    int remainingAttempts;
    int riddleNum;
public:
    Sphinx();
    string getRiddle(int);
    int getRemainingAttemps();
    string getRiddleAns();
};

Sphinx::Sphinx() : Entity() {
    riddle = " ";
    riddleAns = " ";
    remainingAttempts = 3;
}

string Sphinx::getRiddle(int randNum) {
    switch(randNum){
    case 0:
        riddle = "some riddle 1";
        riddleNum = 1;
        return riddle;
        break;
    case 1:
        riddle = "some riddle 2";
        riddleNum = 2;
        return riddle;
        break;
    case 2:
        riddle = "some riddle 3";
        riddleNum = 3;
        return riddle;
        break;
    default:
        return riddle;
    }
}

string Sphinx::getRiddleAns() {
    switch(riddleNum) {
    case 1:
        riddleAns = "riddle answer 1";
        return riddleAns;
        break;
    case 2:
        riddleAns = "riddle answer 2";
        return riddleAns;
        break;
    case 3:
        riddleAns = "riddle answer 3";
        return riddleAns;
        break;
    default:
        return riddleAns;
    }
}

int Sphinx::getRemainingAttemps() {
    return remainingAttempts;
}

/******************
//Trolls Subclass//
******************/
class Trolls: public Entity {
private:
    int timeUntilSunrise;
public:
    Trolls();
    int getSunrise();
};

Trolls::Trolls() : Entity(){
    timeUntilSunrise = 12;
}

int Trolls::getSunrise() {
    return timeUntilSunrise;
}

/******************
// main function //
//to test classes//
******************/
int main (){
  int str;
  int stlt;
  string name;
  cout << "Enter Name: ";
  cin >> name;
  cout << "Enter Strength then stealth separated by a space then hit enter: ";
  cin >> str;
  cin >> stlt;
  Player player1(str, stlt, name);
  cout << "\nUsed get functions: " << endl;
  cout << "Name: " << player1.getName() <<endl;
  cout << "Strength: " << player1.getStrength() << " Stealth: " << player1.getStealth() << endl;
  cout << "Has Sword? ";
  if(player1.getHasSword()) {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;

  cout << "\nUsed printStats() function: " << endl;
  player1.printStats();
  return 0;
}
