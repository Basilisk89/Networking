#include "GameObject.h"
using namespace Game_Lib;
Game_Lib::GameObject::GameObject(Vec4 v, float _angle) :position(v), angle(_angle), acceleration(0.0f, 0.0, 0.0, 0.0), velocity(0.0f), radius(0.0f) {
	Debug::Log(EMessageType::INFO, "GameObject", "GameObject", __FILE__, __LINE__, "Hello from GameObject");
}
Game_Lib::GameObject::~GameObject() {
}