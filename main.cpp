#include "head.h"

using namespace sf;

int main()
{
	std::vector<VideoMode> modes = VideoMode::getFullscreenModes();

	int height	= modes[0].height;
	int width 	= modes[0].width;

	int center_x = HALF(width);
	int center_y = HALF(height);

	RenderWindow window(VideoMode(width, height), "work space window", sf::Style::None);

	Event main_event;

	Clock clock;

	Time time;

	/*!Background creating!*/
	Texture  background_texture;
	background_texture.loadFromFile("pictures/background.png");
	Sprite * background = CreateBackground(background_texture, window);

	/*!Earth creating!*/
	GameObject earth(center_x, center_y, "pictures/earth.png", DEFAULT_SCALE, DEFAULT_SCALE);

	/*!Asteroids store creating!*/
	std::vector<Asteroid> asteroids;
	storeCreate(asteroids, width, height);

	/*!Variables and resourses for asteroids movements!*/
	char alive_max = START_ALIVE_SIZE;
	char alive_size;
	float list_timer;
	std::vector<char> list;

	for(int i = 0; i < ALIVE_LIST_SIZE; i++)
		list.push_back(i);
	
	while(window.isOpen())
	{
		list_timer = clock.getElapsedTime().asSeconds();
		CheckAsteroidAmount(list_timer, alive_size);

		for(int i(0); i < alive_size; i++)
		{
			CheckAliveNumbers(asteroids, list, alive_max, i);

			AsteroidsEngine(asteroids[list[i]], alive_max, center_x, center_y);
		}

		while(window.pollEvent(main_event))
		{
			switch(main_event.type)
			{
				case sf::Event::KeyPressed:
				{
					if(main_event.key.code == sf::Keyboard::Escape)
						window.close();

					break;
				}

				
			}
		}

		window.clear(sf::Color::White);
		window.draw(*background);

		for(int i = 0; i < alive_size; i++)
			window.draw(asteroids[list[i]].getSprite());

		window.draw(earth.getSprite());		

		window.display();
	}

	return 0;
}
