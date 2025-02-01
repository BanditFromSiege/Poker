#pragma once

#include "../PokerLogic/FiveCardCombination.h"

class SevenCardCombination : public FiveCardCombination {
private:
	FiveCardCombination find_best_seven(const std::vector<Card>& table_cards, const std::vector<Card>& hand_cards);
	FiveCardCombination cast_string_seven(const std::string& table_cards, const std::string& hand_cards);

public:
	SevenCardCombination() noexcept;
	SevenCardCombination(const std::vector<Card>& table_cards, const std::vector<Card>& hand_cards);
	SevenCardCombination(const std::string& table_cards, const std::string& hand_cards);
	SevenCardCombination(const std::string& string_of_cards);
	SevenCardCombination(const std::vector<Card>& vector_of_cards);
	SevenCardCombination(const char* string_of_cards);
};

namespace Poker {
	Result compare_combinations(SevenCardCombination comb1, SevenCardCombination comb2) noexcept;
};
