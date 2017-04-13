# cop-3503-project
Final project for COP 3503 Spring 2017. Text based adventure game in C++.

***TO COMPILE NEW gameskeleton.cpp :***
Enter into terminal g++ -o gameskeleton.out gameskeleton.cpp helper.cpp dragon.cpp sphinx.cpp trolls.cpp castle.cpp game-class.cpp junction.cpp training.cpp

outline of dragon scene:

DRAGON_START
A dragon!
Enter 1 to fight the dragon,
0 to sneak past.

DRAGON_ATTACK
fight dragon: if has sword OR strength > n, DRAGON_ATTACK_SUCCESS
if no sword AND strength < n, DRAGON_ATTACK_FAIL

DRAGON_SNEAK
sneak: if strength > n, DRAGON_SNEAK_SUCCESS
if strength < n, DRAGON_SNEAK_FAIL


things that need to be done:

[]make something that stores a bunch of possible questions and answers for the sphinx riddle, and randomly selects one and writes it into SPHINX_RIDDLE.txt at start of program--- base done
Still have to write riddle

[]edit Trolls class to have randomly generated time until sunrise

[]edit Player class, edit all of the quests to take in player stats to decide whether player defeats monster or not

[]write dragon quest

[]write castle quest

[]write junctions 0-3 and training scenes

[]don't use + to concat strings
