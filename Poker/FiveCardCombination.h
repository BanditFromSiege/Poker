#pragma once

#include "Card.h"

class FiveCardCombination {
private:
	std::uint8_t power = 0;
	char high_card = ' ';

	std::array<char, 4> kickers = {' ', ' ', ' ', ' '};

public:
	std::uint8_t getPower() const noexcept;
	char getHighCard() const noexcept;
	constexpr std::array<char, 4> getKickers() const noexcept;
	
	FiveCardCombination() noexcept;

	FiveCardCombination(const std::vector<Card>& vec);
	FiveCardCombination(std::initializer_list<Card> lst);
	FiveCardCombination(const std::string& str);
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
	Result compare_combinations(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;
	void Index(std::size_t n) noexcept;
}

std::ostream& operator<<(std::ostream& out, Poker::Result res);