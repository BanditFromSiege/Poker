#include "Player.h"

Player::Player() noexcept = default;

Player::Player
	(	
		Card c1, 
		Card c2,
		std::uint16_t balance,
		std::uint16_t bet,
		bool valid_in_game,
		bool valid_in_round
	) 
	: first(c1), second(c2), balance(balance), bet(bet), valid_in_game(valid_in_game), 
	valid_in_round(valid_in_round) {}

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

std::uint16_t Player::get_Balance() const noexcept {
	return balance;
}

std::uint16_t Player::get_Bet() const noexcept {
	return bet;
}

bool Player::get_Valid_in_game() const noexcept {
	return valid_in_game;
}

bool Player::get_Valid_in_round() const noexcept {
	return valid_in_round;
}

void Player::Change_First_Card(Card new_card) noexcept {
	first = new_card;
}

void Player::Change_Second_Card(Card new_card) noexcept {
	second = new_card;
}

void Player::Change_Balance(std::uint16_t new_balance) noexcept {
	balance = new_balance;
}

void Player::Change_Bet(std::uint16_t new_bet) noexcept {
	bet = new_bet;
}

void Player::Change_valid_in_game(bool new_valid_in_game) noexcept {
	valid_in_game = new_valid_in_game;
}

void Player::Change_valid_in_round(bool new_valid_in_round) noexcept {
	valid_in_round = new_valid_in_round;
}
