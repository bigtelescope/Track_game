#include "asteroids.h"

Asteroid::Asteroid(int x_null,  int y_null, std::string texture_name, float scale_x, float scale_y):
	GameObject(x_null, y_null, texture_name, scale_x, scale_y)
{}

Asteroid::~Asteroid()
{

}

void storeCreate(std::vector<Asteroid> & vector, int width, int height)
{
	for(int i = 0; i < ASTEROIDS_STORE_SIZE / 4; i++)
	{
		Asteroid * one = new Asteroid(rand()%width,	-TAB,		  "pictures/meteor.png", AST_SCALE, AST_SCALE);
		Asteroid * two = new Asteroid(rand()%width, height + TAB, "pictures/meteor.png", AST_SCALE, AST_SCALE);

		Asteroid * three = new Asteroid(-TAB,		 rand()%height, "pictures/meteor.png", AST_SCALE, AST_SCALE);
		Asteroid * four  = new Asteroid(width + TAB, rand()%height, "pictures/meteor.png", AST_SCALE, AST_SCALE);

		vector.push_back(*one);
		vector.push_back(*two);
		vector.push_back(*three);
		vector.push_back(*four);
	}
}

void CheckAsteroidAmount(float time, char & alive_size)
{
	if(time < ONE_AST_TIME)
	{
		alive_size = ONE_AST;
	}
	else if(time < TWO_AST_TIME)
	{
		alive_size = TWO_AST;
	}
	else if(time < THREE_AST_TIME)
	{
		alive_size = THREE_AST;
	}
	else if(time < FOUR_AST_TIME)
	{
		alive_size = FOUR_AST;
	}
	else
		alive_size = FIVE_AST;
}

void CheckAliveNumbers(std::vector<Asteroid> & asteroids, std::vector<char> & list, char & alive_max, int counter)
{
	if(!(asteroids[list[counter]].isAlive()))
	{
		asteroids[list[counter]].MakeAlive();

		alive_max++;
		list[counter] = alive_max;

		if(alive_max == ASTEROIDS_STORE_SIZE - 1)
			alive_max = START_ALIVE_SIZE;
	}
}
