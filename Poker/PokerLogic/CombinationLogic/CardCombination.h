#pragma once

#include "../CardLogic/Hand_of_cards.h"

class CardCombination {
private:
	Poker::Combination power = Poker::Combination::High_card;
	char high_card = ' ';
	std::array<char, 4> kickers = {' ', ' ', ' ', ' '};

	CardCombination find_best_six_cards(const std::vector<Card>& vec_of_cards);
	CardCombination cast_string_six_cards(const std::string& str_of_cards);

	CardCombination find_best_seven_cards(const std::vector<Card>& vec_of_cards);
	CardCombination cast_string_seven_cards(const std::string& str_of_cards);

public:
	Poker::Combination getPower() const noexcept;
	char getHighCard() const noexcept;
	constexpr std::array<char, 4> getKickers() const noexcept;
	
	CardCombination() noexcept;

	CardCombination(const std::vector<Card>& vector_of_cards);
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
	Result compare_combinations(CardCombination comb1, CardCombination comb2) noexcept;
	std::int8_t find_outs(const std::string& string_of_cards, Poker::Combination comb, Poker::Stages stage);
}