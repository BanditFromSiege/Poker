#pragma once

#include "../ToolsClasses/RandomGenerator.h"

class Player {
private:
	Card first = {};
	Card second = {};

	std::uint32_t balance = 0;

	bool valid_in_game = true;
	bool valid_in_round = false;
	bool bet_check = true;

public:
	Player() noexcept;
	Player(Card c1, Card c2, std::uint32_t balance, bool valid_in_game, bool valid_in_round, bool bet_check);

	std::pair<bool, bool> get_PowerHand() const noexcept;
	Card get_First() const noexcept;
	Card get_Second() const noexcept;
	std::uint32_t get_Balance() const noexcept;
	bool get_Valid_in_game() const noexcept;
	bool get_Valid_in_round() const noexcept;
	bool get_Bet_check() const noexcept;

	void Change_First_Card(Card new_card) noexcept;
	void Change_Second_Card(Card new_card) noexcept;
	void Change_Balance(std::uint32_t new_balance) noexcept;
	void Change_valid_in_game(bool new_valid_in_game) noexcept;
	void Change_valid_in_round(bool new_valid_in_round) noexcept;
	void Change_bet_check(bool new_bet_check) noexcept;
};