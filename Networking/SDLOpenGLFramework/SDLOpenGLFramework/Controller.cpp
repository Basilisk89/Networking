#include "Controller.h"

using namespace Game_Lib;
Controller::Controller() :controller(nullptr) {
}
Controller::~Controller() {
	Delete();
}

void Controller::Initialize() {
	for (int i = 0; i < 17; i++) {
		buttons[i] = false;
	}
	if (SDL_IsGameController(0))
		controller = SDL_GameControllerOpen(0);
	std::cout << SDL_GameControllerMapping(controller) << std::endl;
}

void Game_Lib::Controller::Delete() {
	delete buttons;
}