#ifndef TROLLS_H
#define TROLLS_H

#include <string>

class Input
{
public:
  int readInput(int);
};

class Game
{
  std::string start;
public:
  Game(std::string start)
  {
    this->start = start;
  }
  void gameloop();
};

class Scene
{
public:
  virtual std::string sceneloop(std::string);
};


class Trolls: public Scene
{
public:
  std::string sceneloop(std::string);
};

class Sphinx: public Scene
{
public:
  std::string sceneloop(std::string);
};

class Junction: public Scene
{
public:
  std::string sceneloop(std::string);
};

// class Print
// {
// public:
//   std::string textWrap(std::string);
// };

#endif
