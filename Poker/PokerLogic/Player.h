#pragma once

#include "../ToolsClasses/RandomGenerator.h"

class Player {
private:
	Card first = {};
	Card second = {};
	std::uint32_t balance = 0;

public:
	Player() noexcept;
	Player(Card c1, Card c2, std::uint32_t balance);

	std::pair<bool, bool> getPowerHand() const noexcept;
	Card getFirst() const noexcept;
	Card getSecond() const noexcept;

	void ChangeFirstCard(Card c);
	void ChangeSecondCard(Card c);
	void ChangeBalance(std::uint32_t b);
};