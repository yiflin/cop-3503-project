void castleScene (Player &mainPlayer) {
    int input;
    int rn = rand() % 4;
    string monsterName;
    if (rn == 3) monsterName = "snake";
    else if (rn == 2) monsterName = "rabid princess";
    else if (rn == 1) monsterName = "bear";
    else monsterName = "vicious beast";
    int monsterStrength = (rand() % 15) + 5;
    int monsterStealth = (rand() % 15) + 5;
    Player monster(monsterStrength, monsterStealth, monsterName);
    cout << "Up ahead you see a castle. You feel compelled to enter. Suddenly a " << monsterName << " jumps out at you.\n0. Try and sneak past the " << monsterName << ".\n1. Fight the " << monsterName <<".";
    cin >> input;

    switch (input) {
        case 0: if (mainPlayer.getStealth() > monster.getStealth()) {
            cout << "You successfully snuck past the " << monsterName << ".\n" << endl;
            questFourPass = true;
        }
        else {
            cout << "The " << monsterName << " notices you in your sad attempt to hide and in a fit of rage it kills you.\n" << endl;
            alive = false;
        }
        case 1: if (fight (mainPlayer, monster)) {
            cout << "You fought the " << monsterName << " and slew it.\n" << endl;
            questFourPass = true;
        }
        else {
            cout << "The " << monsterName << " slew you.\n" << endl;
            alive = false;
        }
    }
}
