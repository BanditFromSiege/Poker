#pragma once

#include "../PokerLogic/Player.h"
#include "../ToolsClasses/Stopwatch.h"

class ConsolePokerGame {
private:
	std::vector<Player> players = {};
	std::vector<Card> table = {};

	RandomGenerator rand;

	std::uint32_t bank = 0;
	std::uint32_t rounds = 1;
	
	std::uint32_t bigBlind = 50;
	std::uint8_t round_count = 0;

	std::uint8_t count_players = 6;

	std::uint8_t position_dealer = 0;
	std::uint8_t position_player = rand.getRandomNumber(0, count_players - 1);

	bool global_bet = true;

	std::unique_ptr<Tools::Type_of_hands> ptr_to_type_of_hands
		= std::make_unique<Tools::Type_of_hands>();

	void InitializationPlayers(std::uint32_t balance);
	void InitializationHands();

	void Check();
	void Call();
	void Bet(std::uint8_t i, std::uint32_t bet);
	bool Any_did_bet();
	void Fold(std::uint8_t i);

	void Gretings();
	void Preflop();
	void Flop();
	void Tern();
	void River();

public:
	ConsolePokerGame();
	ConsolePokerGame(std::uint8_t n);

	void Run();
};