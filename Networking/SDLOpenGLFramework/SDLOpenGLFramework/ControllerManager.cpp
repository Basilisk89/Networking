#include "ControllerManager.h"
#include <iostream>

using namespace Game_Lib;
ControllerManager::ControllerManager() :controller(nullptr) {
}

ControllerManager::~ControllerManager() {
}

void Game_Lib::ControllerManager::Initialize() {
	controller = new Controller();
	controller->Initialize();
}

void Game_Lib::ControllerManager::Delete() {
	controller->Delete();
	delete controller;
	controller = nullptr;
}

void const Game_Lib::ControllerManager::OnPress(const unsigned int & keyCode)
{
	buttons[keyCode] = true;
}

void const Game_Lib::ControllerManager::OnRelease(const unsigned int & keyCode)
{
	buttons[keyCode] = false;
}

bool const Game_Lib::ControllerManager::IsPressed(const unsigned int & keyCode)
{
	bool isPressed = buttons[keyCode];
	std::cout << keyCode << std::endl;
	if (isPressed == true)
		return isPressed;
	else { return false; }
}