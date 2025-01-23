#include "Card.h"

Card::Card() noexcept = default;

Card::Card(char power, char suit) : power(std::toupper(power)), suit(std::toupper(suit)) {
	if (!Tools::cards.contains(std::toupper(power)) || !Tools::suit_check(std::toupper(suit))) {
		throw std::runtime_error("Uncorrected values for initialization card");
	}
}

char Card::Power() const noexcept { return power; }

char Card::Suit() const noexcept { return suit; }

bool operator<(Card c1, Card c2) noexcept {
	return Tools::cards.find(c1.Power())->second < Tools::cards.find(c2.Power())->second;
}

bool operator>(Card c1, Card c2) noexcept { return c2 < c1; }
bool operator==(Card c1, Card c2) noexcept { return !(c1 < c2) && !(c2 < c1); }
bool operator!=(Card c1, Card c2) noexcept { return !(c1 == c2); }
bool operator<=(Card c1, Card c2) noexcept { return !(c2 < c1); }
bool operator>=(Card c1, Card c2) noexcept { return c2 <= c1; }

std::ostream& operator<<(std::ostream& out, Card c) {
	out << c.Power() << c.Suit();
	return out;
}
