#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "objects.h"

#define HALF(ARG) (ARG) / 2

sf::Sprite * CreateBackground(sf::Texture &, sf::RenderWindow&);

void AsteroidsEngine(Asteroid &, char &, int, int);

#endif
