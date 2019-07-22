#ifndef GAME_OBJ_H
#define GAME_OBJ_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#define ALIVE 	1
#define DEAD 	0

#define DEFAULT_SCALE 	0.21f

class GameObject
{
	private:
		int 	x_start;
		int 	y_start;
		int 	size_x;
		int 	size_y;
		char 	is_alive;

		sf::Texture texture;
		sf::Sprite 	sprite;

	public:
		GameObject	(int, int, std::string, float, float);
		~GameObject	();

		sf::Sprite & 	getSprite	();
		void 			killObject	();
		void 			MakeAlive	();
		const char 		isAlive 	();
		const int 		getX_start	();
		const int 		getY_start	();
		const int 		getSize_x	();
		const int 		getSize_y	();
};

#endif
