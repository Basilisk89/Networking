#include "Boy.h"
using namespace Game_Lib;
Boy::Boy(Rectangle r, Window* window, float _angle) :GameObject(position, _angle), boySprite(new Sprite(r, window, _angle)), windowPtr(window) {
	position = Vec4(r.x, r.y, 0.0f, 0.0f);
	radius = 3;
	acceleration.y = -40.8;
	Debug::Log(EMessageType::INFO, "Boy", "Boy", __FILE__, __LINE__, "Boy pointer Created at screen coord ::");
}
Boy::~Boy() {
	OnDestroy();
	Debug::Log(EMessageType::INFO, "Boy", "~Boy", __FILE__, __LINE__, "Goodbye Boy");
}
bool Boy::OnCreate(std::string filename) {
	boySprite->Load(filename.c_str());

	if (boySprite) {
		return true;
		Debug::Log(EMessageType::INFO, "Boy", "OnCreate", __FILE__, __LINE__, "Loading Boy assets");
	}if (!boySprite) {
		return false;
		Debug::Log(EMessageType::ERROR, "Boy", "OnCreate", __FILE__, __LINE__, "Failed to Load Boy assets");
	}
}
void Boy::OnDestroy() {
	position = 0.0f;

	delete boySprite;

	boySprite = nullptr;

	Debug::Log(EMessageType::INFO, "Boy", "OnDestroy", __FILE__, __LINE__, "Deleting boy...");
}
void Boy::Render(Matrix4 projection) {
	boySprite->SetAlpha(255);
	boySprite->Render(projection);
}
void Boy::Update(float deltaTime) {
	velocity += acceleration * deltaTime;
	position += velocity * deltaTime + 0.5f * acceleration * deltaTime * deltaTime;
	boySprite->position.x = position.x;
	boySprite->position.y = position.y;
	Clamp();
	boySprite->angle = angle;
	position.print();
}
bool Boy::IsFlipped() {
	if (boySprite->isFlipped == false) {
		return false;
	}
	if (boySprite->isFlipped == true) {
		return true;
	}
}
void Boy::LeftFlip() const {
	boySprite->LeftFlip();
}

void Boy::RightFlip() const {
	boySprite->RightFlip();
}

void Game_Lib::Boy::Clamp() {
	if (position.y - radius <= -600.0) {
		velocity.y = 1.0f;
	}
}