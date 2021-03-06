#include <iostream>
#include "entity.h"
#include <string>

using namespace std;
int fightCount = 0;
bool alive;
bool questOnePass = false;

string gameOver(){
alive = false;
return "GAME OVER";
}

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

void trollScene(Player mainPlayer){
    int input;
    int hideCount = 0;
    cout<<"Trolls! Enter 1 to attack, 0 to hide."<<endl;
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

void tavern(Player &mainPlayer){
    
    cout << "You enter the tavern and notice they are holding bar fights."<<endl;
    int choice = 0;
    while(true){
        cout << "What would you like to do?\n0: Fight. 1: Leave" << endl;
        cin >> choice;
        if(cin.fail() || choice < 0 || choice > 1){
            cout << "Invalid Input, try again \n";
            cin.clear();
            cin.ignore(10000,'\n');
        }else if(choice == 0 && fightCount < 3){
            cout << "You enter the ring and made quick work of your opponent \n";
            mainPlayer.addStrength();
            ++fightCount;
        }else if(choice == 0 && fightCount >= 3){
            cout << "You have grown too tired for another fight." << endl;
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

    //sphinxSideQuest(mainPlayer);
    break;
  case 2:
   // dragonSideQuest(mainPlayer);
    break;
        
  default:
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
        if(cin.fail() || race > 5 || race <1){
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
    
    cout << "Welcome, "<<mainPlayer.getName()<<". You are on a road.\n0. Go forward.\n1. Explore.\n2. View stats."<<endl;
    
    cin >> input;
    if(cin.fail()){
        cin.clear();
        cout <<"Selection not found. Try again.\n";
        cin.ignore(10000,'\n');
    }else if(input == 0){
        trollScene(mainPlayer);
    }else if(input == 1){
        junction(0, mainPlayer);
    }else if(input == 2){
        mainPlayer.printStats();
    }
    
    while(alive){
        cout<<"You are on a road.\n0. Go forward.\n1. Explore.\n2. View stats."<<endl;
        cin>>input;
        if(cin.fail()){
            cin.clear();
            cout <<"Selection not found. Try again.\n";
            cin.ignore(10000,'\n');
        }else if(input == 0){
            if(questOnePass == false){
                trollScene(mainPlayer);
            }else{
                //sphinxScene();
            }
        }else if(input == 1){
            junction(1, mainPlayer);
        }else if(input == 2){
            mainPlayer.printStats();
        }
    }
    
  return 0;
}
