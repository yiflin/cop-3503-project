#include "gameskeleton.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

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
    else if (current.compare("DRAGON_START") == 0)
    {
      scene = new Dragon();
    }
    else if (current.compare("CASTLE_START") == 0)
    {
      scene = new Castle();
    }
    else if (current.find("TRAINING") != std::string::npos)
    {
      scene = new Training();
    }
    else
    {
      scene = new Junction();
    }
    std::cout << "gameloop current: " << current << std::endl;
    current = scene->sceneloop(current); //TODO redundant current
    std::cout << "gameloop current: " << current << std::endl;

  }
}
