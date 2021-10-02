#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

class Player{
public:
	Player()  {
		transform = new Engine::Object();
	}
	Player(char* _name) {
		transform = new Engine::Object(_name);
	}
	Player(char* _name,const Engine::Point2& _position) {
		transform = new Engine::Object(_name, _position);
	}

	virtual ~Player() {
		delete transform;
	}

	void Draw() const { transform->Draw(); }
	virtual void Update(char input);

	void SetName(char* _name) { transform->SetName(_name); };
private:
	Engine::Object* transform;
};

#endif // PLAYER_H