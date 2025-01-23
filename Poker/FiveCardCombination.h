#pragma once

#include "Card.h"

class FiveCardCombination {
private:
	std::uint8_t power = 0;
	char high_card = ' ';

	std::array<char, 4> kickers = {' ', ' ', ' ', ' '};

public:
	std::uint8_t CombinationPower() const noexcept;
	char HighCard() const noexcept;

	constexpr std::array<char, 4> Kickers() const noexcept;
	
	FiveCardCombination() noexcept;
	FiveCardCombination(std::vector<Card> lst);
	FiveCardCombination(std::initializer_list<Card> lst);
	FiveCardCombination(std::string str);
	FiveCardCombination(const char* str);
	
	void Combination() const noexcept;
};

bool operator<(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;
bool operator>(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;
bool operator==(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;
bool operator!=(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;
bool operator<=(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;
bool operator>=(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;

namespace Poker {
	enum class Result : std::uint8_t { Draw, Win, Loss };
	Result compare_combinations(FiveCardCombination comb1, FiveCardCombination comb2);
	void Index(std::size_t n);
}

std::ostream& operator<<(std::ostream& out, Poker::Result res);