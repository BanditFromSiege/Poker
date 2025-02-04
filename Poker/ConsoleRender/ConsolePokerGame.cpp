#include "ConsolePokerGame.h"

ConsolePokerGame::ConsolePokerGame() = default;

ConsolePokerGame::ConsolePokerGame(std::uint8_t n) {
	if (!(n >= 2 && n <= 8)) {
		throw std::runtime_error("Error");
	}
	count_players = n;
}

void ConsolePokerGame::InitializationPlayers(std::uint16_t balance) {
	for (std::uint8_t i = 0; i < count_players; ++i) {
		players.push_back({ "2H", "2D", balance, 0, true, true});
	}
}

void ConsolePokerGame::InitializationHands() {
	static std::vector<Card> cards = {
		{'2','S'}, {'3','S'}, {'4','S'}, {'5','S'}, {'6','S'}, {'7','S'}, {'8','S'},
		{'9','S'}, {'T','S'}, {'J','S'}, {'Q','S'}, {'K','S'}, {'A','S'},
		{'2','H'}, {'3','H'}, {'4','H'}, {'5','H'}, {'6','H'}, {'7','H'}, {'8','H'},
		{'9','H'}, {'T','H'}, {'J','H'}, {'Q','H'}, {'K','H'}, {'A','H'},
		{'2','D'}, {'3','D'}, {'4','D'}, {'5','D'}, {'6','D'}, {'7','D'}, {'8','D'},
		{'9','D'}, {'T','D'}, {'J','D'}, {'Q','D'}, {'K','D'}, {'A','D'},
		{'2','C'}, {'3','C'}, {'4','C'}, {'5','C'}, {'6','C'}, {'7','C'}, {'8','C'},
		{'9','C'}, {'T','C'}, {'J','C'}, {'Q','C'}, {'K','C'}, {'A','C'}
	};

	rand.Shuffle(cards);

	std::uint8_t count = 0;
	for (std::uint8_t i = 0; i < count_players; ++i) {
		players[i].Change_First_Card(cards[count++]);
		players[i].Change_Second_Card(cards[count++]);
		players[i].Change_valid_in_round(true);
	}

	for (std::uint8_t i = 0; i < 5; ++i) {
		table.push_back(cards[count++]);
	}

	if (rounds == 1) {
		std::vector<std::uint8_t> index_of_valid_players;

		for (std::uint8_t i = 0; auto & player : players) {
			if (player.get_Valid_in_game()) {
				index_of_valid_players.push_back(i++);
			}
		}

		rand.Shuffle(index_of_valid_players);
		position_dealer = index_of_valid_players.front();
	}
	else {
		position_dealer = (++position_dealer) % count_players;
	}

	bigBlind = bigBlind * ((++round_count / 5) + 1);
}

bool ConsolePokerGame::everyone_did_bet() {
	bool result = true;
	for (auto& player : players) {
		if (player.get_Valid_in_round()) {
			result = (player.get_Bet() == max_bet);
		}
	}
	return result;
}

std::uint8_t ConsolePokerGame::players_in_round() {
	std::uint8_t count = 0;
	for (auto& player : players) {
		count += player.get_Valid_in_round();
	}
	return count;
}

void ConsolePokerGame::Check(std::uint8_t i) {
	std::cout << "Check: ";
	std::cout << "Player number " << int(i) + 1 << " maked call " << '\n';
}

void ConsolePokerGame::Call(std::uint8_t i) {
	std::cout << "Call: ";
	Bet(i, max_bet - players[i].get_Bet());
}

void ConsolePokerGame::Raise(std::uint8_t i, std::uint8_t multiply) {
	std::cout << "Raise: ";
	Bet(i, max_bet * multiply);
}

void ConsolePokerGame::Bet(std::uint8_t i, std::uint16_t bet) {
	if ((players[i].get_Balance() - bet) >= 0) {

		max_bet = std::max(bet, max_bet);
		players[i].Change_Bet(bet);
		players[i].Change_Balance(players[i].get_Balance() - bet);

		if (players[i].get_Balance() == 0) {
			std::cout << "Player number " << int(i) + 1 << " maked all - in " << bet << '\n';
		} else { 
			std::cout << "Player number " << int(i) + 1 << " maked bet in " << bet << '\n';
		}
	}
	else {
		//TODO
	}
}

