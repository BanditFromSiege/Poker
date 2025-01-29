#pragma once

#include "../PokerLogic/SevenCardCombination.h"

class RandomGenerator {
private:
	std::random_device random = {};
	std::unique_ptr<std::default_random_engine> mt
		= { std::make_unique<std::default_random_engine>(random()) };

public:
	RandomGenerator();

	template <typename T>
	requires std::is_integral_v<T>
	T getRandomNumber(T a, T b) const {
		std::uniform_int_distribution<T> r(a, b);
		return r(*mt);
	}

	bool Probability(std::uint8_t prop) const;
	void Shuffle(std::vector<Card>& vec) const;
};