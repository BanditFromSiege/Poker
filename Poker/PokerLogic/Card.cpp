#include "../PokerLogic/Card.h"

Card::Card() noexcept = default;

Card::Card(char power, char suit) : power(std::toupper(power)), suit(std::toupper(suit)) {
	if (!Tools::cards.contains(std::toupper(power)) || !Tools::suit_check(std::toupper(suit))) {
		throw std::runtime_error("Uncorrected values for initialization card");
	}
}

Card::Card(const std::string& str) : Card::Card(str[0], str[1]) {
	if (str.size() != 2) { throw std::runtime_error("Uncorrected values for initialization card"); }
}

Card::Card(const char* str) : Card::Card(std::string(str)) {}

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

namespace Tools {
	Hand_of_cards::Hand_of_cards(char c1, char c2, bool suit_equal)
		: c1(c1), c2(c2), suit_equal(suit_equal) {}

	Hand_of_cards::Hand_of_cards(Card cd1, Card cd2) {
		c1 = (cd1 < cd2) ? cd2.Power() : cd1.Power();
		c2 = (cd1 < cd2) ? cd1.Power() : cd2.Power();
		suit_equal = (cd1.Suit() == cd2.Suit());
	}

	bool operator==(Hand_of_cards hand1, Hand_of_cards hand2) {
		if (hand1.c1 == hand2.c1) {
			if (hand1.c2 == hand2.c2) {
				return (hand1.c1 != hand2.c1) ? hand1.suit_equal == hand2.suit_equal : true;
			}
			return false;
		}
		return false;
	}

	std::uint8_t get_power_hand(const Type_of_hands& check, Hand_of_cards hand) {
		if (check.premium.set.contains(hand)) {
			return 4;
		}
		else if (check.high.set.contains(hand)) {
			return 3;
		}
		else if (check.medium.set.contains(hand)) {
			return 2;
		}
		else if (check.low.set.contains(hand)) {
			return 1;
		}
		return 0;
	}
};