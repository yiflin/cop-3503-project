#include "gameskeleton.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

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

int Input::readInput(int lineCount, int messageLineCount)
{
  int c;
  while (true)
  {
    std::cin >> c;
    if (std::cin.good())
    {
      if (c < lineCount - messageLineCount && c >= 0)
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
