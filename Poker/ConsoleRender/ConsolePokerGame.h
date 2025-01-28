#pragma once

#include "../PokerLogic/Player.h"

class ConsolePokerGame {
private:
	std::vector<Player> players = {};
	std::vector<Card> table = {};
	std::vector<bool> val_players_round = {};
	std::vector<bool> val_players_live = {};

	RandomGenerator rand;

	std::uint32_t bank = 0;
	std::uint32_t rounds = 1;
	
	std::uint16_t BigBlind = 50;
	std::uint8_t round_count = 0;

	std::uint8_t count_players = 6;

	std::uint8_t position_dealer = 0;
	std::uint8_t position_player = rand.getRandomNumber(0, count_players - 1);

	void InitializationPlayers(std::uint32_t balance);
	void InitializationHands();

	void Check();
	void Call();
	void Bet();
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