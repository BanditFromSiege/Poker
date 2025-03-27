#include "ConsoleRender/ConsolePokerGame.h"

namespace Tests {
	void Test_check_combination_of_cards() {
		std::vector<std::vector<Card>> cards = {
			{ {'Q','S'},{'J','C'},{'3','D'},{'5','H'},{'8','D'} },
			{ {'A','D'},{'A','H'},{'6','D'},{'7','S'},{'J','S'} },
			{ {'A','D'},{'A','H'},{'5','S'},{'5','C'},{'3','D'} },
			{ {'8','S'},{'8','C'},{'8','D'},{'6','D'},{'K','S'} },
			{ {'7','S'},{'8','C'},{'9','D'},{'T','H'},{'J','D'} },
			{ {'A','C'},{'J','C'},{'7','C'},{'4','C'},{'2','C'} },
			{ {'8','S'},{'8','C'},{'A','D'},{'A','H'},{'A','D'} },
			{ {'5','S'},{'5','C'},{'5','D'},{'5','H'},{'J','D'} },
			{ {'7','D'},{'8','D'},{'9','D'},{'T','D'},{'J','D'} },
			{ {'A','D'},{'K','D'},{'Q','D'},{'J','D'},{'T','D'} }
		};

		for (std::vector<Card>& vector_of_cards : cards) {
			for (Card c : vector_of_cards) {
				std::cout << c << ' ';
			}
			std::cout << '\n';

			CardCombination combination = { vector_of_cards };
			combination.ShowCombination();
			std::cout << '\n';
		}
	}

	void Test_distribution_of_five_comb_cards(int number_of_ñard_shuffles) {
		std::vector<Card> cards = {
			{'2','S'}, {'3','S'}, {'4','S'}, {'5','S'}, {'6','S'}, {'7','S'}, {'8','S'},
			{'9','S'}, {'T','S'}, {'J','S'}, {'Q','S'}, {'K','S'}, {'A','S'},
			{'2','H'}, {'3','H'}, {'4','H'}, {'5','H'}, {'6','H'}, {'7','H'}, {'8','H'},
			{'9','H'}, {'T','H'}, {'J','H'}, {'Q','H'}, {'K','H'}, {'A','H'},
			{'2','D'}, {'3','D'}, {'4','D'}, {'5','D'}, {'6','D'}, {'7','D'}, {'8','D'},
			{'9','D'}, {'T','D'}, {'J','D'}, {'Q','D'}, {'K','D'}, {'A','D'},
			{'2','C'}, {'3','C'}, {'4','C'}, {'5','C'}, {'6','C'}, {'7','C'}, {'8','C'},
			{'9','C'}, {'T','C'}, {'J','C'}, {'Q','C'}, {'K','C'}, {'A','C'}
		};

		std::random_device random_device;
		auto ptr_to_rand_engine = std::make_unique<std::mt19937>(random_device());

		std::vector<Card> cards_of_combinations;
		cards_of_combinations.reserve(5);

		std::unordered_map<Poker::Combination, int> un_map_of_combinations;
		for (int i = 0; i < number_of_ñard_shuffles; ++i) {
			std::sample(cards.begin(), cards.end(),
				std::back_inserter(cards_of_combinations), 5, *ptr_to_rand_engine);

			CardCombination hand(cards_of_combinations);
			++un_map_of_combinations[hand.GetPower()];

			cards_of_combinations.clear();
		}

		std::vector<std::pair<Poker::Combination, int>> 
			vector_of_buckets(un_map_of_combinations.begin(), un_map_of_combinations.end());

		std::sort(vector_of_buckets.begin(), vector_of_buckets.end());

		for (auto [combination, count] : vector_of_buckets) {
			std::cout << combination << ": " << count << '\n';
		}
		std::cout << '\n';
	}

