#include "head.h"

sf::Sprite * CreateBackground(sf::Texture & texture, sf::RenderWindow & window)
{
	sf::Sprite * background = new sf::Sprite;

	sf::Vector2u texture_size = texture.getSize(); //Get size of texture.
    sf::Vector2u window_size  = window.getSize();  //Get size of window.

    float scale_x = (float)window_size.x / texture_size.x;	  //Calculate scale.
    float scale_y = (float)window_size.y / texture_size.y;    //Calculate scale.

    background->setTexture(texture);
    background->setScale(scale_x, scale_y);

    return background;
}

