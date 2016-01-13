#include "Cat.h"

using namespace Game_Lib;

Cat::Cat(Rectangle r, Window* window, float _angle) :GameObject(position, _angle), catSprite(new Sprite(r, window, _angle)), windowPtr(window) {
	position = Vec4(r.x, r.y, 0.0f, 0.0f);
	radius = r.h / 5;
}
Cat::~Cat() {
	OnDestroy();
}

bool Cat::OnCreate(std::string filename) {
	catSprite->Load(filename.c_str());
	if (catSprite) { return true; }
	if (!catSprite) { return false; }
}

void Cat::OnDestroy() {
	position = 0.0f;
	delete catSprite;
	catSprite = nullptr;
	Debug::Log(EMessageType::INFO, "Boy", "OnDestroy", __FILE__, __LINE__, "Deleting cat...");
}

void Cat::Render(Matrix4 projection) {
	catSprite->SetAlpha(255);
	catSprite->Render(projection);
}
void Cat::Update(float deltaTime) {
	accuTime += deltaTime;
	catSprite->angle = 20 * 3.14 * cosf(accuTime);
	position.y += 25 * cosf(accuTime);
	catSprite->position.x = position.x;
	catSprite->position.y = position.y;
}

void Cat::LeftFlip() const {
}

void Cat::RightFlip() const {
}

bool Cat::IsFlipped() {
	return false;
}

void Cat::Clamp() {
}