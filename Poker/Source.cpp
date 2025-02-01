#include "ConsoleRender/ConsolePokerGame.h"

namespace Tests {
	extern void test_check_combination_of_cards();
	extern void test_distribution_of_five_comb_cards(int number_of_ñard_shuffles);
	extern void test_distribution_of_seven_comb_cards(int number_of_ñard_shuffles);
	extern void test_of_stopwatch();
	extern void test_wallpapper();

	extern void unit_tests_five_card();
	extern void unit_tests_six_card();
	extern void unit_tests_seven_card();

	extern void Run_tests();
}

int main() {
	Tests::Run_tests();

	/*
	auto ptr = std::make_unique<ConsolePokerGame>();
	(*ptr).Run();*/

	return 0;
}