#include "Event.h"
#include <cassert>
using namespace Game_Lib;
Event::Event() :SDLevent(SDL_Event()) { Debug::Log(EMessageType::INFO, "Event", "Event", __FILE__, __LINE__, "Event Created"); }
Event::~Event() { Debug::Log(EMessageType::INFO, "Event", "~Event", __FILE__, __LINE__, "Event KILLED"); }
void Event::Initialize(SDL_Event _event) {
	SDLevent = _event;
	Debug::Log(EMessageType::INFO, "Event", "~Event", __FILE__, __LINE__, "Event Initialized");
}
void Event::Delete() {
	Event::~Event();
}