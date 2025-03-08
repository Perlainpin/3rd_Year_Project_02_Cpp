#pragma once

class Timer {
public:
	Timer();
	~Timer();

	void Start();
	//int Stop();
	void Restart();
	float GetTimeSinceStart();
	float GetTime();

private:
	float _startTime;
};