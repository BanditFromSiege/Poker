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

	extern void Test_distribution_probabilty(int number_of_ñard_shuffles = 5, bool show = true);
	extern void Test_find_probability(const std::span<Card>& vector_of_cards);
	extern void Test_combination_predictor();

	extern void Run_tests();
}

int main() {
	Tests::Run_tests();
	
	//std::vector<Card> vec = { "TC", "9H", "2D", "TH", "JD" };
	//Tests::Test_find_probability(vec);

	/*
	auto ptr = std::make_unique<ConsolePokerGame>();
	(*ptr).Run();*/

	return 0;
}