#pragma once

#include "Card.h"

class FiveCardCombination {
private:
	std::int8_t power = 0;
	char high_card = ' ';

public:
	int CombinationPower() const noexcept;
	char HighCard() const noexcept;
	
	FiveCardCombination() noexcept;
	FiveCardCombination(std::vector<Card> lst);
	FiveCardCombination(std::initializer_list<Card> lst);
	FiveCardCombination(std::string str);
	FiveCardCombination(const char* str);
	
	void Combination() const;
};

bool operator<(FiveCardCombination comb1, FiveCardCombination comb2);
bool operator>(FiveCardCombination comb1, FiveCardCombination comb2);
bool operator==(FiveCardCombination comb1, FiveCardCombination comb2);

namespace Poker {
	int compare_combinations(FiveCardCombination comb1, FiveCardCombination comb2);
	void Index(std::size_t n);
}