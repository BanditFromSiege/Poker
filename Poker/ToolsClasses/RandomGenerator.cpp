#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() = default;

bool RandomGenerator::Probability(std::uint8_t prop) const {
	if (prop >= 100) { return true; }
	else if (prop <= 0) { return false; }

	std::uint8_t p = getRandomNumber(1, 100);
	return p <= prop;
}

void RandomGenerator::Shuffle(std::vector<Card>& vec) const {
	std::shuffle(vec.begin(), vec.end(), *mt);
}