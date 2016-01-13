#include "Mouse.h"

using namespace Game_Lib;

Mouse::Mouse() :MouseCoordinates(0.0f, 0.0f) {
}

Mouse::~Mouse() {
	Delete();
}

void Mouse::Initialize() {
	for (int i = 0; i < MOUSE_BUTTONS; i++)
		mouseButtons[i] = false;
}

void Mouse::Delete() {
	for (int i = 0; i < 3; i++) {
		//delete mouseButtons[i];
	}
}