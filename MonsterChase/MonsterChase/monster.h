#ifndef MONSTER_H
#define MONSTER_H

#include "object.h"

class Monster {
public:
	Monster() :life(0) { transform = new Engine::Object(); }

	Monster(char* _name) :life(0) {
		transform = new Engine::Object(_name, RandNum(-25, 25), RandNum(-25, 25));
	}

	Monster(char* _name, int _x, int _y) :life(0) {
		transform = new Engine::Object(_name, _x, _y);
	}

	Monster(char* _name, const Engine::Point2& _position) :life(0) {
		transform = new Engine::Object(_name, _position);
	}

	Monster(const Monster& val) :life(val.life){
		transform = new Engine::Object(*val.transform);
	}

	Monster& operator=(const Monster& val);

	Monster(Monster&& val) noexcept :life(val.life), transform(val.transform) {
		val.transform = nullptr;
	}
	Monster& operator=(Monster&& val) noexcept;

	virtual ~Monster() {
		delete transform;
	}

	void Draw() const { transform->Draw(); }
	virtual void Update(char input);

	const int GetLifeTime() const { return life; }
private:
	int life;
	Engine::Object* transform;

	int RandNum(int lower, int upper)
	{
		return (rand() % (upper - lower + 1)) + lower;
	}
};

#endif // MONSTER_H