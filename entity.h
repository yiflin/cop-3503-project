#include <iostream>
#include <string>


using namespace std;

string title[] = {"Elf","Orc","Nord","Goblin","Human"};
/******************
//Player Class//
******************/
class Player {
private:
    string name;
    bool hasSword;
    int strength;
    int stealth;
public:
    
    
    Player();
    Player(int, int, string);
    
    void setName(string);
    void setHasSword();
    void setStrength(int);
    void setStealth(int);
    
   
    
    void printStats(int);
    
    bool attack(Player);
    
    void addStrength();
    void addStealth();
    void addStrength(int);
    void addStealth(int);
    
    string getName();
    bool getHasSword();
    int getStrength();
    int getStealth();
};

Player::Player(){
    this->name = "";
    this->hasSword = false;
}
int Player::getStrength(){
    return strength;
}
int Player::getStealth(){
    return stealth;
}

void Player::setStrength(int str){
    this->strength = str;
}
void Player::setStealth(int sth){
    this->stealth = sth;
}

Player::Player(int str, int sth, string name) {
    this->name = name;
    this->hasSword = false;
    this->strength = str;
    this->stealth = str;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setHasSword() {
    this->hasSword = true;
}

string Player::getName() {
    return name;
}

bool Player::getHasSword() {
    return hasSword;
}


void Player::printStats(int race) {
    cout << name << ", the "<< title[race-1] << endl;
    cout << "Strength: " << strength << endl;
    cout << "Stealth: " << stealth << endl;
}

void Player::addStrength(){
    int i = rand() % 10;
    cout << "You gained " << i << " Strength points" << "\n" <<endl;
    Player::addStrength(i);
}

void Player::addStealth(){
    int i = rand() % 10;
    cout << "You gained " << i << " Strength points" << "\n" <<endl;
    Player::addStealth(i);
}

void Player::addStrength(int i){
    this->strength = strength + i;
}
void Player::addStealth(int i){
    this->stealth = stealth + i;
}
/******************
//Sphinx Subclass//
******************/
class Sphinx {
private:
    string riddle;
    string riddleAns;
    int remainingAttempts;
    int riddleNum;
public:
    Sphinx();
    string getRiddle(int);
    int getRemainingAttempts();
    string getRiddleAns(int);
};

Sphinx::Sphinx(){
    remainingAttempts = 3;
}

string Sphinx::getRiddle(int randNum) {
    switch(randNum){
    case 1:
        riddleNum = 1;
        return "some riddle 1";
        break;
    case 2:
        riddleNum = 2;
        return "some riddle 2";
        break;
    case 3:
        riddleNum = 3;
        return "some riddle 3";
        break;
    default:
        return "some riddle 0";
    }
}

string Sphinx::getRiddleAns(int riddleNum) {
    switch(riddleNum) {
    case 1:
        return "riddle answer 1";
        break;
    case 2:
        return "riddle answer 2";
        break;
    case 3:
        return "riddle answer 3";
        break;
    default:
        return "riddle answer 0";
    }
}

int Sphinx::getRemainingAttempts() {
    return remainingAttempts;
}


/******************
// main function //
//to test classes//
******************/
/*int main (){
  int str;
  int sth;
  string name;
  cout << "Enter Name: ";
  cin >> name;
  cout << "Enter Strength then Stealth separated by a space then hit enter: ";
  cin >> str;
  cin >> sth;
  Player player(str, sth, name);
  cout << "Used get functions: " << endl;
  cout << "Name: " << player.getName() <<endl;
  cout << "Strength: " << player.getStrength() << " Stealth: " << player.getStealth() << endl;
  cout << "Has Sword? ";
  if(player.getHasSword()) {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
  cout << "\nUsed printStats() function: " << endl;
  player.printStats();
  return 0;
}*/
