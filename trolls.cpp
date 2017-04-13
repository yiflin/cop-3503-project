#include "gameskeleton.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

std::string Trolls::sceneloop(std::string start)
{
  Input input;
  int command;

  std::string currentFrame = start;
  std::string line;

  int lineCount;
  int messageLineCount = 0;

  std::ifstream file;

  int hideCount = 0; // counts number of times player chooses to hide

  bool go = true;
  while (go)
  {
    if (hideCount > 3)
    {
      file.open("TROLLS_HIDE_SUCCESS.txt");
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
      file.open(currentFrame + ".txt"); //TODO add exception handling
      std::getline(file, line);
      while (line.compare("STOP") != 0)
      {
        std::cout << '\n' << line << std::endl;
        messageLineCount++;
        std::getline(file, line);
      }

      lineCount = countLines(currentFrame);
      // std::cout << "lineCount: " << lineCount << std::endl;

      if (lineCount < 3 || line.find("GAME OVER") != std::string::npos) // there is no next scene or there is only one next scene
      {
        go = false;
      }
      else
      {
        command = input.readInput(lineCount, messageLineCount);
        for (int i = -1; i < command; i++)
        {
          std::getline(file, line);
        }

        currentFrame = line;
        std::cout << currentFrame << std::endl;
        file.close();
        messageLineCount = 0;

        if (currentFrame.compare("TROLLS_HIDE") == 0)
        {
          hideCount++;
          std::cout << hideCount << std::endl;
        }
      }
    }

  }

  std::getline(file, line);

  return line;

}
