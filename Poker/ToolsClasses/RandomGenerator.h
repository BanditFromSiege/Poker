#pragma once

#include "../PokerLogic/SevenCardCombination.h"
#include "../PokerLogic/SixCardCombination.h"

class RandomGenerator {
private:
	std::random_device random = {};
	std::unique_ptr<std::default_random_engine> engine
		= { std::make_unique<std::default_random_engine>(random()) };

public:
	RandomGenerator();

	template <typename T>
	requires std::is_integral_v<T>
	T getRandomNumber(T a, T b) const {
		std::uniform_int_distribution<T> r(a, b);
		return r(*engine);
	}

	bool Probability(std::uint8_t probability) const;

	template <typename Container>
	void Shuffle(Container& vector_of_elements) const {
		std::shuffle(vector_of_elements.begin(), vector_of_elements.end(), *engine);
	}
};