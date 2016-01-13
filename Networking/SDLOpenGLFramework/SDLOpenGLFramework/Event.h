#ifndef Event_H
#define Event_H
#include <SDL.h>
#include "Debug.h"
namespace Game_Lib {
	class Event {
	public:
		Event();
		~Event();
		void Initialize(SDL_Event _event);
		void Delete();
		friend class EventHandler;
	private:
		SDL_Event SDLevent;
	};
}
#endif 