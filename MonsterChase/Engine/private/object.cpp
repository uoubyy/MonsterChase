#include "object.h"
namespace Engine {
	Object::Object(const Object& val) :position(val.position) {
		name = new char[strlen(val.name) + 1];
		strcpy_s(name, strlen(val.name) + 1, val.name);
	}

	Object& Object::operator=(const Object& val) {
		position = val.position;

		// alloc new memory before delete old memory
		char* temp = new char[strlen(val.name) + 1];
		strcpy_s(temp, strlen(val.name) + 1, val.name);

		delete[] name;
		name = temp;
		return *this;
	}

	Object::Object(Object&& val) noexcept :position(val.position), name(val.name) {
		val.name = nullptr;
	}

	Object& Object::operator=(Object&& val) noexcept {
		position = val.position;
		name = val.name;

		val.name = nullptr;
		return *this;
	}

	void Object::Draw() const {
		printf("%s is at [ %d,  %d]\n", name, position.X(), position.Y());
	}

	void Object::Move(const Vector2& offset) {
		position += offset;
	}

	void Object::SetName(char* _name)
	{
		// alloc new memory before delete old memory
		char* temp = new char[strlen(_name) + 1];
		strcpy_s(temp, strlen(_name) + 1, _name);

		delete[] name;
		name = temp;
	}
}