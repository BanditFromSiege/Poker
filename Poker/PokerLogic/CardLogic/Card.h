#pragma once

#include "../Enums.h"

namespace Tools {
	constexpr auto cards = [](char card) -> std::uint8_t {
		switch (card) {
			case '2': return 2;
			case '3': return 3;
			case '4': return 4;
			case '5': return 5;
			case '6': return 6;
			case '7': return 7;
			case '8': return 8;
			case '9': return 9;
			case 'A': return 14;
			case 'J': return 11;
			case 'K': return 13;
			case 'Q': return 12;
			case 'T': return 10;
			default: throw std::runtime_error("Uncorrected card");
		}
	};

	constexpr auto int_to_cards = [](std::uint8_t power) -> char {
		switch (power) {
			case 2: return '2';
			case 3: return '3';
			case 4: return '4';
			case 5: return '5';
			case 6: return '6';
			case 7: return '7';
			case 8: return '8';
			case 9: return '9';
			case 10: return 'T';
			case 11: return 'J';
			case 12: return 'Q';
			case 13: return 'K';
			case 14: return 'A';
			default: throw std::runtime_error("Uncorrected card");
		}
	};

	constexpr auto suits = [](char suit) -> std::uint8_t {
		switch (suit) {
			case 'C': return 1;
			case 'D': return 2;
			case 'H': return 3;
			case 'S': return 4;
			default: throw std::runtime_error("Uncorrected suit");
		}
	};

	constexpr auto int_to_suits = [](std::uint8_t int_suit) -> char {
		switch (int_suit) {
			case 1: return 'C';
			case 2: return 'D';
			case 3: return 'H';
			case 4: return 'S';
			default: throw std::runtime_error("Uncorrected suit");
		}
	};

	constexpr auto comparator = 
		[](std::pair<char, std::uint8_t> p1, std::pair<char, std::uint8_t> p2) {
			return cards(p1.first) < cards(p2.first);
	};

	constexpr auto suit_check = [](char suit) {
		return (suit == 'S' || suit == 'H' || suit == 'D' || suit == 'C');
	};

	constexpr auto value_check = [](char value) {
		return (value == '2' || value == '3' || value == '4' || value == '5'
			|| value == '6' || value == '7' || value == '8' || value == '9'
			|| value == 'T' || value == 'J' || value == 'Q' || value == 'K'
			|| value == 'A');
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