void ConsolePokerGame::Fold(std::uint8_t i) {
	std::cout << "Fold: " << "Player number " << int(i) + 1 << " maked fold " << '\n';
	players[i].Change_valid_in_round(false);
}

void ConsolePokerGame::Gretings() {
	std::cout << "Welcome to Poker" << '\n';
	std::cout << "Press SPACE to continue..." << '\n';
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
}

void ConsolePokerGame::Preflop() {
	system("cls");
	InitializationHands();

	std::cout << "Round: " << rounds << '\n';
	std::cout << "Blinds: " << bigBlind * 0.5 << ' ' << bigBlind << '\n';
	std::cout << "Dealer's place is " << int(position_dealer) + 1 << '\n';

	std::cout << "You have place by number: " << int(position_player) + 1 << '\n';

	if (position_dealer == position_player) {
		std::cout << "Congratulations! You are dealer" << '\n' << '\n';
	}

	std::cout << "You cards " << players[position_player].get_First()
		<< ' ' << players[position_player].get_Second() << '\n';

	std::uint8_t index_little_blind = (position_dealer + 1) % count_players;
	std::uint8_t index_big_blind = (index_little_blind + 1) % count_players;

	Bet(index_little_blind, 0.5 * bigBlind);
	Bet(index_big_blind, bigBlind);

	std::cout << "Press SPACE to continue..." << '\n';
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space));

	for (std::uint8_t i = (index_big_blind + 1) % count_players; ; i = (i + 1) % count_players) {
		std::cout << '\n';
		
		//TODO
		auto count = players_in_round();

		if (count == 1 && i != position_player) {
			std::cout << "Player number " << i << "won" << '\n';
			players[i].Change_Balance(max_bet);
			max_bet = 0;
			end_game_on_preflop = true;
			std::cout << "Press SPACE to continue..." << '\n';
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
			break;
			//TODO
		}
		else if (count == 1) {
			std::cout << "Congratulations! You are won" << '\n';
			players[i].Change_Balance(max_bet);
			max_bet = 0;
			end_game_on_preflop = true;
			std::cout << "Press SPACE to continue..." << '\n';
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
			break;
			//TODO
		}

		if (i == index_big_blind && everyone_did_bet()) {
			std::cout << "Go to flop" << "\n";
			std::cout << "Press SPACE to continue..." << '\n';
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
			break;
			//TODO
		}

		if (i != position_player && players[i].get_Valid_in_round() && players[i].get_Valid_in_game()) {
			std::cout << "PLayers in round: " << (int)count << '\n';
			std::cout << "Player number " << int(i + 1) << " moves" << '\n';

			Delay<milliseconds>(500);

			Hand_of_cards hand({ players[i].get_First(), players[i].get_Second() });
			std::uint8_t power_hand = get_power_hand(*ptr_to_type_of_hands, hand);

			if (power_hand == 4) {
				//TODO
				if (players[i].get_Bet() < max_bet) {
					if (rand.Probability(45)) {
						Call(i);
					}
					else if (rand.Probability(50)) {
						std::uint8_t multiply = rand.getRandomNumber(2, 4);

						if (players[i].get_Balance() >= max_bet * multiply) {
							Raise(i, multiply);
						} else {
							Call(i);
						}
					}
					else {
						Fold(i);
					}
				}
				else {
					if (rand.Probability(35)) {
						Check(i);
					}
					else if (rand.Probability(60)) {
						std::uint8_t multiply = rand.getRandomNumber(2, 4);

						if (players[i].get_Balance() >= max_bet * multiply) {
							Raise(i, multiply);
						}
						else {
							Check(i);
						}
					}
					else {
						Fold(i);
					}
				}
			}

			else if (power_hand == 3) {
				//TODO
				if (players[i].get_Bet() < max_bet) {
					if (rand.Probability(60)) {
						Call(i);
					}
					else if (rand.Probability(30)) {
						std::uint8_t multiply = rand.getRandomNumber(2, 4);

						if (players[i].get_Balance() >= max_bet * multiply) {
							Raise(i, multiply);
						}
						else {
							Call(i);
						}
					}
					else {
						Fold(i);
					}
				}
				else {
					//TODO
					if (rand.Probability(70)) {
						Check(i);
					}
					else if (rand.Probability(25)) {
						std::uint8_t multiply = rand.getRandomNumber(2, 4);

						if (players[i].get_Balance() >= max_bet * multiply) {
							Raise(i, multiply);
						}
						else {
							Check(i);
						}
					}
					else {
						Fold(i);
					}
				}
			}

			else if (power_hand == 2) {
				//TODO
				if (players[i].get_Bet() < max_bet) {
					if (rand.Probability(65)) {
						Call(i);
					}
					else if (rand.Probability(30)) {
						std::uint8_t multiply = rand.getRandomNumber(2, 4);

						if (players[i].get_Balance() >= max_bet * multiply) {
							Raise(i, multiply);
						}
						else {
							Call(i);
						}
					}
					else {
						Fold(i);
					}
				}
				else {
					//TODO
					if (players[i].get_Bet() < max_bet) {
						if (rand.Probability(70)) {
							Check(i);
						}
						else if (rand.Probability(25)) {
							std::uint8_t multiply = rand.getRandomNumber(2, 4);

							if (players[i].get_Balance() >= max_bet * multiply) {
								Raise(i, multiply);
							}
							else {
								Check(i);
							}
						}
						else {
							Fold(i);
						}
					}
				}
			}

			else if (power_hand == 1) {
				//TODO
				if (players[i].get_Bet() < max_bet) {
					if (rand.Probability(70)) {
						Call(i);
					}
					else if (rand.Probability(5)) {
						std::uint8_t multiply = rand.getRandomNumber(2, 4);

						if (players[i].get_Balance() >= max_bet * multiply) {
							Raise(i, multiply);
						}
						else {
							Call(i);
						}
					}
					else {
						Fold(i);
					}
				}
				else {
					//TODO
					if (players[i].get_Bet() < max_bet) {
						if (rand.Probability(70)) {
							Check(i);
						}
						else if (rand.Probability(10)) {
							std::uint8_t multiply = rand.getRandomNumber(2, 4);

							if (players[i].get_Balance() >= max_bet * multiply) {
								Raise(i, multiply);
							}
							else {
								Check(i);
							}
						}
						else {
							Fold(i);
						}
					}
				}
			}

			else {
				//TODO
				if (players[i].get_Bet() < max_bet) {
					if (rand.Probability(10)) {
						Call(i);
					}
					else if (rand.Probability(5)) {
						std::uint8_t multiply = rand.getRandomNumber(2, 4);

						if (players[i].get_Balance() >= max_bet * multiply) {
							Raise(i, multiply);
						}
						else {
							Call(i);
						}
					}
					else {
						Fold(i);
					}
				}
				else {
					//TODO
					if (rand.Probability(20)) {
						Check(i);
					}
					else if (rand.Probability(5)) {
						std::uint8_t multiply = rand.getRandomNumber(2, 4);

						if (players[i].get_Balance() >= max_bet * multiply) {
							Raise(i, multiply);
						}
						else {
							Check(i);
						}
					}
					else {
						Fold(i);
					}
				}
			}
		}

		else if (players[i].get_Valid_in_round() && players[i].get_Valid_in_game()) {
			std::cout << "Choice you move: " << '\n';
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
			//TODO
		}

	}
	//TODO
}

void ConsolePokerGame::Flop() {
	//TODO
}

void ConsolePokerGame::Tern() {
	//TODO
}

void ConsolePokerGame::River() {
	//TODO
}

void ConsolePokerGame::Run() {
	Gretings();
	InitializationPlayers(5000);
	while (players.size() > 1) {
		Preflop();
		if (!end_game_on_preflop) {
			Flop();
			Tern();
			River();
		}
	}
	//TODO
}