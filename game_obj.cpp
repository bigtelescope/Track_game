#include "game_obj.h"

GameObject::GameObject(int 		x_null,  int 	y_null, std::string texture_name,
					   float 	scale_x, float 	scale_y):
	x_start		(x_null),
	y_start		(y_null),
	is_alive 	(ALIVE)
{
	texture.loadFromFile(texture_name);

	size_x = (texture.getSize().x / 2) * scale_x;
	size_y = (texture.getSize().y / 2) * scale_y;

	x_start -=  size_x;
	y_start -=  size_y;

	sprite.setTexture	(texture);
	sprite.setPosition	(x_start, y_start);
	sprite.setScale		(scale_x, scale_y);
}

GameObject::~GameObject()
{

}

sf::Sprite & GameObject::getSprite()
{
	return sprite;
}

const char GameObject::isAlive()
{
	return is_alive;
}

void GameObject::MakeAlive()
{
	is_alive = ALIVE;
	sprite.setPosition	(x_start, y_start);
}

void GameObject::killObject()
{
	is_alive = DEAD;
}

const int GameObject::getX_start()
{
	return x_start;
}

const int GameObject::getY_start()
{
	return y_start;
}

const int GameObject::getSize_x()
{
	return size_x;
}

const int GameObject::getSize_y()
{
	return size_y;
}