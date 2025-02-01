#include "Player.h"

Player::Player() noexcept = default;

Player::Player(Card c1, Card c2, std::uint32_t balance, bool valid_in_game, bool valid_in_round, bool bet_check)
	: first(c1), second(c2), balance(balance), valid_in_game(valid_in_game), 
	valid_in_round(valid_in_round), bet_check(bet_check)
{}

std::pair<bool, bool> Player::get_PowerHand() const noexcept {
	return { 
		(first.Power() == second.Power()), (first.Suit() == second.Suit())
	};
}

Card Player::get_First() const noexcept { 
	return first;
}

Card Player::get_Second() const noexcept { 
	return second;
}

std::uint32_t Player::get_Balance() const noexcept {
	return balance;
}

bool Player::get_Valid_in_game() const noexcept {
	return valid_in_game;
}

bool Player::get_Valid_in_round() const noexcept {
	return valid_in_round;
}

bool Player::get_Bet_check() const noexcept {
	return bet_check;
}

void Player::Change_First_Card(Card new_card) noexcept {
	first = new_card;
}

void Player::Change_Second_Card(Card new_card) noexcept {
	second = new_card;
}

void Player::Change_Balance(std::uint32_t new_balance) noexcept {
	balance = new_balance;
}

void Player::Change_valid_in_game(bool new_valid_in_game) noexcept {
	valid_in_game = new_valid_in_game;
}

void Player::Change_valid_in_round(bool new_valid_in_round) noexcept {
	valid_in_round = new_valid_in_round;
}

void Player::Change_bet_check(bool new_bet_check) noexcept {
	bet_check = new_bet_check;
}
