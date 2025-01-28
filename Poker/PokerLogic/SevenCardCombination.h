#pragma once

#include "../PokerLogic/FiveCardCombination.h"

class SevenCardCombination : public FiveCardCombination {
private:
	FiveCardCombination find_best(const std::vector<Card>& vec, const std::vector<Card>& add_vec);
	FiveCardCombination cast_string(const std::string& str, const std::string& add_str);
public:
	SevenCardCombination() noexcept;
	SevenCardCombination(const std::vector<Card>& vec, const std::vector<Card>& add_vec);
	SevenCardCombination(const std::string& str, const std::string& add_str);
	SevenCardCombination(const std::string& str);
	SevenCardCombination(const std::vector<Card>& vec);
	SevenCardCombination(const char* str);
};

namespace Poker {
	Result compare_combinations(SevenCardCombination comb1, SevenCardCombination comb2) noexcept;
};
