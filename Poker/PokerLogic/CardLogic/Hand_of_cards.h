#pragma once

#include "Card.h"

struct Hand_of_cards {
	char card1 = ' ';
	char card2 = ' ';
	bool suit_equal = false;

	Hand_of_cards(char card1, char card2, bool suit_equal);
	Hand_of_cards(Card other_card1, Card other_card2);
};

bool operator==(Hand_of_cards hand1, Hand_of_cards hand2);

namespace Tools {
	const auto hash = [](Hand_of_cards hoc) {
		std::size_t h1 = std::hash<char>{}(hoc.card1);
		std::size_t h2 = std::hash<char>{}(hoc.card2);
		std::size_t h3 = std::hash<bool>{}(hoc.suit_equal);
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