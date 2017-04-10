#include "looptest.h"
#include <iostream>
#include <fstream>
#include <sstream>

// use .insert() to put in line breaks
// std::string Print::textWrap(std::string line)
// {
//
// }

int countLines(std::string fileName)
{
  std::ifstream myFile(fileName + ".txt");
  // skips empty lines (I think)
  return std::count( std::istreambuf_iterator<char>(myFile), std::istreambuf_iterator<char>(), '\n');
}

int Input::readInput(int lineCount)
{
  int c;
  while (true)
  {
    std::cin >> c;
    if (std::cin.good())
    {
      if (c < lineCount - 1 && c >= 0)
      {
        return c;
      }
      else
      {
        std::cout << "Error: Menu option out of range. Try again." << std::endl;
      }
    }
    else
    {
      std::cout << "Error: Invalid menu option. Try again." << std::endl;
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }
  }
}

std::string Scene::sceneloop(std::string start)
{
  return "GAME OVER";
}

std::string Trolls::sceneloop(std::string start)
{
  Input input;
  int command;

  std::string currentFrame = start;
  std::string line;

  int lineCount;
  std::ifstream file;

  int hideCount = 0; // counts number of times player chooses to hide

  bool go = true;
  while (go)
  {
    if (hideCount > 6)
    {
      file.open("TROLLS_HIDE_SUCCESS.txt");
      std::getline(file, line);
      std::cout << '\n' << line << std::endl;
      go = false;
    }
    else
    {
      file.open(currentFrame + ".txt"); //TODO add exception handling
      std::getline(file, line);
      std::cout << '\n' << line << std::endl;

      lineCount = countLines(currentFrame);

      if (lineCount < 3 || line.find("GAME OVER") != std::string::npos) // there is no next scene or there is only one next scene
      {
        go = false;
      }
      else
      {
        command = input.readInput(lineCount);
        for (int i = -1; i < command; i++)
        {
          std::getline(file, line);
        }

        currentFrame = line;
        file.close();

        if (currentFrame.compare("TROLLS_HIDE") == 0)
          hideCount++;
      }
    }

  }

  std::getline(file, line);
  file.close();

  return line;

}

std::string Junction::sceneloop(std::string start)
{
  Input input;
  int command;

  std::string currentFrame = start;
  std::string line;

  int lineCount;
  std::ifstream file;

  bool go = true;
  while (go)
  {
      file.open(currentFrame + ".txt"); //TODO add exception handling
      std::getline(file, line);
      std::cout << '\n' << line << std::endl;

      lineCount = countLines(currentFrame);

      if (lineCount < 3 || line.find("GAME OVER") != std::string::npos) // there is no next scene or there is only one next scene
      {
        go = false;
      }
      else
      {
        command = input.readInput(lineCount);
        for (int i = -1; i < command; i++)
        {
          std::getline(file, line);
        }

        currentFrame = line;
        file.close();
      }

  }

  std::getline(file, line);
  currentFrame = line;
  file.close();

  return line;

}

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

void Game::gameloop()
{
  std::string current = start;
  Scene* scene;
  while (current.compare("GAME OVER") != 0)
  {
    if (current.compare("TROLLS_START") == 0)
    {
      scene = new Trolls();
    }
    else if (current.compare("SPHINX_START") == 0)
    {
      scene = new Sphinx();
    }
    else
    {
      scene = new Junction();
    }
    current = scene->sceneloop(current); //TODO redundant current
  }
}

int main() {

  // Scene scene("TROLLS_START");
  // scene.sceneloop(scene.getStart());

  Game game("START");
  game.gameloop();

  return 0;
}
