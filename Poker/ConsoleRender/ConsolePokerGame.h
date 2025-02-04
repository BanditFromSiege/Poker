#pragma once

#include "../PokerLogic/PlayerLogic/Player.h"
#include "../ToolsClasses/Stopwatch.h"

class ConsolePokerGame {
private:
	std::vector<Player> players = {};
	std::vector<Card> table = {};

	RandomGenerator rand;

	std::uint32_t pot = 0;
	std::uint32_t rounds = 1;
	
	std::uint16_t bigBlind = 50;
	std::uint16_t max_bet = 0;

	std::uint8_t round_count = 0;

	std::uint8_t count_players = 6;
	std::uint8_t position_dealer = 0;
	std::uint8_t position_player = rand.getRandomNumber(0, count_players - 1);

	std::unique_ptr<Tools::Type_of_hands> ptr_to_type_of_hands
		= std::make_unique<Tools::Type_of_hands>();

	bool end_game_on_preflop = false;

	void InitializationPlayers(std::uint16_t balance);
	void InitializationHands();

	bool everyone_did_bet();
	std::uint8_t players_in_round();

	void Check(std::uint8_t i);
	void Call(std::uint8_t i);
	void Raise(std::uint8_t i, std::uint8_t multiply);

	void Bet(std::uint8_t i, std::uint16_t bet);
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