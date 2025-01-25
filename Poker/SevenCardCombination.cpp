#include "SevenCardCombination.h"

FiveCardCombination SevenCardCombination::find_best(const std::vector<Card>& vec, const std::vector<Card>& add_vec) {
	if ((vec.size() > 5) || (add_vec.size() > 2)) { throw std::runtime_error("Too many cards for combination"); }

	std::vector<std::vector<Card>> hands = {
		{ vec[0], vec[1], vec[2], vec[3], vec[4] },

		{ add_vec[0], vec[1], vec[2], vec[3], vec[4] },
		{ vec[0], add_vec[0], vec[2], vec[3], vec[4] },
		{ vec[0], vec[1], add_vec[0], vec[3], vec[4] },
		{ vec[0], vec[1], vec[2], add_vec[0], vec[4] },
		{ vec[0], vec[1], vec[2], vec[3], add_vec[0] },

		{ add_vec[1], vec[1], vec[2], vec[3], vec[4] },
		{ vec[0], add_vec[1], vec[2], vec[3], vec[4] },
		{ vec[0], vec[1], add_vec[1], vec[3], vec[4] },
		{ vec[0], vec[1], vec[2], add_vec[1], vec[4] },
		{ vec[0], vec[1], vec[2], vec[3], add_vec[1] },

		{ add_vec[0], add_vec[1], vec[2], vec[3], vec[4] },
		{ add_vec[0], vec[1], add_vec[1], vec[3], vec[4] },
		{ add_vec[0], vec[1], vec[2], add_vec[1], vec[4] },
		{ add_vec[0], vec[1], vec[2], vec[3], add_vec[1] },

		{ vec[0], add_vec[1], add_vec[0], vec[3], vec[4] },
		{ vec[0], add_vec[1], vec[2], add_vec[0], vec[4] },
		{ vec[0], add_vec[1], vec[2], vec[3], add_vec[0] },

		{ vec[0], vec[1], vec[2], add_vec[0], add_vec[1] },
		{ vec[0], vec[1], add_vec[0], vec[3], add_vec[1] },
		{ add_vec[0], vec[1], vec[2], vec[3], add_vec[1] }
	};

	FiveCardCombination res = hands[0];
	for (std::uint8_t i = 1; i < hands.size(); ++i) {
		res = std::max(res, FiveCardCombination(hands[i]));
	}

	return res;
}

FiveCardCombination SevenCardCombination::cast_string(const std::string& str, const std::string& add_str) {
	if ((str.size() > 14) || (add_str.size() > 5)) { throw std::runtime_error("Too many cards for combination"); }

	std::vector<Card> vec;
	vec.reserve(5);

	for (std::uint8_t i = 0; i < str.size(); i += 3) {
		vec.push_back({ str[i], str[i + 1] });
	}

	std::vector<Card> add_vec;
	add_vec.reserve(2);

	for (std::uint8_t i = 0; i < add_str.size(); i += 3) {
		add_vec.push_back({ add_str[i], add_str[i + 1] });
	}

	return find_best(vec, add_vec);
}

SevenCardCombination::SevenCardCombination() noexcept = default;

SevenCardCombination::SevenCardCombination(const std::vector<Card>& vec, const std::vector<Card>& add_vec)
	: FiveCardCombination(find_best(vec, add_vec)) {}

SevenCardCombination::SevenCardCombination(const std::string& str, const std::string& add_str) 
	: FiveCardCombination(cast_string(str, add_str)) {}

SevenCardCombination::SevenCardCombination(const std::string& str) 
	: SevenCardCombination::SevenCardCombination(str.substr(0, 14), str.substr(15, 5)) {}

SevenCardCombination::SevenCardCombination(const char* str) 
	: SevenCardCombination::SevenCardCombination(std::string(str)) {}

namespace Poker {
	Result compare_combinations(SevenCardCombination comb1, SevenCardCombination comb2) noexcept {
		if (comb1 < comb2) { return Result::Loss; }
		else if (comb1 > comb2) { return Result::Win; }
		else { return Result::Draw; }
	}
}