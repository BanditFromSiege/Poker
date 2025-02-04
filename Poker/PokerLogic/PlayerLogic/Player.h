#pragma once

#include "../../ToolsClasses/RandomGenerator.h"

class Player {
private:
	Card first = {};
	Card second = {};

	std::uint16_t balance = 0;
	std::uint16_t bet = 0;

	bool valid_in_game = true;
	bool valid_in_round = false;

public:
	Player() noexcept;
	Player(
		Card c1,
		Card c2,
		std::uint16_t balance,
		std::uint16_t bet,
		bool valid_in_game,
		bool valid_in_round
	);

	std::pair<bool, bool> get_PowerHand() const noexcept;

	Card get_First() const noexcept;
	Card get_Second() const noexcept;

	std::uint16_t get_Balance() const noexcept;
	std::uint16_t get_Bet() const noexcept;

	bool get_Valid_in_game() const noexcept;
	bool get_Valid_in_round() const noexcept;

	void Change_First_Card(Card new_card) noexcept;
	void Change_Second_Card(Card new_card) noexcept;
	void Change_Balance(std::uint16_t new_balance) noexcept;
	void Change_Bet(std::uint16_t new_bet) noexcept;
	void Change_valid_in_game(bool new_valid_in_game) noexcept;
	void Change_valid_in_round(bool new_valid_in_round) noexcept;
};