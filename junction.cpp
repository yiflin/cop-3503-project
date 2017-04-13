#include "gameskeleton.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

//junction doesn't loop because it's not an action scene
std::string Junction::sceneloop(std::string start)
{
  Input input;
  int command;

  std::string currentFrame = start;
  std::string line = "";

  int lineCount;
  int messageLineCount = 0;
  std::ifstream file;

  // bool go = true;
  // while (go)
  // {
      file.open(currentFrame + ".txt"); //TODO add exception handling
      std::getline(file, line);
      while (line.compare("STOP") != 0)
      {
        std::cout << line << std::endl;
        messageLineCount++;
        std::getline(file, line);
      }

      lineCount = countLines(currentFrame);
      // std::cout << "JUNCTION lineCount: " << lineCount << std::endl;


      // if (lineCount < 4 || line.find("GAME OVER") != std::string::npos) // there is no next scene or there is only one next scene
      // {
      //   std::getline(file, line);
      //   currentFrame = line;
      //   go = false;
      // }
      // else
      // {
        command = input.readInput(lineCount, messageLineCount);
        // if (command == 1) go = false;
        for (int i = -1; i < command; i++)
        {
          std::getline(file, line);
        }

        currentFrame = line;
        file.close();
        messageLineCount = 0;
      // }

  // }

  return currentFrame;

}
