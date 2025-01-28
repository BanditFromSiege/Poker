#pragma once

#include "../PokerLogic/Card.h"

namespace Poker {
	enum class Combination : std::uint8_t {
		high_card, pair, two_pair, set, straight, flush, full_house, care, straight_flush, royal_flush
	};

	enum class Result : std::uint8_t { 
		Draw, Win, Loss
	};
}

class FiveCardCombination {
private:
	Poker::Combination power = Poker::Combination::high_card;
	char high_card = ' ';
	std::array<char, 4> kickers = {' ', ' ', ' ', ' '};

public:
	Poker::Combination getPower() const noexcept;
	char getHighCard() const noexcept;
	constexpr std::array<char, 4> getKickers() const noexcept;
	
	FiveCardCombination() noexcept;

	FiveCardCombination(const std::vector<Card>& vec);
	FiveCardCombination(std::initializer_list<Card> lst);
	FiveCardCombination(const std::string& str);
	FiveCardCombination(const char* str);
	
	void ShowCombination() const noexcept;
};

bool operator<(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;
bool operator>(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;
bool operator==(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;
bool operator!=(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;
bool operator<=(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;
bool operator>=(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;

namespace Poker {
	Result compare_combinations(FiveCardCombination comb1, FiveCardCombination comb2) noexcept;
}

std::ostream& operator<<(std::ostream& out, Poker::Result res) noexcept;
std::ostream& operator<<(std::ostream& out, Poker::Combination comb) noexcept;