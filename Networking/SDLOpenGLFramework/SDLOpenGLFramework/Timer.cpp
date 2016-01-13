#include "Timer.h"
using namespace Game_Lib;
Timer::Timer() :prevTicks(0), currTicks(0) { Debug::Log(EMessageType::INFO, "Timer", "Timer", __FILE__, __LINE__, "Hello from Timer"); }
Timer::~Timer() { Debug::Log(EMessageType::INFO, "Timer", "~Timer", __FILE__, __LINE__, "Goodbye from timer"); }
void Timer::UpdateFrameTicks() {
	prevTicks = currTicks;
	currTicks = clock();
}
void Timer::Start() {
	Debug::Log(EMessageType::INFO, "Timer", "UpdateFrameTicks", __FILE__, __LINE__, "Starting Timer");
	prevTicks = clock();
	currTicks = clock();
}
float Timer::GetDeltaTime() const {
	return (currTicks - prevTicks) / 1000.0f;
}
unsigned int Timer::GetSleepTime(const unsigned int fps) const {
	unsigned int milliSecsPerFrame = 1000 / fps;
	if (milliSecsPerFrame == 0)
		return 0;
	unsigned int sleepTime = milliSecsPerFrame - (prevTicks - currTicks);
	if (sleepTime > milliSecsPerFrame)
		return milliSecsPerFrame;
	return sleepTime;
}