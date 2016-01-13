#ifndef Mouse_H
#define Mouse_H
#include "Vec3.h"
#include <SDL.h>
#include "Debug.h"
namespace Game_Lib {
	class Mouse {
	public:
		// set of mouse states set to SDLs mouse states
		enum State : unsigned int {
			UP_CLICK = SDL_MOUSEBUTTONUP,
			DOWN_CLICK = SDL_MOUSEBUTTONDOWN,
			MOUSE_MOVE = SDL_MOUSEMOTION
		};
		// set of mouse buttons set to SDLs mouse  buttons
		enum Buttons : unsigned int {
			LEFT_BUTTON = SDL_BUTTON_LEFT,
			MIDDLE_BUTTON = SDL_BUTTON_MIDDLE,
			RIGHT_BUTTON = SDL_BUTTON_RIGHT
		};
		static const int MOUSE_BUTTONS = 3;
		Mouse();
		Mouse(Mouse&) = delete;
		Mouse(Mouse&&) = delete;
		Mouse operator = (Mouse&) = delete;
		Mouse operator = (Mouse&&) = delete;
		~Mouse();
		void Initialize();
		void Delete();
		friend class MouseManager;
	private:
		// private boolean array of mouse buttons
		bool mouseButtons[MOUSE_BUTTONS];
		Vec2 MouseCoordinates;
	};
}
#endif