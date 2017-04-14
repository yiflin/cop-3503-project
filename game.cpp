#include <iostream>
#include "entity.h"
#include <string>

using namespace std;


bool alive;
bool questOnePass = false;
bool questTwoPass = false;
bool questThreePass = false;


bool fight(Player you, Player enemy){
    int rng = rand() % 100 +1;
    if(you.getStrength() >= enemy.getStrength()){
        if(rng>=10){
            return true;
        }else{
            return false;
        }
    }else{
        if(rng>=90){
            return true;
        }else{
            return false;
        }
    }
}

void trollScene(Player &mainPlayer){
    int input;
    int hideCount = 0;
    cout<<"Trolls!\n0. Hide.\n1. Attack the trolls."<<endl;
    cin>>input;
    Player troll(15,1,"Troll");
    while(hideCount != 6 && input == 0){
        hideCount++;
        cout<<"You're crouching behind a rock. The trolls don't seem to have noticed you yet. Enter 1 to attack, 0 to hide."<<endl;
        cin>>input;
        
    }
    if(hideCount == 6){
        cout<<"You sneeze and your location is revealed. The trolls start to close in. You begin to run but you know it's too late. You've been crouching behind a rock all night and your legs are tired. Suddenly the sun starts to rise and you hear a strange groan behind you. You turn, and to your surprise, the trolls have been turned to stone. You keep walking."<<endl;
            questOnePass = true;
    }
    if(input == 1){
        if(fight(mainPlayer, troll)){
            cout<<"You attack the trolls and succeed!"<<endl;
            questOnePass = true;
        }else{
            cout<<"You attack the trolls and die. Game over."<<endl;
            alive = false;
        }
    }

}
void dragonScene (Player &mainPlayer) {
    int input;
    cout << "In the distance you spot a dragon in your path. There are no other routes. You get closer and notice it is fast asleep.\n0. Try and sneak past the dragon.\n1. Fight the dragon.";
    cin >> input;
    Player dragon (45,20,"Dragon");
    
    switch (input) {
        case 0: if (mainPlayer.getStealth() > dragon.getStealth()) {
            cout << "You successfully snuck past the dragon while it slept." << endl;
            questThreePass = true;
        }
        else {
            cout << "You woke the dragon and in a fit of rage it kills you." << endl;
            alive = false;
        }
        case 1: if (mainPlayer.getHasSword()) {
            cout << "You use your sword and effortlessly slay the dragon." << endl;
            questThreePass = true;
        }
        else if (fight (mainPlayer, dragon)) {
            cout << "You fought the dragon and slew it." << endl;
            questThreePass = true;
        }
        else {
            cout << "The dragon slew you." << endl;
            alive = false;
        }
    }
}

void sphinxScene (Player &mainPlayer) {
    string riddleAnswer;
    Sphinx Sphinx;
    cout << "You encounter a Sphinx, it wants to ask you three riddles before you may pass. You have one try for each riddle so answer carefully." << endl;
    for (int i = 1; i < 4; i++) {
        cout << Sphinx.getRiddle(i) << endl;
        cin >> riddleAnswer;
        if(riddleAnswer.compare(Sphinx.getRiddleAns(i))==0) {
            cout << "Correct!" << endl;
            break;
        }
        else{
            cout << "WRONG!!!!!!!!" << endl;
        Sphinx.remainingAttempts--;
        if (Sphinx.remainingAttempts == 0){
            break;
            }
        }
    }
    if (Sphinx.getRemainingAttempts() != 0) {
        cout << "\"Congratulations. You have passed the test of time.\"" << endl;
        if(Sphinx.getRemainingAttempts() == 3){
        cout << "\"Take this sword, as a gift. It might prove useful in the future.\"" << endl;
            mainPlayer.setHasSword();
        }
        questTwoPass = true;
    }else if (Sphinx.getRemainingAttempts() == 0) {
        cout << "You are out of tries. Game Over.";
        alive = false;
    }
}

void tavern(Player &mainPlayer){
    cout << "While exploring you notice a building in the distance, upon closer inspection you see a sign that says: Drunken Horseman Tavern\nYou enter the tavern and notice they are holding bar fights."<<endl;
    int fightCount = 0;
    int choice = 0;
    while(true){
        cout << "What would you like to do?\n0. Leave the tavern.\n1. Fight." << endl;
        cin >> choice;
        if(cin.fail() || choice < 0 || choice > 1){
            cout << "Invalid Input, try again \n";
            cin.clear();
            cin.ignore(10000,'\n');
        }else if(choice == 1 && fightCount < 3){
            cout << "You enter the ring and made quick work of your opponent \n";
            mainPlayer.addStrength();
            ++fightCount;
        }else if(choice == 1 && fightCount >= 3){
            cout << "You have grown too tired for another fight." << endl;
        }
        else{
            return;
        }
    }
}

