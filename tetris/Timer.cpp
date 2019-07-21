#include "Timer.h"
#include "Constants.h"
#include "graphics.h"

Timer::Timer()
{
	startTime_ = GetTickCount();
}

void Timer::reset()
{
	startTime_ = GetTickCount();
}

double Timer::checkBlockTimer()
{
	return (GetTickCount() - startTime_)/1000.0;
}