#include "Hand_of_cards.h"

Hand_of_cards::Hand_of_cards(char card1, char card2, bool suit_equal)
	: card1(card1), card2(card2), suit_equal(suit_equal) {}

Hand_of_cards::Hand_of_cards(Card other_card1, Card other_card2) {
	card1 = (other_card1 < other_card2) ? other_card2.Power() : other_card1.Power();
	card1 = (other_card1 < other_card2) ? other_card1.Power() : other_card2.Power();
	suit_equal = (other_card1.Suit() == other_card2.Suit());
}

bool operator==(Hand_of_cards hand1, Hand_of_cards hand2) {
	if (hand1.card1 == hand2.card1) {
		if (hand1.card2 == hand2.card2) {
			return (hand1.card1 != hand2.card1) ? hand1.suit_equal == hand2.suit_equal : true;
		}
		return false;
	}
	return false;
}

namespace Tools {
	std::uint8_t Get_hand_category(const Type_of_hands& type, Hand_of_cards hand) {
		return (type.premium.set.contains(hand) * 4
			+ type.high.set.contains(hand) * 3
			+ type.medium.set.contains(hand) * 2
			+ type.low.set.contains(hand) * 1);
	}
};