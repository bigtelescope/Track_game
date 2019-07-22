#include "head.h"

void AsteroidsEngine(Asteroid & asteroid, char & alive_max, int dest_x, int dest_y)
{
	float moment_pos_x = asteroid.getSprite().getPosition().x;
	float moment_pos_y = asteroid.getSprite().getPosition().y;

	if(abs(moment_pos_x + asteroid.getSize_x() - dest_x) < 70 &&
	   abs(moment_pos_y + asteroid.getSize_y() - dest_y) < 70)
	{
		asteroid.killObject();
		return;
	}

	int delta_x = dest_x - asteroid.getX_start();
	int delta_y = dest_y - asteroid.getY_start();

	float radius = sqrt(delta_x * delta_x + delta_y * delta_y);

	asteroid.getSprite().setPosition(moment_pos_x + (delta_x / radius),
								  	 moment_pos_y + (delta_y / radius));
}