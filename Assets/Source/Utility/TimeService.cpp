#include "../../Header/Utility/TimeService.h"
namespace Utility
{

	void Utility::TimeService::initialize()
	{
		previous_time = std::chrono::steady_clock::now();
		delta_time = 0;

	}

	




	void TimeService::updateDeltaTimee()
	{
		delta_time = calculateDeltatime();
		updatePreviousTime();
	}

	float TimeService::calculateDeltatime()
	{
		int delta = std::chrono::duration_cast<std::chrono::microseconds>(
			std::chrono::steady_clock::now() - previous_time).count();

		// Convert to seconds
		return static_cast<float>(delta) / 1000000.0f;
	}

	void TimeService::updatePreviousTime()
	{
		previous_time = std::chrono::steady_clock::now();
	}
	void TimeService::update()
	{
		updateDeltaTimee();

	}

	float TimeService::getDeltatime()
	{
		return delta_time;
	}



}
