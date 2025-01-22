#include "FiveCardCombination.h"
#include "Stopwatch.h"

void test_check_combination_of_cards() {
	std::vector<std::vector<Card>> cs = {
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

	for (auto& vec_cards : cs) {
		for (Card c : vec_cards) {
			std::cout << c << ' ';
		}
		std::cout << '\n';

		FiveCardCombination comb(vec_cards);
		comb.Combination();
		std::cout << '\n';
	}
}

void test_distribution_of_card(int m) {
	std::vector<Card> cs = {
		{'2','S'}, {'3','S'}, {'4','S'}, {'5','S'}, {'6','S'}, {'7','S'}, {'8','S'},
		{'9','S'}, {'T','S'}, {'J','S'}, {'Q','S'}, {'K','S'}, {'A','S'},
		{'2','H'}, {'3','H'}, {'4','H'}, {'5','H'}, {'6','H'}, {'7','H'}, {'8','H'},
		{'9','H'}, {'T','H'}, {'J','H'}, {'Q','H'}, {'K','H'}, {'A','H'},
		{'2','D'}, {'3','D'}, {'4','D'}, {'5','D'}, {'6','D'}, {'7','D'}, {'8','D'},
		{'9','D'}, {'T','D'}, {'J','D'}, {'Q','D'}, {'K','D'}, {'A','D'},
		{'2','C'}, {'3','C'}, {'4','C'}, {'5','C'}, {'6','C'}, {'7','C'}, {'8','C'},
		{'9','C'}, {'T','C'}, {'J','C'}, {'Q','C'}, {'K','C'}, {'A','C'},
	};

	std::random_device g;
	std::mt19937 r(g());

	FiveCardCombination hand;
	std::vector<Card> res;
	res.reserve(5);

	std::unordered_map<int, int> pw;
	for (int i = 0; i < m; ++i) {
		std::shuffle(cs.begin(), cs.end(), r);

		for (int j = 0; j < 5; ++j) {
			res.push_back(cs[j]);
		}

		FiveCardCombination temp(std::move(res));
		hand = std::move(temp);
		++pw[hand.CombinationPower()];
	}

	std::vector<std::pair<int, int>> vec(pw.begin(), pw.end());
	std::sort(vec.begin(), vec.end());

	for (const auto& [x, y] : vec) {
		Poker::Index(x);
		std::cout << ": " << y << '\n';
	}
}

void test_of_stopwatch() {
	Stopwatch obj;
	std::size_t mid = 0;
	std::size_t diff = 0;

	for (int i = 0; i < 10; ++i) {
		obj.SetBeginPoint();
		Delay(1);
		obj.SetEndPoint();

		std::size_t t = obj.GetTime();

		mid += t;
		diff += t - 1000000;
		std::cout << i + 1 << ": " << t << ' ' << t - 1000000 << ' ';
		obj.ShowType();
	}

	mid /= 10;
	std::cout << mid << ' ';
	obj.ShowType();
	std::cout << diff << ' ';
	obj.ShowType();
}

void test_wallpapper() {
	sf::Texture wallpapper;
	wallpapper.loadFromFile("img\\Table.png");

	sf::Sprite ph(wallpapper);

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Poker");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		window.draw(ph);
		window.display();
	}
}

int main() {
	//test_check_combination_of_cards();
	//test_distribution_of_card(100000);
	//test_of_stopwatch();
	//test_wallpapper();

	FiveCardCombination c1("AC AD QH QC QS");
	FiveCardCombination c2("KD KS KH 2H 2C");
	std::cout << Poker::compare_combinations(c1, c2);
	
	return 0;
}