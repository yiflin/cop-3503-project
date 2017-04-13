#ifndef GAMESKELETON_H
#define GAMESKELETON_H

#include <string>

class Input
{
public:
  int readInput(int, int);
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
  virtual std::string sceneloop(std::string start) { return "GAME OVER"; };
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

class Dragon: public Scene
{
public:
  std::string sceneloop(std::string);
};

class Castle: public Scene
{
public:
  std::string sceneloop(std::string);
};

class Junction: public Scene
{
public:
  std::string sceneloop(std::string);
};

class Training: public Scene
{
public:
  std::string sceneloop(std::string);
};

//put in a class
int countLines(std::string);

// class Print
// {
// public:
//   std::string textWrap(std::string);
// };

#endif
