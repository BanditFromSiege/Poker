#pragma once

#include "../CardLogic/Hand_of_cards.h"

class CardCombination {
private:
	Poker::Combination power = Poker::Combination::High_card;
	char high_card = ' ';
	std::array<char, 4> kickers = {' ', ' ', ' ', ' '};

	CardCombination Find_best_six_cards(const std::span<Card>& vec_of_cards);
	CardCombination Cast_string_six_cards(const std::string& str_of_cards);

	CardCombination Find_best_seven_cards(const std::span<Card>& vec_of_cards);
	CardCombination Cast_string_seven_cards(const std::string& str_of_cards);

public:
	Poker::Combination GetPower() const noexcept;
	char GetHighCard() const noexcept;
	constexpr std::array<char, 4> GetKickers() const noexcept;
	
	CardCombination() noexcept;

	CardCombination(const std::span<Card>& vector_of_cards);
	CardCombination(std::initializer_list<Card> list_of_cards);
	CardCombination(const std::string& string_of_cards);
	CardCombination(const char* string_of_cards);
	
	void ShowCombination() const noexcept;
};

bool operator<(CardCombination comb1, CardCombination comb2) noexcept;
bool operator>(CardCombination comb1, CardCombination comb2) noexcept;
bool operator==(CardCombination comb1, CardCombination comb2) noexcept;
bool operator!=(CardCombination comb1, CardCombination comb2) noexcept;
bool operator<=(CardCombination comb1, CardCombination comb2) noexcept;
bool operator>=(CardCombination comb1, CardCombination comb2) noexcept;

namespace Poker {
	constexpr std::uint8_t count_of_cards_on_flop = 5;
	constexpr std::uint8_t count_of_cards_on_tern = 6;
	constexpr std::uint8_t count_of_cards_on_river = 7;

	constexpr std::uint8_t count_of_str_cards_on_flop = 14;
	constexpr std::uint8_t count_of_str_cards_on_tern = 17;
	constexpr std::uint8_t count_of_str_cards_on_river = 20;

	Result compare_combinations(CardCombination comb1, CardCombination comb2) noexcept;

	auto Find_Probability(const std::span<Card>& vector_of_cards)
		-> std::array<std::tuple<float, float, float, Poker::Combination>, 9>;
}