#pragma once

#include "FiveCardCombination.h"

class SixCardCombination : public FiveCardCombination {
private:
	FiveCardCombination find_best_six(const std::vector<Card>& table_cards, const std::vector<Card>& hand_cards);
	FiveCardCombination cast_string_six(const std::string& table_cards, const std::string& hand_cards);

public:
	SixCardCombination() noexcept;
	SixCardCombination(const std::vector<Card>& table_cards, const std::vector<Card>& hand_cards);
	SixCardCombination(const std::string& table_cards, const std::string& hand_cards);
	SixCardCombination(const std::string& string_of_cards);
	SixCardCombination(const std::vector<Card>& vector_of_cards);
	SixCardCombination(const char* string_of_cards);
};

namespace Poker {
	Result compare_combinations(SixCardCombination comb1, SixCardCombination comb2) noexcept;
};