	void Test_distribution_of_seven_comb_cards(int number_of_ñard_shuffles) {
		std::vector<Card> cards = {
			{'2','S'}, {'3','S'}, {'4','S'}, {'5','S'}, {'6','S'}, {'7','S'}, {'8','S'},
			{'9','S'}, {'T','S'}, {'J','S'}, {'Q','S'}, {'K','S'}, {'A','S'},
			{'2','H'}, {'3','H'}, {'4','H'}, {'5','H'}, {'6','H'}, {'7','H'}, {'8','H'},
			{'9','H'}, {'T','H'}, {'J','H'}, {'Q','H'}, {'K','H'}, {'A','H'},
			{'2','D'}, {'3','D'}, {'4','D'}, {'5','D'}, {'6','D'}, {'7','D'}, {'8','D'},
			{'9','D'}, {'T','D'}, {'J','D'}, {'Q','D'}, {'K','D'}, {'A','D'},
			{'2','C'}, {'3','C'}, {'4','C'}, {'5','C'}, {'6','C'}, {'7','C'}, {'8','C'},
			{'9','C'}, {'T','C'}, {'J','C'}, {'Q','C'}, {'K','C'}, {'A','C'}
		};

		std::random_device g;
		auto ptr_to_rand_engine = std::make_unique<std::mt19937>(g());

		std::vector<Card> cards_of_combinations;
		cards_of_combinations.reserve(7);

		std::unordered_map<Poker::Combination, int> un_map_of_combinations;
		for (int i = 0; i < number_of_ñard_shuffles; ++i) {
			std::sample(cards.begin(), cards.end(), 
				std::back_inserter(cards_of_combinations), 7, *ptr_to_rand_engine);

			CardCombination hand(cards_of_combinations);
			++un_map_of_combinations[hand.GetPower()];
			/*
			if (hand.getPower() >= Poker::Combination::Care) {
				std::cout << "Table cards: ";
				for (std::uint8_t i = 0; i < 5; ++i) {
					std::cout << cards_of_combinations[i] << ' ';
				}
				std::cout << '\n' << "Hand cards: ";
				for (std::uint8_t i = 5; i < 7; ++i) {
					std::cout << cards_of_combinations[i] << ' ';
				}
				std::cout << '\n';
				hand.ShowCombination();
				std::cout << '\n';
			}
			*/
			cards_of_combinations.clear();
		}

		std::vector<std::pair<Poker::Combination, int>>
			vector_of_buckets(un_map_of_combinations.begin(), un_map_of_combinations.end());

		std::sort(vector_of_buckets.begin(), vector_of_buckets.end());

		for (auto [combination, count] : vector_of_buckets) {
			std::cout << combination << ": " << count << '\n';
		}
		std::cout << '\n';
	}

	void Test_of_stopwatch() {
		Stopwatch stopwatch;
		std::size_t mid = 0;
		std::size_t diff = 0;

		for (int i = 0; i < 10; ++i) {
			stopwatch.SetBeginPoint();
			Delay(1);
			stopwatch.SetEndPoint();

			std::size_t time = stopwatch.GetTime();

			mid += time;
			diff += time - 1000000;
			std::cout << i + 1 << ": " << time << ' ' << time - 1000000 << ' ';
			stopwatch.ShowType();
		}

		mid /= 10;
		std::cout << mid << ' ';
		stopwatch.ShowType();
		std::cout << diff << ' ';
		stopwatch.ShowType();
	}

