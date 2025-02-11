#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() = default;

bool RandomGenerator::Probability(std::uint8_t probability) const {
	if (probability >= 100) { return true; }
	else if (probability <= 0) { return false; }

	std::uint8_t p = GetRandomNumber(1, 100);
	return p <= probability;
}