#include "ConsolePokerGame.h"

ConsolePokerGame::ConsolePokerGame() = default;

ConsolePokerGame::ConsolePokerGame(std::uint8_t n) {
	if (!(n >= 2 && n <= 8)) { throw std::runtime_error("Error"); }
	count_players = n;
}

void ConsolePokerGame::InitializationPlayers(std::uint32_t balance) {
	for (std::uint8_t i = 0; i < count_players; ++i) {
		players.push_back({ "2H", "2D", balance });
		val_players_round.push_back(true);
		val_players_live.push_back(true);
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
		players[i].ChangeFirstCard(cards[count++]);
		players[i].ChangeSecondCard(cards[count++]);
		val_players_round[i] = true;
	}
	for (std::uint8_t i = 0; i < 5; ++i) {
		table.push_back(cards[count++]);
	}

	if (rounds != 1) { position_dealer = (++position_dealer) % count_players; }

	BigBlind = BigBlind * ((++round_count / 5) + 1);
}

void ConsolePokerGame::Check() {
	//TODO
}

void ConsolePokerGame::Call() {
	//TODO
}

void ConsolePokerGame::Bet() {
	//TODO
}

void ConsolePokerGame::Fold(std::uint8_t i) {
	val_players_round[i] = false;
	//TODO
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
	std::cout << "Blinds: " << BigBlind * 0.5 << ' ' << BigBlind << '\n';
	std::cout << "Dealer's place is " << int(position_dealer) << '\n';

	std::cout << "You have place by number: " << int(position_player) << '\n';

	if (position_dealer == position_player) {
		std::cout << "Congratulations! You are dealer" << '\n';
	}

	std::cout << "Press SPACE to continue..." << '\n';
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space));

	bool bet = false;

	for (std::uint8_t i = 0; i < players.size(); ++i) {
		std::cout << '\n';
		if (i != position_player && val_players_round[i] && val_players_live[i]) {
			std::cout << "Player number " << int(i + 1) << " moves" << '\n';
			Delay<milliseconds>(500);

			auto hand = players[i].getPowerHand();
			if (hand.first) {
				if (rand.Probability(60)) {
					//TODO
				}
				else if (rand.Probability(35)) {
					//TODO
				}
				else {
					//TODO
				}
			}
			else if (hand.second && (std::abs(Tools::cards.find(players[i].getFirst().Power())->second 
					- Tools::cards.find(players[i].getSecond().Power())->second) == 1))
			{
				if (rand.Probability(65)) {
					//TODO
				}
				else if (rand.Probability(15)) {
					//TODO
				}
				else {
					//TODO
				}
			}
			else {
				if (rand.Probability(4)) {
					//TODO
				}
				else if (rand.Probability(4)) {
					//TODO
				}
				else {
					//TODO
				}
			}
		}
		else if (val_players_round[i] && val_players_live[i]) {
			std::cout << "Choice you move: " << '\n';
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
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
		Flop();
		Tern();
		River();
	}
	//TODO
}