void cave (Player &mainPlayer){
    cout << "You have discovered a cave.\nYou decide to enter in the hopes that there might be treasure.\n";
    int choice;
    
    string caveEncounters[] = {"some cave bats", "a giant centipede", "a bear", "a giant lizard", "a golem"};
    
    for (int i = 0; i < 6; i++) {
        if (i < 5) {
            cout << "You encounter "<<caveEncounters[i]<<".\n0. Fight them\n1. Run out of the cave." << endl;
            cin >> choice;
            if(cin.fail() || choice < 0 || choice > 1) {
                cout << "Invalid Input, try again \n";
                cin.clear();
                cin.ignore(10000,'\n');
            }
            else if (choice == 0){
                cout << "You kill the beast and absorbed their strength" << endl;
                mainPlayer.addStrength();
            }
            else if (choice == 1) {
                cout << "You managed to escape from the cave beast" << endl;
                mainPlayer.addStealth();
                break;
            }
        }
        else if (i == 5) {
            cout << "You have discovered a treasure chest at the end of the cave.\nEagerly, you open the chest and discover that it is empty.\nYou decide to leave the cave dissapointed.";
        }
    }
}
void forest(Player &mainPlayer){
    
    cout << "While exploring you enter a forest. You spot a little boy wandering around alone."<<endl;
    
    int choice = 0;
    while(true){
        cout << "What would you like to do?\n0. He's probably lost. Offer help.\n1. I don't talk to strangers. Continue walking." << endl;
        cin >> choice;
        if(cin.fail() || choice < 0 || choice > 1){
            cout << "Invalid Input, try again \n";
            cin.clear();
            cin.ignore(10000,'\n');
        }else if(choice == 0 ){
            cout << "The boy thanks you for your kindness and offers you new shoes. \n";
            mainPlayer.addStealth();
            break;
        }
        else{
            return;
        }
    }
}
void junction(int junctionType, Player &mainPlayer){
    
switch(junctionType){
  case 0:
    tavern(mainPlayer);
    break;
  case 1:
    forest(mainPlayer);
    break;
  case 2:
    cave(mainPlayer);
    break;
  default:
    cout<<"You've reached a dead end in the road.";
    break;
  }
    
}


int main() {
    
    alive = true;
    string name;
    int input;
    int race;
    cout << "Enter Name: ";
    cin >> name;
    Player mainPlayer(0,0,name);
    while(true){
        cout << "Select your race:\n";
        cout <<"1. Elf\n2. Orc\n3. Nord\n4. Goblin\n5. Human\n";
        cin >> race;
        if(cin.fail() || race > 5 || race < 1){
            cin.clear();
            cout <<"Selection not found. Try again.\n";
            cin.ignore(10000,'\n');
        }else{
            break;
        }
    }
    
    switch(race){
        case 1:
            mainPlayer.setStrength(1);
            mainPlayer.setStealth(10);
            break;
        case 2:
            mainPlayer.setStrength(10);
            mainPlayer.setStealth(1);
            break;
        case 3:
            mainPlayer.setStrength(8);
            mainPlayer.setStealth(3);
            break;
        case 4:
            mainPlayer.setStrength(3);
            mainPlayer.setStealth(8);
            break;
        case 5:
            mainPlayer.setStrength(5);
            mainPlayer.setStealth(5);
            break;
        default:
            break;
    }
    while(true){
    cout << "Welcome, "<<mainPlayer.getName()<<". You are on a road.\n0. Go forward.\n1. Explore.\n2. View stats."<<endl;
    
    cin >> input;
    
    if(cin.fail() || input < 0 || input > 2){
        cin.clear();
        cout <<"Selection not found. Try again.\n";
        cin.ignore(10000,'\n');
    }else if(input == 0){
        trollScene(mainPlayer);
    }else if(input == 1){
        junction(0, mainPlayer);
    }else if(input == 2){
        mainPlayer.printStats(race);
    }
    
    while(alive){
        
        cout<<"You are back on a road.\n0. Go forward.\n1. Explore.\n2. View stats."<<endl;
        cin>>input;
        
        if(cin.fail() || input < 0 || input > 2){
            cin.clear();
            cout <<"Selection not found. Try again.\n";
            cin.ignore(10000,'\n');
        }else if(input == 0){
            if(questOnePass == false){
                trollScene(mainPlayer);
            }else if(questTwoPass == false){
                sphinxScene(mainPlayer);
            }else if(questThreePass == false){
                dragonScene(mainPlayer);
            }else{
                //castleScene(mainPlayer);
            }
        }else if(input == 1){
            if(questOnePass == false){
                junction(0, mainPlayer);
            }else if(questTwoPass == false){
                junction(1, mainPlayer);
            }else if(questThreePass == false){
                junction(2, mainPlayer);
            }
        }else if(input == 2){
            mainPlayer.printStats(race);
        }
    }
    int decide;
    cout << "Would you like to try again?\n0. Yes\n1. No"<<endl;
    cin >> decide;
    if(cin.fail() || decide > 1 || decide < 0){
        cin.clear();
        cout <<"Selection not found. Try again.\n";
        cin.ignore(10000,'\n');
    }
        if(decide == 0){
            alive = true;
            switch(race){
                case 1:
                    mainPlayer.setStrength(1);
                    mainPlayer.setStealth(10);
                    break;
                case 2:
                    mainPlayer.setStrength(10);
                    mainPlayer.setStealth(1);
                    break;
                case 3:
                    mainPlayer.setStrength(8);
                    mainPlayer.setStealth(3);
                    break;
                case 4:
                    mainPlayer.setStrength(3);
                    mainPlayer.setStealth(8);
                    break;
                case 5:
                    mainPlayer.setStrength(5);
                    mainPlayer.setStealth(5);
                    break;
                default:
                    break;
            }
        }
        else{
            return 0;
        }
    }
    
}
