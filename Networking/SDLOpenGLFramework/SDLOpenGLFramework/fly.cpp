#include "fly.h"

using namespace Game_Lib;
fly::fly(Rectangle r, Window * window, float _angle) :GameObject(position, _angle), flySprite(new Sprite(r, window, _angle)), windowPtr(window) {
	position.x = r.x;
	position.y = r.y;
	radius =1;
}

fly::~fly() {
	OnDestroy();
}

bool fly::OnCreate(std::string filename) {
	flySprite->Load(filename.c_str());
	flySprite->SetAlpha(100);
	return true;
}

void fly::OnDestroy() {
	flySprite->OnDestroy();
	delete flySprite, windowPtr;
	flySprite = nullptr;
	windowPtr = nullptr;
	Debug::Log(EMessageType::INFO, "fly", "Ondestroy", __FILE__, __LINE__, "fly Killed");
}

void fly::Render(Matrix4 projection) {
	flySprite->Render(projection);
}

void  fly::Update(float deltaTime) {
	angle += sinf(deltaTime);
	position.x += 1.0 * cosf(angle);
	position.y += -0.5;
	if (position.y <= -750) { position.y = 0.0f; }
	flySprite->position.x = position.x;
	flySprite->position.y = position.y;
	position.print();
}

void fly::LeftFlip() const {
}

void fly::RightFlip() const {
}

bool fly::IsFlipped() {
	return false;
}

void fly::Clamp() {
}