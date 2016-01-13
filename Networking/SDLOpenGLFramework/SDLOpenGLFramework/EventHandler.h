#ifndef EventManager_H
#define EventManager_H
#include "Event.h"
#include <SDL.h>
namespace Game_Lib {
	class EventHandler :public Event {
	public:
		EventHandler();
		~EventHandler();
		void Initialize(SDL_Event _event);
		void OnDestroy();
		int Update();

		SDL_KeyboardEvent getKey() const;
		Uint32 getType() const;
		SDL_Scancode getScanCode() const;
	private:
		Event* event;
	};
}
#endif