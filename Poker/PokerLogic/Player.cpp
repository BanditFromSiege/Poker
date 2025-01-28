#include "Player.h"

Player::Player() noexcept = default;

Player::Player(Card c1, Card c2, std::uint32_t balance)
	: first(c1), second(c2), balance(balance) {}

std::pair<bool, bool> Player::getPowerHand() const noexcept {
	return { (first.Power() == second.Power()), (first.Suit() == second.Suit()) };
}

Card Player::getFirst() const noexcept { return first; }

Card Player::getSecond() const noexcept { return second; }

void Player::ChangeFirstCard(Card c) { first = c; }

void Player::ChangeSecondCard(Card c) { second = c; }

void Player::ChangeBalance(std::uint32_t b) { balance = b; }
