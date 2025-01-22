#pragma once

#include "Headers.h"

using namespace std::chrono;

template <typename T>
concept Time_type = 
	std::is_same_v<T, nanoseconds> || std::is_same_v<T, microseconds> ||
	std::is_same_v<T, milliseconds> || std::is_same_v<T, seconds> ||
	std::is_same_v<T, minutes> || std::is_same_v<T, hours>;

template <typename T>
concept Clock_type =
	std::is_same_v<T, system_clock> || std::is_same_v<T, steady_clock> ||
	std::is_same_v<T, high_resolution_clock> || std::is_same_v<T, utc_clock> ||
	std::is_same_v<T, tai_clock> || std::is_same_v<T, gps_clock>;

template <Time_type T = microseconds, Clock_type Clock = high_resolution_clock>
class Stopwatch {
private:
	time_point<Clock> begin{};
	time_point<Clock> end{};
public:
	constexpr void SetBeginPoint() noexcept { 
		begin = Clock::now();
	}
	constexpr void SetEndPoint() noexcept { 
		end = Clock::now();
	}

	static constexpr void ShowType() noexcept {
		if constexpr (std::is_same_v<T, nanoseconds>) {
			std::cout << "nanoseconds" << '\n';
		} else if (std::is_same_v<T, microseconds>) {
			std::cout << "microseconds" << '\n';
		} else if (std::is_same_v<T, milliseconds>) {
			std::cout << "mlliseconds" << '\n';
		} else if (std::is_same_v<T, seconds>) {
			std::cout << "seconds" << '\n';
		} else if (std::is_same_v<T, minutes>) {
			std::cout << "minutes" << '\n';
		} else {
			std::cout << "hours" << '\n';
		}
	}

	constexpr void ShowTime() noexcept {
		std::cout << GetTime() << ' ';
		ShowType();
	}

	constexpr auto GetTime() noexcept {
		return duration_cast<T>(end - begin).count();
	}
};

template <Time_type T = seconds, Clock_type Clock = high_resolution_clock>
constexpr void Delay(std::size_t time) noexcept {
	auto time_point = Clock::now();
	while (std::abs(duration_cast<T>(Clock::now() - time_point).count()) < time);
}