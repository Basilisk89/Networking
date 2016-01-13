#include "MouseManager.h"
using namespace Game_Lib;
MouseManager::MouseManager() :mouse(new Mouse()) {}
MouseManager::~MouseManager() {
	Delete();
}
void MouseManager::Initialize() {
	mouse->Initialize();
}
void MouseManager::Delete() {
	delete mouse;
	mouse = nullptr;

	Debug::Log(EMessageType::INFO, "MouseManager", "Delete", __FILE__, __LINE__, "Deleting");
}
void MouseManager::OnPress(const int keyCode) {
	mouse->mouseButtons[keyCode] = true;
}
void MouseManager::OnRelease(const int keyCode) {
	mouse->mouseButtons[keyCode] = false;
}
bool MouseManager::IsPressed(const int keyCode) {
	bool MouseIsPressed = mouse->mouseButtons[keyCode];
	if (MouseIsPressed) {
		return MouseIsPressed;
	}
	else {
		return MouseIsPressed;
	}
}
Vec2 MouseManager::GetMouseCoordinates() const {
	return mouse->MouseCoordinates;
}
void MouseManager::SetMouseCoordinates(const int x, const int y) {
	mouse->MouseCoordinates = Vec2(x, y);
}