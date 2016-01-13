#include "KeyboardManager.h"

using namespace Game_Lib;

KeyboardManager::KeyboardManager() :keyboard(new Keyboard()) {
}

KeyboardManager::~KeyboardManager() {
	Delete();
}

void KeyboardManager::Initialize() {
	// initialize all keys to false
	keyboard->Initialize();
}

void KeyboardManager::Delete() {
	// delete the array of keys in the keyboard;
	Debug::Log(EMessageType::INFO, "Keyboardmanager", "Delete", __FILE__, __LINE__, "Deleting keyboardManager");
	delete keyboard;
	keyboard = nullptr;
}

void  KeyboardManager::OnPress(const unsigned int& keyCode) {
	keyboard->key[keyCode] = true;
}

void  KeyboardManager::OnRelease(const unsigned int& keyCode) {
	keyboard->key[keyCode] = false;
}

bool  KeyboardManager::IsPressed(const unsigned int& keyCode) {
	bool keyIsPressed = keyboard->key[keyCode];
	if (keyIsPressed) {
		return keyIsPressed;
	}
	else {
		return false;
	}
}
bool KeyboardManager::IsReleased(const unsigned int& keyCode) {
	bool keyIsPressed = keyboard->key[keyCode];
	if (!keyIsPressed) {
		return true;
	}
	else {
		return false;
	}
}