#include "gameskeleton.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

std::string Sphinx::sceneloop(std::string start)
{
  std::string line;
  std::ifstream file;

  file.open(start + ".txt"); //TODO add exception handling
  std::getline(file, line);
  std::cout << '\n' << line << std::endl;
  file.close();

  file.open("SPHINX_RIDDLE.txt"); //TODO add exception handling
  std::getline(file, line);
  std::cout << '\n' << line << std::endl;

  std::string correctAnswer;
  std::getline(file, correctAnswer);
  file.close();

  int attemptCount = 0;
  std::string attempt;

  bool go = true;
  while (go)
  {
    std::cin >> attempt;
    attemptCount++;

    if (attempt.compare(correctAnswer) == 0)
    {
      std::cout << "Correct!" << std::endl;
      file.open("SPHINX_SUCCESS.txt"); //TODO add exception handling
      std::getline(file, line);
      while (line.compare("STOP") != 0)
      {
        std::cout << '\n' << line << std::endl;
        std::getline(file, line);
      }
      go = false;
    }
    else
    {
      if (attemptCount > 2)
      {
        std::cout << "You have failed for the last time." << std::endl;
        return "GAME OVER";
      }
      else
      {
        std::cout << "Wrong answer. " << 3 - attemptCount << " attempts left." << std::endl;
        std::cout << line << std::endl;

        std::cin.clear();
        std::cin.ignore(1000, '\n');
      }
    }

  }

  std::getline(file, line);
  file.close();

  return line;

}
