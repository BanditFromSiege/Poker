#include "ConsoleRender/ConsolePokerGame.h"

namespace Tests {
	extern void Test_check_combination_of_cards();
	extern void Test_distribution_of_five_comb_cards(int number_of_ñard_shuffles);
	extern void Test_distribution_of_seven_comb_cards(int number_of_ñard_shuffles);
	extern void Test_of_stopwatch();
	extern void Test_wallpapper();

	extern void Unit_tests_five_card();
	extern void Unit_tests_six_card();
	extern void Unit_tests_seven_card();

	extern void Run_tests();
}

int main() {
	Tests::Run_tests();
	
	//"3H", "5D", "6D", "9S", "TD"
	//"AH", "TD", "9H", "2S", "KH"

	/*
	std::vector<Card> vec = { "8H", "8C", "9H", "TH", "AH" };
	auto array_of_probabilty = Poker::Find_Probability(vec);

	std::cout << "Tern" << '\t' << " River" << '\t' << " Tern or River" << '\t' << " Combination" << '\n' << '\n';
	for (auto [x, y, z, c] : array_of_probabilty) {
		if (c != Poker::Combination::High_card) {
			std::cout << x * 100 << '\t' << y * 100 << '\t' << z * 100 << '\t' << '\t' << c << '\n' << '\n';
		}
	}*/

	/*
	auto ptr = std::make_unique<ConsolePokerGame>();
	(*ptr).Run();*/

	return 0;
}