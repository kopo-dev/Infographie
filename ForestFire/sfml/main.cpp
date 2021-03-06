#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

class		Forest
{
public:
  Forest(int width, int height)
  {
    MAX_WIDTH = width;
    MAX_HEIGHT = height;
    _forest.create(MAX_WIDTH, MAX_HEIGHT, sf::Color::Black);
    _nforest.create(MAX_WIDTH, MAX_HEIGHT, sf::Color::Black);
    initForest(6.5f, 1.1f);
  }

  void	initForest(int p, int f)
  {
    _p = p;
    _f = f;
    seedForest();
  }

  sf::Image		getImage()
  {
    return (this->simulate(10));
  }

private:
  sf::Image	_forest;
  sf::Image	_nforest;
  int		_treesize = 4;
  int		MAX_WIDTH;
  int		MAX_HEIGHT;
  int		_p;
  int		_f;
  
  int	probRand()
  {
    return (float) rand() / 32343.2222;
  }

  bool	plantTree(int x, int y)
  {
    int a;
    int b;

    for (int yy = _treesize/2; yy < _treesize/2; yy++)
      {
    	for (int xx = -_treesize/2; xx < _treesize/2; xx++)
    	  {
    	    if (!xx && !yy)
    	      continue;
    	    a = x + xx;
    	    b = y + yy;
    	    if (a < MAX_WIDTH && b < MAX_HEIGHT && a > -1 && b > -1)
    	      if (_forest.getPixel(a,b) == sf::Color::Red)
    		return (false);
    	    if (_forest.getPixel(a,b) == sf::Color::Green)
    	      return (false);	  
    	  }
      }
    for (int yy = - _treesize/2; yy < _treesize/2; yy++)
      {
	for (int xx = -_treesize/2; xx <_treesize/2; xx++)
	  {
	    a = x + xx;
	    b = y + yy;
	    if (a < MAX_WIDTH && b < MAX_HEIGHT && a > -1 && b > -1)
	      _nforest.setPixel(a,b,sf::Color::Green);
	  }
      }
    return (true );
  }
  
  void	seedForest()
  {
    for (int y = 0; y < MAX_HEIGHT; y++)
      for (int x = 0; x < MAX_WIDTH; x++)
	{
	  if (probRand() < _p)
	    plantTree(x, y);
	}
  }

  bool getNeighbors(int x, int y)
  {
    int a;
    int b;

    for (int yy = -1; yy < 2; yy++)
      for (int xx = -1; xx < 2; xx++)
	{
	  if (!xx && !yy)
	    continue;
	  a = x + xx;
	  b = y + yy;
	  if (a < MAX_WIDTH && b < MAX_HEIGHT && a > -1 && b > -1)
	    if (_forest.getPixel(a,b) == sf::Color::Red)
	      return (true);
	}
    return (false);
  }

  sf::Image	simulate(int limit)
  {
    for (int y = 0; y < MAX_HEIGHT; y++)
      {
	for (int x = 0; x < MAX_WIDTH; x++)
	  {
	    if (_forest.getPixel(x,y) == sf::Color::Black || _forest.getPixel(x,y) == sf::Color::White)
	      {
		if (probRand() < _p)		
		  plantTree(x,y);
	      }
	    else if (_forest.getPixel(x,y).r > 0)
	      _nforest.setPixel(x, y, sf::Color(((_forest.getPixel(x,y).r) / 1.25f), 0, 0));
	     else if (_forest.getPixel(x,y) == sf::Color::Red)
	       _nforest.setPixel(x,y,sf::Color::Black);
	    else if (_forest.getPixel(x,y) == sf::Color::Green)
	      {
		if (getNeighbors(x,y) || probRand() < _f)
		  _nforest.setPixel(x,y,sf::Color::Red);
	      }
	  }
      }
    for (int y = 0; y < MAX_HEIGHT; y++)
      for (int x = 0; x < MAX_WIDTH; x++)
	{
	  _forest.setPixel(x,y,_nforest.getPixel(x,y));
	}
    return (_forest);
  }
};

int			main(int argc, char **argv)
{
  int			width = 800;
  int			height = 600;
  if (argc == 3)
    {
      width = atoi(argv[1]);
      height = atoi(argv[2]);
    }
  sf::RenderWindow	window(sf::VideoMode(width, height), "SFMLFire", sf::Style::Default);
  sf::Texture		texture;
  sf::Sprite		sprite;
  Forest		forest(width, height);
  
  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	    window.close();
	}
      texture.loadFromImage(forest.getImage());
      sprite.setTexture(texture, true);
      window.draw(sprite);
      window.display();
      window.clear();     
    }
  return 0;

  

}
