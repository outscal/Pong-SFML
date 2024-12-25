#include "../../Header/Utility/TimeManager.h"

using namespace Utility;

void TimeManager::updateDeltaTime()
{
	delta_time = calculateDeltaTime();
	updatePreviousTime();
}

void TimeManager::initialize()
{
	previous_time = std::chrono::steady_clock::now();
	delta_time = 0;
}

void TimeManager::update()
{
	updateDeltaTime();
}

float TimeManager::getDeltaTime()
{
	return delta_time;
}

float TimeManager::calculateDeltaTime()
{
	// Get time difference in microseconds
	int delta = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time).count();
	//converts into seconds.
	return static_cast<float>(delta) / 1000000.0f;
}

void TimeManager::updatePreviousTime()
{
	previous_time = std::chrono::steady_clock::now();
}
