#include "player.h"

void Player::Update(char input)
{
	int x = 0, y = 0;
	if (input == 'a' || input == 'A')
		x = 1;
	else if (input == 'd' || input == 'D')
		x = -1;
	else if (input == 'w' || input == 'W')
		y = 1;
	else if (input == 's' || input == 'S')
		y = -1;

	transform->Move(Engine::Vector2(x, y));
}