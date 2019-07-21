#pragma once

class Timer
{
public:
	Timer();
	void reset();
	double checkBlockTimer();

private:
	long startTime_;
};