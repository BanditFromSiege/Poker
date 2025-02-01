#include "../PokerLogic/SevenCardCombination.h"

FiveCardCombination SevenCardCombination::find_best_seven
	(
		const std::vector<Card>& table_cards,
		const std::vector<Card>& hand_cards
	)
{
	if ((table_cards.size() != 5) || (hand_cards.size() != 2)) {
		throw std::runtime_error("Not seven cards for combination");
	}

	std::vector<std::vector<Card>> combinations = {
		{ table_cards[0], table_cards[1], table_cards[2], table_cards[3], table_cards[4] },

		{ hand_cards[0], table_cards[1], table_cards[2], table_cards[3], table_cards[4] },
		{ table_cards[0], hand_cards[0], table_cards[2], table_cards[3], table_cards[4] },
		{ table_cards[0], table_cards[1], hand_cards[0], table_cards[3], table_cards[4] },
		{ table_cards[0], table_cards[1], table_cards[2], hand_cards[0], table_cards[4] },
		{ table_cards[0], table_cards[1], table_cards[2], table_cards[3], hand_cards[0] },

		{ hand_cards[1], table_cards[1], table_cards[2], table_cards[3], table_cards[4] },
		{ table_cards[0], hand_cards[1], table_cards[2], table_cards[3], table_cards[4] },
		{ table_cards[0], table_cards[1], hand_cards[1], table_cards[3], table_cards[4] },
		{ table_cards[0], table_cards[1], table_cards[2], hand_cards[1], table_cards[4] },
		{ table_cards[0], table_cards[1], table_cards[2], table_cards[3], hand_cards[1] },

		{ hand_cards[0], hand_cards[1], table_cards[2], table_cards[3], table_cards[4] },
		{ hand_cards[0], table_cards[1], hand_cards[1], table_cards[3], table_cards[4] },
		{ hand_cards[0], table_cards[1], table_cards[2], hand_cards[1], table_cards[4] },
		{ hand_cards[0], table_cards[1], table_cards[2], table_cards[3], hand_cards[1] },

		{ table_cards[0], hand_cards[1], hand_cards[0], table_cards[3], table_cards[4] },
		{ table_cards[0], hand_cards[1], table_cards[2], hand_cards[0], table_cards[4] },
		{ table_cards[0], hand_cards[1], table_cards[2], table_cards[3], hand_cards[0] },

		{ table_cards[0], table_cards[1], table_cards[2], hand_cards[0], hand_cards[1] },
		{ table_cards[0], table_cards[1], hand_cards[0], table_cards[3], hand_cards[1] },
		{ hand_cards[0], table_cards[1], table_cards[2], table_cards[3], hand_cards[1] }
	};

	FiveCardCombination res = combinations[0];
	for (std::uint8_t i = 1; i < combinations.size(); ++i) {
		res = std::max(res, FiveCardCombination(combinations[i]));
	}

	return res;
}

FiveCardCombination SevenCardCombination::cast_string_seven
	(
		const std::string& table_cards,
		const std::string& hand_cards
	)
{
	if ((table_cards.size() != 14) || (hand_cards.size() != 5)) {
		throw std::runtime_error("Not seven cards for combination");
	}

	std::vector<Card> vector_of_table_cards;
	vector_of_table_cards.reserve(5);

	for (std::uint8_t i = 0; i < table_cards.size(); i += 3) {
		vector_of_table_cards.push_back({ table_cards[i], table_cards[i + 1] });
	}

	std::vector<Card> vector_of_hand_cards;
	vector_of_hand_cards.reserve(2);

	for (std::uint8_t i = 0; i < hand_cards.size(); i += 3) {
		vector_of_hand_cards.push_back({ hand_cards[i], hand_cards[i + 1] });
	}

	return find_best_seven(vector_of_table_cards, vector_of_hand_cards);
}

SevenCardCombination::SevenCardCombination() noexcept = default;

SevenCardCombination::SevenCardCombination(const std::vector<Card>& table_cards, const std::vector<Card>& hand_cards)
	: FiveCardCombination(find_best_seven(table_cards, hand_cards)) {}

SevenCardCombination::SevenCardCombination(const std::string& table_cards, const std::string& hand_cards)
	: FiveCardCombination(cast_string_seven(table_cards, hand_cards)) {}

SevenCardCombination::SevenCardCombination(const std::string& string_of_cards)
	: SevenCardCombination::SevenCardCombination(string_of_cards.substr(0, 14), string_of_cards.substr(15, 5)) {}

SevenCardCombination::SevenCardCombination(const std::vector<Card>& vector_of_cards)
	: SevenCardCombination::SevenCardCombination
	(
		{ vector_of_cards[0], vector_of_cards[1], vector_of_cards[2], vector_of_cards[3], vector_of_cards[4] },
		{ vector_of_cards[5], vector_of_cards[6] }
	) 
{
	if (vector_of_cards.size() != 7) { throw std::runtime_error("Not seven cards for combination"); }
}

SevenCardCombination::SevenCardCombination(const char* string_of_cards)
	: SevenCardCombination::SevenCardCombination(std::string(string_of_cards)) {}

namespace Poker {
	Result compare_combinations(SevenCardCombination comb1, SevenCardCombination comb2) noexcept {
		if (comb1 < comb2) { return Result::Loss; }
		else if (comb1 > comb2) { return Result::Win; }
		else { return Result::Draw; }
	}
}