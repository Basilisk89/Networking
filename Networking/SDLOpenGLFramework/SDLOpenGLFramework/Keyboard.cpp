#include "Keyboard.h"

using namespace Game_Lib;

Keyboard::Keyboard() {
}

Keyboard::~Keyboard() {
	Delete();
}

void Keyboard::Initialize() {
	for (int i = 0; i < KEYBOARD_KEYS; i++)
		key[i] = false;
}

void Keyboard::Delete() {
	//	delete[] key;
}