#include "ConsoleRender/ConsolePokerGame.h"

namespace Tests {
	void test_check_combination_of_cards() {
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

		for (const auto& vector_of_cards : cards) {
			for (Card c : vector_of_cards) {
				std::cout << c << ' ';
			}
			std::cout << '\n';

			FiveCardCombination combination(vector_of_cards);
			combination.ShowCombination();
			std::cout << '\n';
		}
	}

	void test_distribution_of_five_comb_cards(int number_of_ñard_shuffles) {
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

		FiveCardCombination hand;
		std::vector<Card> cards_of_combinations;
		cards_of_combinations.reserve(5);

		std::unordered_map<Poker::Combination, int> un_map_of_combinations;
		for (int i = 0; i < number_of_ñard_shuffles; ++i) {
			std::shuffle(cards.begin(), cards.end(), *ptr_to_rand_engine);

			for (int j = 0; j < 5; ++j) {
				cards_of_combinations.push_back(cards[j]);
			}

			FiveCardCombination temp(cards_of_combinations);
			hand = std::move(temp);
			++un_map_of_combinations[hand.getPower()];

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

	void test_distribution_of_seven_comb_cards(int number_of_ñard_shuffles) {
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
		auto pr = std::make_unique<std::mt19937>(g());

		SevenCardCombination hand;
		std::vector<Card> cards_of_combinations;
		cards_of_combinations.reserve(7);

		std::unordered_map<Poker::Combination, int> un_map_of_combinations;
		for (int i = 0; i < number_of_ñard_shuffles; ++i) {
			std::shuffle(cards.begin(), cards.end(), *pr);

			for (int j = 0; j < 7; ++j) {
				cards_of_combinations.push_back(cards[j]);
			}

			SevenCardCombination temp(cards_of_combinations);
			hand = std::move(temp);
			++un_map_of_combinations[hand.getPower()];

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

	void test_of_stopwatch() {
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

	void test_wallpapper() {
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

	void unit_tests_five_card() {
		auto run_test = [](const char* player, const char* opponent, Poker::Result outcome) -> bool {
			return Poker::compare_combinations(FiveCardCombination(player), FiveCardCombination(opponent)) == outcome;
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
	}

	void unit_tests_six_card() {
		auto run_test = [](const char* player, const char* opponent, Poker::Result outcome) -> bool {
			return Poker::compare_combinations(SixCardCombination(player), SixCardCombination(opponent)) == outcome;
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

	void unit_tests_seven_card() {
		auto run_test = [](const char* player, const char* opponent, Poker::Result outcome) -> bool {
			return Poker::compare_combinations(SevenCardCombination(player), SevenCardCombination(opponent)) == outcome;
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

	void Run_tests() {
		//test_check_combination_of_cards();

		/*
		Stopwatch<seconds> a; 
		Stopwatch<seconds> b;
		a.SetBeginPoint();
		test_distribution_of_five_comb_cards(10000);
		a.SetEndPoint();

		a.ShowTime();
		std::cout << '\n';

		b.SetBeginPoint();
		test_distribution_of_seven_comb_cards(10000);
		b.SetEndPoint();

		b.ShowTime();
		*/

		//test_of_stopwatch();
		//test_wallpapper();

		unit_tests_five_card();
		unit_tests_six_card();
		unit_tests_seven_card();
	}
}