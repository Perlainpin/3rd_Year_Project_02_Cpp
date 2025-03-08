#include "pch.h"
#include "Timer.h"

Timer::Timer() {
	_startTime = 0;
}

Timer::~Timer() {
}

void Timer::Start() {
	_startTime = timeGetTime();
}

void Timer::Restart() {
	_startTime = timeGetTime();
}

float Timer::GetTimeSinceStart() {
	return _startTime - timeGetTime();
}

float Timer::GetTime() {
	return timeGetTime();
}