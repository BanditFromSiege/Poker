#include "SixCardCombination.h"

FiveCardCombination SixCardCombination::find_best_six
	(
		const std::vector<Card>& table_cards,
		const std::vector<Card>& hand_cards
	)
{
	if ((table_cards.size() != 4) || (hand_cards.size() != 2)) {
		throw std::runtime_error("Not six cards for combination");
	}

	std::vector<std::vector<Card>> combinations = {
		{ table_cards[0], table_cards[1], table_cards[2], table_cards[3], hand_cards[0] },
		{ table_cards[0], table_cards[1], table_cards[2], table_cards[3], hand_cards[1] },
		{ table_cards[0], table_cards[1], table_cards[2], hand_cards[0], hand_cards[1] },
		{ table_cards[0], table_cards[1], hand_cards[0], hand_cards[1], table_cards[3] },
		{ table_cards[0], hand_cards[0], hand_cards[1], table_cards[2], table_cards[3] },
		{ hand_cards[0], hand_cards[1], table_cards[1], table_cards[2], table_cards[3] }
	};

	FiveCardCombination res = combinations[0];
	for (std::uint8_t i = 1; i < combinations.size(); ++i) {
		res = std::max(res, FiveCardCombination(combinations[i]));
	}

	return res;
}

FiveCardCombination SixCardCombination::cast_string_six
	(
		const std::string& table_cards,
		const std::string& hand_cards
	)
{
	if ((table_cards.size() != 11) || (hand_cards.size() != 5)) {
		throw std::runtime_error("Not six cards for combination");
	}

	std::vector<Card> vector_of_table_cards;
	vector_of_table_cards.reserve(4);

	for (std::uint8_t i = 0; i < table_cards.size(); i += 3) {
		vector_of_table_cards.push_back({ table_cards[i], table_cards[i + 1] });
	}
	
	std::vector<Card> vector_of_hand_cards;
	vector_of_hand_cards.reserve(2);

	for (std::uint8_t i = 0; i < hand_cards.size(); i += 3) {
		vector_of_hand_cards.push_back({ hand_cards[i], hand_cards[i + 1] });
	}

	return find_best_six(vector_of_table_cards, vector_of_hand_cards);
}

SixCardCombination::SixCardCombination() noexcept = default;

SixCardCombination::SixCardCombination(const std::vector<Card>& table_cards, const std::vector<Card>& hand_cards)
	: FiveCardCombination(find_best_six(table_cards, hand_cards)) {}

SixCardCombination::SixCardCombination(const std::string& table_cards, const std::string& hand_cards)
	: FiveCardCombination(cast_string_six(table_cards, hand_cards)) {}

SixCardCombination::SixCardCombination(const std::string& string_of_cards)
	: SixCardCombination::SixCardCombination(string_of_cards.substr(0, 11), string_of_cards.substr(12, 5)) {}

SixCardCombination::SixCardCombination(const std::vector<Card>& vector_of_cards) 
	: SixCardCombination::SixCardCombination
	(
		{ vector_of_cards[0], vector_of_cards[1], vector_of_cards[2], vector_of_cards[3] },
		{ vector_of_cards[4], vector_of_cards[5] }
	)
{
	if (vector_of_cards.size() != 6) { throw std::runtime_error("Not six cards for combination"); }
}

SixCardCombination::SixCardCombination(const char* string_of_cards)
	: SixCardCombination::SixCardCombination(std::string(string_of_cards)) {}

namespace Poker {
	Result compare_combinations(SixCardCombination comb1, SixCardCombination comb2) noexcept {
		if (comb1 < comb2) { return Result::Loss; }
		else if (comb1 > comb2) { return Result::Win; }
		else { return Result::Draw; }
	}
}
