#pragma once

#include "../Headers.h"

namespace Tools {
	const std::unordered_map<char, std::uint8_t> cards = {
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
	char power = ' ';
	char suit = ' ';

public:
	Card() noexcept;
	Card(char power, char suit);
	Card(const std::string& str);
	Card(const char* str);

	char Power() const noexcept;
	char Suit() const noexcept;
};

bool operator<(Card c1, Card c2) noexcept;
bool operator>(Card c1, Card c2) noexcept;
bool operator==(Card c1, Card c2) noexcept;
bool operator!=(Card c1, Card c2) noexcept;
bool operator<=(Card c1, Card c2) noexcept;
bool operator>=(Card c1, Card c2) noexcept;

std::ostream& operator<<(std::ostream& out, Card c);

namespace Tools {
	struct Hand_of_cards {
		char c1 = ' ';
		char c2 = ' ';
		bool suit_equal = false;

		Hand_of_cards(char c1, char c2, bool suit_equal);
		Hand_of_cards(Card cd1, Card cd2);
	};

	bool operator==(Hand_of_cards hand1, Hand_of_cards hand2);

	const auto hash = [](Hand_of_cards hoc) {
		auto h1 = std::hash<char>{}(hoc.c1);
		auto h2 = std::hash<char>{}(hoc.c2);
		auto h3 = std::hash<bool>{}(hoc.suit_equal);
		return h1 ^ (h2 << 1) ^ (h3 << 2);
	};

	struct Premium_hands { // 5
		const std::unordered_set<Hand_of_cards, decltype(hash)> set = {
			{'A', 'A', false}, {'A', 'K', true}, {'A', 'K', false},
			{'K', 'K', false}, {'Q', 'Q', false}
		};
	};

	struct High_hands { // 11 
		const std::unordered_set<Hand_of_cards, decltype(hash)> set = {
			{'A', 'Q', true}, {'A', 'J', true}, {'A', 'T', true},
			{'K', 'Q', true}, {'K', 'J', true}, {'J', 'J', false},
			{'T', 'T', false}, {'9', '9', false}, {'A', 'Q', false},
			{'K', 'Q', false}, {'A', 'J', false}
		};
	};

	struct Medium_hands { // 20
		const std::unordered_set<Hand_of_cards, decltype(hash)> set = {
			{'Q', 'J', true}, {'Q', 'T', true}, {'J', 'T', true},
			{'K', 'T', true}, {'K', '9', true}, {'A', '9', true},
			{'A', '8', true}, {'A', '7', true}, {'A', '6', true},
			{'Q', 'J', false}, {'K', 'J', false}, {'K', 'T', false},
			{'A', 'T', false}, {'A', '9', false}, {'A', '8', false},
			{'A', '7', false}, {'8', '8', false}, {'7', '7', false},
			{'6', '6', false}, {'5', '5', false}
		};
	};

	struct Low_hands { // 24
		const std::unordered_set<Hand_of_cards, decltype(hash)> set = {
			{'A', '2', false}, {'A', '3', false}, {'A', '4', false},
			{'A', '5', false}, {'A', '6', false}, {'K', '9', false},
			{'Q', '9', false}, {'J', 'T', false}, {'T', '9', true},
			{'9', '8', true}, {'8', '7', true}, {'J', '9', true},
			{'Q', '9', true}, {'Q', '8', true}, {'K', '8', true},
			{'K', '7', true}, {'K', '6', true}, {'A', '5', true},
			{'A', '4', true}, {'A', '3', true}, {'A', '2', true},
			{'4', '4', false}, {'3', '3', false}, {'2', '2', false}
		};
	};

	struct Type_of_hands {
		Premium_hands premium;
		High_hands high;
		Medium_hands medium;
		Low_hands low;
	};

	std::uint8_t get_power_hand(const Type_of_hands& check, Hand_of_cards hand);
}