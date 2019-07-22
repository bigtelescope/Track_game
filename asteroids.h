#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include "game_obj.h"

#define ASTEROIDS_STORE_SIZE 	64
#define START_ALIVE_SIZE 		3
#define ALIVE_LIST_SIZE 		10
#define ZERO 					0
#define TAB 					100

#define AST_SCALE 				0.3f

#define ONE_AST_TIME 	5
#define TWO_AST_TIME 	10
#define THREE_AST_TIME 	15
#define FOUR_AST_TIME 	20

#define ONE_AST 	1
#define TWO_AST 	2
#define THREE_AST 	3
#define FOUR_AST 	4
#define FIVE_AST 	5

class Asteroid : public GameObject
{
	public :
		Asteroid(int, int, std::string, float, float);
		~Asteroid();
};

void 	storeCreate			(std::vector<Asteroid> &, int, int);
void 	CheckAsteroidAmount	(float, char&);
void 	CheckAliveNumbers	(std::vector<Asteroid> &, std::vector<char> &, char &, int);

#endif