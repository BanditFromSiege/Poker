#pragma once

#include "Headers.h"

namespace Tools {
	const std::unordered_map<char, int8_t> cards = {
		{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8},
		{'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14},
	};

	constexpr inline auto comparator = 
		[](std::pair<char, std::uint8_t> p1, std::pair<char, std::uint8_t> p2) {
			return cards.find(p1.first)->second < cards.find(p2.first)->second;
		};

	constexpr inline auto suit_check = [](char s) {
		return (s == 'S' || s == 'H' || s == 'D' || s == 'C');
	};
}

class Card {
private:
	char power = 0;
	char suit = ' ';

public:
	Card() noexcept;

	Card(char power, char suit);
	Card(std::pair<char, char> a);
	Card(std::initializer_list<char> lst);

	char Power() const noexcept;
	char Suit() const noexcept;
};

bool operator<(Card c1, Card c2) noexcept;
bool operator>(Card c1, Card c2) noexcept;

std::ostream& operator<<(std::ostream& out, Card c);