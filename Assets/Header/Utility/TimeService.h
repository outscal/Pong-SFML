#pragma once
#include<chrono>
namespace Utility
{
	class TimeService
	{
	protected:
		std::chrono::steady_clock::time_point previous_time;
		float delta_time;
		void updateDeltaTimee();
		float calculateDeltatime();
		void updatePreviousTime();


	public:
		void initialize();
		void update();
		float getDeltatime();
	};
}