	void Test_wallpapper() {
		sf::Texture wallpapper;
		wallpapper.loadFromFile("Textures\\TableNew.png");

		sf::Sprite sprite_of_wallpapper(wallpapper);

		sf::RenderWindow window(sf::VideoMode(1920, 1080), "Poker", sf::Style::Fullscreen);

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || (event.KeyPressed && event.key.code == sf::Keyboard::Escape)) {
					window.close();
				}
			}

			window.clear();
			window.draw(sprite_of_wallpapper);
			window.display();
		}
	}

	void Unit_tests_five_card() {
		auto run_test = [](const char* player, const char* opponent, Poker::Result outcome) -> bool {
			return Poker::compare_combinations(CardCombination(player), CardCombination(opponent)) == outcome;
		};

		assert(run_test("2H 3H 4H 5H 6H", "KS AS TS QS JS", Poker::Result::Loss));
		assert(run_test("2H 3H 4H 5H 6H", "AS AD AC AH JD", Poker::Result::Win));
		assert(run_test("AS AH 2H AD AC", "JS JD JC JH 3D", Poker::Result::Win));
		assert(run_test("2S AH 2H AS AC", "JS JD JC JH AD", Poker::Result::Loss));
		assert(run_test("2S AH 2H AS AC", "2H 3H 5H 6H 7H", Poker::Result::Win));
		assert(run_test("AS 3S 4S 8S 2S", "2H 3H 5H 6H 7H", Poker::Result::Win));
		assert(run_test("2H 3H 5H 6H 7H", "2S 3H 4H 5S 6C", Poker::Result::Win));
		assert(run_test("2S 3H 4H 5S 6C", "3D 4C 5H 6H 2S", Poker::Result::Draw));
		assert(run_test("2S 3H 4H 5S 6C", "AH AC 5H 6H AS", Poker::Result::Win));
		assert(run_test("2S 3H 4H 5S AC", "AH AC 5H 6H AS", Poker::Result::Win));
		assert(run_test("2S 2H 4H 5S 4C", "AH AC 5H 6H AS", Poker::Result::Loss));
		assert(run_test("2S 2H 4H 5S 4C", "AH AC 5H 6H 7S", Poker::Result::Win));
		assert(run_test("6S AD 7H 4S AS", "AH AC 5H 6H 7S", Poker::Result::Loss));
		assert(run_test("2S AH 4H 5S KC", "AH AC 5H 6H 7S", Poker::Result::Loss));
		assert(run_test("2S 3H 6H 7S 9C", "7H 3C TH 6H 9S", Poker::Result::Loss));
		assert(run_test("4S 5H 6H TS AC", "3S 5H 6H TS AC", Poker::Result::Win));
		assert(run_test("2S AH 4H 5S 6C", "AD 4C 5H 6H 2C", Poker::Result::Draw));

		assert(run_test("KC KD KH QS QD", "KS KC KH QC QH", Poker::Result::Draw));
		assert(run_test("AS 5H 4S 3C 2D", "AS 2S 3S QS KS", Poker::Result::Loss));
		assert(run_test("AD 2D JD QD KD", "AC TC JC QC KC", Poker::Result::Loss));
		assert(run_test("AS TS JS QS KS", "AD TD JD QD KD", Poker::Result::Draw));
		assert(run_test("AH 2S 3S 4H KS", "9D TC JC QD KD", Poker::Result::Loss));

		assert(run_test("AH AS 2D 7S 9S", "AD AH 2H 7C 9C", Poker::Result::Draw));

		assert(run_test("AH TD 9H AS 9H", "AH KD 5H AS 5H", Poker::Result::Win));
		assert(run_test("AH 9D 9H AS 9H", "AH 5D 5H AS 5H", Poker::Result::Win));
	}

	void Unit_tests_six_card() {
		auto run_test = [](const char* player, const char* opponent, Poker::Result outcome) -> bool {
			return Poker::compare_combinations(CardCombination(player), CardCombination(opponent)) == outcome;
		};

		assert(run_test("8S 3S TC 7H AH KS", "8S 3S TC 7H QC TH", Poker::Result::Loss));
		assert(run_test("KS QH AC QS TD QD", "KS QH AC QS QC 9H", Poker::Result::Draw));
		assert(run_test("5S 9D AC KH QS 9C", "5S 9D AC KH 9H TH", Poker::Result::Win));
		assert(run_test("5D 8S TD 7H KS 2S", "5D 8S TD 7H 2H JC", Poker::Result::Win));
		assert(run_test("9D 9H 9S 9C AS 2H", "9D 9H 9S 9C JH JC", Poker::Result::Win));
		assert(run_test("KD QH TS 3C JS 7H", "KD QH TS 3C JD 9C", Poker::Result::Loss));
		assert(run_test("KD QH TS JC AH 4H", "KD QH TS JC AD 6H", Poker::Result::Draw));
		assert(run_test("4C 2D 7S 7D 9S 7C", "4C 2D 7S 7D 7H 6D", Poker::Result::Win));
		assert(run_test("8S 3D 4H 7C QH TH", "8S 3D 4H 7C JC 9D", Poker::Result::Win));
		assert(run_test("6S 3S AC KH QS 7D", "6S 3S AC KH JH TC", Poker::Result::Win));
	}

	void Unit_tests_seven_card() {
		auto run_test = [](const char* player, const char* opponent, Poker::Result outcome) -> bool {
			return Poker::compare_combinations(CardCombination(player), CardCombination(opponent)) == outcome;
		};

		assert(run_test("8S 3S TC 7H AH KS TD", "8S 3S TC 7H AH QC TH", Poker::Result::Win));
		assert(run_test("KS QH AC QS 5S TD QD", "KS QH AC QS 5S QC 9H", Poker::Result::Draw));
		assert(run_test("5S 9D AC KH 4S QS 9C", "5S 9D AC KH 4S 9H TH", Poker::Result::Win));
		assert(run_test("5D 8S TD 7H 2C KS 2S", "5D 8S TD 7H 2C 2H JC", Poker::Result::Win));
		assert(run_test("9D 9H 9S 9C 3H AS 2H", "9D 9H 9S 9C 3H JH JC", Poker::Result::Win));
		assert(run_test("KD QH TS 3C AH JS 7H", "KD QH TS 3C AH JD 9C", Poker::Result::Draw));
		assert(run_test("KD QH TS JC AH 4S 4H", "KD QH TS JC AH 6S 6H", Poker::Result::Draw));
		assert(run_test("4C 2D 7S 7D JC 9S 7C", "4C 2D 7S 7D JC 7H 6D", Poker::Result::Win));
		assert(run_test("8S 3D 4H 7C 2S QH TH", "8S 3D 4H 7C 2S JC 9D", Poker::Result::Win));
		assert(run_test("6S 3S AC KH 9H QS 7D", "6S 3S AC KH 9H JH TC", Poker::Result::Win));
	}

	void Test_distribution_probabilty(int number_of_ñard_shuffles = 5, bool show = true) {
		std::vector<Card> cards = {
			{'2','S'}, {'3','S'}, {'4','S'}, {'5','S'}, {'6','S'}, {'7','S'}, {'8','S'},
			{'9','S'}, {'T','S'}, {'J','S'}, {'Q','S'}, {'K','S'}, {'A','S'},
			{'2','H'}, {'3','H'}, {'4','H'}, {'5','H'}, {'6','H'}, {'7','H'}, {'8','H'},
			{'9','H'}, {'T','H'}, {'J','H'}, {'Q','H'}, {'K','H'}, {'A','H'},
			{'2','D'}, {'3','D'}, {'4','D'}, {'5','D'}, {'6','D'}, {'7','D'}, {'8','D'},
			{'9','D'}, {'T','D'}, {'J','D'}, {'Q','D'}, {'K','D'}, {'A','D'},
			{'2','C'}, {'3','C'}, {'4','C'}, {'5','C'}, {'6','C'}, {'7','C'}, {'8','C'},
			{'9','C'}, {'T','C'}, {'J','C'}, {'Q','C'}, {'K','C'}, {'A','C'}
		};

		std::random_device random_device;
		auto ptr_to_rand_engine = std::make_unique<std::mt19937>(random_device());

		std::vector<Card> cards_of_combinations;
		cards_of_combinations.reserve(5);

		for (int i = 0; i < number_of_ñard_shuffles; ++i) {
			std::shuffle(cards.begin(), cards.end(), *ptr_to_rand_engine);

			for (int j = 0; j < 5; ++j) {
				cards_of_combinations.push_back(cards[j]);
			}

			CardCombination comb(cards_of_combinations);
			auto array_of_probability = Poker::Find_Probability(cards_of_combinations);

			if (show && comb.GetPower() >= Poker::Combination::High_card) {
				for (Card c : cards_of_combinations) {
					std::cout << c << ' ';
				}
				std::cout << '\n';
				comb.ShowCombination();
				std::cout << '\n';

				std::cout << "Tern" << '\t' << " River" << '\t' << " Tern or River" << '\t' << " Combination" << '\n' << '\n';
				for (auto [x, y, z, c] : array_of_probability) {
					if (c != Poker::Combination::High_card) {
						std::cout << std::round(x * 100 * 100) / 100
							<< "%\t" << std::round(y * 100 * 100) / 100 << "%\t"
							<< std::round(z * 100 * 100) / 100 << "%\t" << '\t' << c << '\n' << '\n';
					}
				}
				std::cout << '\n';
			}

			cards_of_combinations.clear();
		}
	}

	void Test_find_probability(const std::span<Card>& vector_of_cards) {
		//"7S", "8S", "9S", "TS", "KD"
		//"7S", "8S", "9S", "TS", "KS"
		//"TC", "QC", "6S", "7D", "2D" 
		//"KS", "4S", "3S", "3C", "3H"

		//"3H", "5D", "6D", "9S", "TD"
		//"AH", "TD", "9H", "2S", "KH"
		//"8H", "8C", "9H", "TH", "AH"
		//"7H", "5D", "8D", "9D", "TD"
		//"7H", "AD", "8D", "9D", "TD"
		//"7H", "AD", "8D", "9D", "QD"
		//"7H", "2D", "3D", "4C", "5D"
		//"7H", "2D", "2H", "2C", "5H"

		//"3D", "4D", "6S", "7D", "6H"
		//"TD", "KD", "AD", "QD", "5H"

		for (Card card : vector_of_cards) {
			std::cout << card << ' ';
		}
		std::cout << '\n';

		CardCombination card(vector_of_cards);

		card.ShowCombination();
		std::cout << '\n';

		auto array = Poker::Find_Probability(vector_of_cards);

		std::cout << "Tern" << '\t' << " River" << '\t' << " Tern or River" << '\t' << " Combination" << '\n' << '\n';
		for (auto [x, y, z, c] : array) {
			if (c != Poker::Combination::High_card) {
				std::cout << std::round(x * 100 * 100) / 100
					<< "%\t" << std::round(y * 100 * 100) / 100 << "%\t"
					<< std::round(z * 100 * 100) / 100 << "%\t" << '\t' << c << '\n' << '\n';
			}
		}
	}

	void Test_combination_predictor() {
		auto check_card = [](const std::string& card) {
			return (card.size() == 2 && Tools::suit_check(std::toupper(card.back()))
				&& Tools::value_check(std::toupper(card.front())));
		};

		std::string card;

		std::array<std::string, 5> cards;

		std::cout << "Enter your hand cards: " << '\n';

		for (;;) {
			std::cout << "1: ";
			std::cin >> card;
			if (check_card(card)) {
				cards[0] = { card };
				break;
			} else {
				std::cout << "Invalid card input, please try gain..." << '\n';
			}
		}

		for (;;) {
			std::cout << "2: ";
			std::cin >> card;
			if (check_card(card)) {
				if (cards[0] != card) {
					cards[1] = { card };
					break;
				}
				else {
					std::cout << "Entering identical cards, please try gain..." << '\n';
				}
			}
			else {
				std::cout << "Invalid card input, please try gain..." << '\n';
			}
		}

		std::cout << '\n' << "Enter cards that are on the table: " << '\n';

		for (;;) {
			std::cout << "1: ";
			std::cin >> card;
			if (check_card(card)) {
				if (cards[0] != card && cards[1] != card) {
					cards[2] = { card };
					break;
				}
				else {
					std::cout << "Entering identical cards, please try gain..." << '\n';
				}
			}
			else {
				std::cout << "Invalid card input, please try gain..." << '\n';
			}
		}

		for (;;) {
			std::cout << "2: ";
			std::cin >> card;
			if (check_card(card)) {
				if (cards[0] != card && cards[1] != card && cards[2] != card) {
					cards[3] = { card };
					break;
				}
				else {
					std::cout << "Entering identical cards, please try gain..." << '\n';
				}
			}
			else {
				std::cout << "Invalid card input, please try gain..." << '\n';
			}
		}

		for (;;) {
			std::cout << "3: ";
			std::cin >> card;
			if (check_card(card)) {
				if (cards[0] != card && cards[1] != card && cards[2] != card
					&& cards[3] != card) 
				{
					cards[4] = { card };
					break;
				}
				else {
					std::cout << "Entering identical cards, please try gain..." << '\n';
				}
			}
			else {
				std::cout << "Invalid card input, please try gain..." << '\n';
			}
		}

		std::array<Card, 5> correct_cards = {};

		for (std::uint8_t i = 0; auto & str : cards) {
			correct_cards[i++] = str;
		}

		std::cout << '\n';
		std::cout << "Your cards: " << correct_cards[0] << ' ' << correct_cards[1] << '\n';
		std::cout << "Table cards: " << correct_cards[2] << ' ' << correct_cards[3] << ' ' << correct_cards[4] << '\n';

		CardCombination comb = { correct_cards };
		std::cout << '\n' << "Current combination: ";
		comb.ShowCombination();
		std::cout << '\n' << "Probabilities for stronger combinations: " << '\n' << '\n';

		auto array_of_probability = Poker::Find_Probability(correct_cards);

		std::cout << "Tern" << '\t' << " River" << '\t' << " Tern or River" << '\t' << " Combination" << '\n' << '\n';
		for (auto [x, y, z, c] : array_of_probability) {
			if (c != Poker::Combination::High_card) {
				std::cout << std::round(x * 100 * 100) / 100
					<< "%\t" << std::round(y * 100 * 100) / 100 << "%\t"
					<< std::round(z * 100 * 100) / 100 << "%\t" << '\t' << c << '\n' << '\n';
			}
		}
	}

	void Run_tests() {
		//test_check_combination_of_cards();
		/*
		Stopwatch<seconds> a;
		Stopwatch<seconds> b;
		a.SetBeginPoint();
		Test_distribution_of_five_comb_cards(1000000);
		a.SetEndPoint();

		a.ShowTime();
		std::cout << '\n';
		
		b.SetBeginPoint();
		Test_distribution_of_seven_comb_cards(1000000);
		b.SetEndPoint();

		b.ShowTime();*/

		//test_of_stopwatch();
		//test_wallpapper();

		Unit_tests_five_card();
		Unit_tests_six_card();
		Unit_tests_seven_card();

		//Test_combination_predictor();
		//Test_distribution_probabilty(10);
	}
}