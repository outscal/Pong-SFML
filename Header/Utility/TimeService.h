#pragma once
#include <chrono>

namespace Utility
{
	class TimeService
	{
	private:
		std::chrono::steady_clock::time_point previous_time;
		float delta_time;
		void updateDeltaTime();
		float calculateDeltaTime();
		void updatePreviousTime(); // Update previous_time to the current time
		void initialize();
		static TimeService* instance; // Static instance for singleton pattern
		TimeService();
		
		TimeService(const TimeService&) = delete;  // Disable copy
		TimeService& operator=(const TimeService&) = delete; // Disable assignment
	public:
		static TimeService* getInstance();
		void update();
		float getDeltaTime();
	};
}