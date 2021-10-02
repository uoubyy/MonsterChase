#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "point2.h"

namespace Engine {
	class Object {
	public:
		Object() : position(0, 0), name(nullptr) {}

		Object(char* _name) :position(0, 0) {
			name = new char[strlen(_name) + 1];
			strcpy_s(name, strlen(_name) + 1, _name);
		}
		Object(char* _name, int _x, int _y) :position(_x, _y) {
			name = new char[strlen(_name) + 1];
			strcpy_s(name, strlen(_name) + 1, _name);
		}
		Object(char* _name, const Point2& _position) :position(_position) {
			name = new char[strlen(_name) + 1];
			strcpy_s(name, strlen(_name) + 1, _name);
		}

		virtual ~Object() {
			delete[]name;
		}

		Object(const Object& val);
		Object& operator=(const Object& val);

		Object(Object&& val) noexcept;
		Object& operator=(Object&& val) noexcept;

		virtual void Draw() const;
		virtual void Move(const Vector2& offset);

		void SetName(char* _name);

	private:
		char* name;
		Point2 position;
	};
}
#endif // OBJECT_H