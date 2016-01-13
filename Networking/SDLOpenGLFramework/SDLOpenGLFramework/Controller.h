#ifndef Controller_H
#define Controller_H
#include <SDL.h>
#include "Debug.h"
namespace Game_Lib {
	class Controller {
	public:
		enum button : Uint8 {
			A = SDL_CONTROLLER_BUTTON_A,
			B = SDL_CONTROLLER_BUTTON_B,
			X = SDL_CONTROLLER_BUTTON_X,
			Y = SDL_CONTROLLER_BUTTON_Y,
			BACK = SDL_CONTROLLER_BUTTON_BACK,
			START = SDL_CONTROLLER_BUTTON_START,
			UP = SDL_CONTROLLER_BUTTON_DPAD_UP,
			DOWN = SDL_CONTROLLER_BUTTON_DPAD_DOWN,
			LEFT = SDL_CONTROLLER_BUTTON_DPAD_LEFT,
			RIGHT = SDL_CONTROLLER_BUTTON_DPAD_RIGHT
		};
		enum states :Uint8 {
			BUTTONDOWN = SDL_PRESSED,
			BUTTONUP = SDL_RELEASED
		}; SDL_Haptic* haptic;
		Controller();
		~Controller();
		void Initialize();
		void Delete();
		friend class ControllerManager;
	private:
		bool buttons[17];
		SDL_GameController* controller;
	};
}
#endif