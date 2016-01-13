#include "EventHandler.h"
using namespace Game_Lib;
EventHandler::EventHandler() :event(new Event()) { Debug::Log(EMessageType::INFO, "EventHandler", "EventHandler", __FILE__, __LINE__, "Event Handler Created"); }
EventHandler::~EventHandler() { Debug::Log(EMessageType::INFO, "EventHandler", "~EventHandler", __FILE__, __LINE__, "Event Handler killed"); OnDestroy(); }
int Game_Lib::EventHandler::Update() {
	while (SDL_PollEvent(&event->SDLevent) == 1) {
		return 1;
	}
	return 0;
}
void EventHandler::Initialize(SDL_Event _event) {
	event->Initialize(_event);
	Debug::Log(EMessageType::INFO, "EventHandler", "Initialize", __FILE__, __LINE__, "Event Handlerer initializing Event");
}
void Game_Lib::EventHandler::OnDestroy() {
	delete event;
	event = nullptr;
}
SDL_KeyboardEvent EventHandler::getKey() const {
	return event->SDLevent.key;
}
Uint32 EventHandler::getType() const {
	return event->SDLevent.type;
}
SDL_Scancode EventHandler::getScanCode() const {
	return event->SDLevent.key.keysym.scancode;
}