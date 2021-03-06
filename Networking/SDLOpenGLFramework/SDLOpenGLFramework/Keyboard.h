#ifndef Keyboard_H
#define Keyboard_H
#include <SDL.h>
#include <SDL_scancode.h>
#include "Debug.h"
namespace Game_Lib {
	class Keyboard {
	public:
		// enum of keyboard states that are equal to SDL keyboard states
		enum State : unsigned int {
			KEYDOWN = SDL_KEYDOWN,
			KEYUP = SDL_KEYUP
		};
		// an enum of keys that are equal to SDL scancodes i chose
		enum Key : unsigned int {
			A = SDL_SCANCODE_A,
			D = SDL_SCANCODE_D,
			S = SDL_SCANCODE_S,
			W = SDL_SCANCODE_W,
			SPACE = SDL_SCANCODE_SPACE,
			ESCAPE = SDL_SCANCODE_ESCAPE
		};
		// get the number of scan codes from SDL but them into a static const int , going to need it for an array of boolean keys
		static const int KEYBOARD_KEYS = SDL_NUM_SCANCODES;
		Keyboard();
		Keyboard(Keyboard&) = delete;
		Keyboard(Keyboard&&) = delete;
		Keyboard operator = (Keyboard&) = delete;
		Keyboard operator = (Keyboard&&) = delete;
		~Keyboard();
		void Initialize();
		void Delete();
		// with class Keyboard manager as a friend , the manager can touch the keys array.
		friend class KeyboardManager;
	private:
		// our private set of keys for the keyboard to check
		bool key[KEYBOARD_KEYS];
	};
}
#endif