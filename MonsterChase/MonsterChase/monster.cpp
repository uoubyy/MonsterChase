#include "monster.h"

Monster& Monster::operator=(const Monster& val)
{
	life = val.life;
	delete transform;
	transform = val.transform;
	return *this;
}

Monster& Monster::operator=(Monster&& val) noexcept
{
	life = val.life;
	transform = val.transform;
	val.transform = nullptr;
	return *this;
}

void Monster::Update(char input)
{
	life++;
	transform->Move(Engine::Vector2(RandNum(-1, 1), RandNum(-1, 1)));
}