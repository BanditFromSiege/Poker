#include "Card.h"

Card::Card() noexcept = default;

Card::Card(char power, char suit) : power(std::toupper(power)), suit(std::toupper(suit)) {
	Tools::cards(std::toupper(power));
	if (!Tools::suit_check(std::toupper(suit))) {
		throw std::runtime_error("Uncorrected values for initialization card");
	}
}

Card::Card(const std::string& str) : Card::Card(str[0], str[1]) {
	if (str.size() != 2) { 
		throw std::runtime_error("Uncorrected values for initialization card");
	}
}

Card::Card(const char* str) : Card::Card(std::string(str)) {}

char Card::Power() const noexcept {
	return power;
}

char Card::Suit() const noexcept {
	return suit;
}

bool operator<(Card c1, Card c2) noexcept {
	return Tools::cards(c1.Power()) < Tools::cards(c2.Power());
}

bool operator>(Card c1, Card c2) noexcept { 
	return c2 < c1;
}

bool operator==(Card c1, Card c2) noexcept {
	return !(c1 < c2) && !(c2 < c1);
}

bool operator!=(Card c1, Card c2) noexcept {
	return !(c1 == c2);
}

bool operator<=(Card c1, Card c2) noexcept {
	return !(c2 < c1);
}

bool operator>=(Card c1, Card c2) noexcept {
	return c2 <= c1;
}

std::ostream& operator<<(std::ostream& out, Card c) {
	out << c.Power() << c.Suit();
	return out;
}