#include "CardCombination.h"

CardCombination CardCombination::Find_best_six_cards(const std::span<Card>& vec_of_cards) {
	if (vec_of_cards.size() != Poker::count_of_cards_on_tern) {
		throw std::runtime_error("Not six cards for combination");
	}

	std::array<Card, 5> combination_1 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_2 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[5] };

	std::array<Card, 5> combination_3 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[5], vec_of_cards[4] };

	std::array<Card, 5> combination_4 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[5], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_5 =
		{ vec_of_cards[0], vec_of_cards[5], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_6 =
		{ vec_of_cards[5], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] };

	std::array<std::array<Card, 5>, 6> combinations = {
		combination_1, combination_2, combination_3, combination_4, combination_5, combination_6
	};

	CardCombination res = { combinations[0] };
	for (std::uint8_t i = 1; i < combinations.size(); ++i) {
		res = std::max(res, CardCombination(combinations[i]));
	}

	return res;
}

CardCombination CardCombination::Cast_string_six_cards(const std::string& str_of_cards) {
	if (str_of_cards.size() != Poker::count_of_str_cards_on_tern) {
		throw std::runtime_error("Not six cards for combination");
	}
	
	std::vector<Card> vector_of_cards;
	vector_of_cards.reserve(6);

	for (std::uint8_t i = 0; i < str_of_cards.size(); i += 3) {
		vector_of_cards.push_back({ str_of_cards[i], str_of_cards[i + 1] });
	}

	return Find_best_six_cards(vector_of_cards);
}

CardCombination CardCombination::Find_best_seven_cards(const std::span<Card>& vec_of_cards) {
	if (vec_of_cards.size() != Poker::count_of_cards_on_river) {
		throw std::runtime_error("Not seven cards for combination");
	}

	std::array<Card, 5> combination_1 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_2 =
		{ vec_of_cards[5], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_3 =
		{ vec_of_cards[0], vec_of_cards[5], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_4 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[5], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_5 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[5], vec_of_cards[4] };

	std::array<Card, 5> combination_6 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[5] };

	std::array<Card, 5> combination_7 =
		{ vec_of_cards[6], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_8 =
		{ vec_of_cards[0], vec_of_cards[6], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_9 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[6], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_10 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[6], vec_of_cards[4] };

	std::array<Card, 5> combination_11 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[6] };

	std::array<Card, 5> combination_12 =
		{ vec_of_cards[5], vec_of_cards[6], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_13 =
		{ vec_of_cards[5], vec_of_cards[1], vec_of_cards[6], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_14 =
		{ vec_of_cards[5], vec_of_cards[1], vec_of_cards[2], vec_of_cards[6], vec_of_cards[4] };

	std::array<Card, 5> combination_15 =
		{ vec_of_cards[5], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[6] };

	std::array<Card, 5> combination_16 =
		{ vec_of_cards[0], vec_of_cards[6], vec_of_cards[5], vec_of_cards[3], vec_of_cards[4] };

	std::array<Card, 5> combination_17 =
		{ vec_of_cards[0], vec_of_cards[6], vec_of_cards[2], vec_of_cards[5], vec_of_cards[4] };

	std::array<Card, 5> combination_18 =
		{ vec_of_cards[0], vec_of_cards[6], vec_of_cards[2], vec_of_cards[3], vec_of_cards[5] };

	std::array<Card, 5> combination_19 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[5], vec_of_cards[6] };

	std::array<Card, 5> combination_20 =
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[5], vec_of_cards[3], vec_of_cards[6] };

	std::array<Card, 5> combination_21 =
		{ vec_of_cards[5], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[6] };

	std::array<std::array<Card, 5>, 21> combinations = { 
		combination_1, combination_2, combination_3, combination_4, combination_5, combination_6,
		combination_7, combination_8, combination_9, combination_10, combination_11, combination_12,
		combination_13, combination_14, combination_15, combination_16, combination_17, combination_18,
		combination_19, combination_20, combination_21 
	};

	CardCombination res = { combinations[0] };
	for (std::uint8_t i = 1; i < combinations.size(); ++i) {
		res = std::max(res, CardCombination(combinations[i]));
	}

	return res;
}

CardCombination CardCombination::Cast_string_seven_cards(const std::string& str_of_cards) {
	if (str_of_cards.size() != Poker::count_of_str_cards_on_river) {
		throw std::runtime_error("Not seven cards for combination");
	}

	std::vector<Card> vector_of_cards;
	vector_of_cards.reserve(Poker::count_of_cards_on_river);

	for (std::uint8_t i = 0; i < str_of_cards.size(); i += 3) {
		vector_of_cards.push_back({ str_of_cards[i], str_of_cards[i + 1] });
	}

	return Find_best_seven_cards(vector_of_cards);
}

Poker::Combination CardCombination::GetPower() const noexcept {
	return power;
}

char CardCombination::GetHighCard() const noexcept {
	return high_card;
}

constexpr std::array<char, 4> CardCombination::GetKickers() const noexcept {
	return kickers;
}

CardCombination::CardCombination() noexcept = default;

CardCombination::CardCombination(const std::span<Card>& vector_of_cards) {
	if (vector_of_cards.size() == Poker::count_of_cards_on_river) {
		CardCombination result = Find_best_seven_cards(vector_of_cards);

		power = std::move(result.power);
		high_card = std::move(result.high_card);
		kickers = std::move(result.kickers);
	}
	else if (vector_of_cards.size() == Poker::count_of_cards_on_tern) {
		CardCombination result = Find_best_six_cards(vector_of_cards);

		power = std::move(result.power);
		high_card = std::move(result.high_card);
		kickers = std::move(result.kickers);
	}
	else if (vector_of_cards.size() != Poker::count_of_cards_on_flop) {
		throw std::runtime_error("Not five, six or seven cards for combination");
	}
	else {
		std::array<std::uint8_t, 13> values = {0};
		std::array<std::uint8_t, 4> suits = {0};

		for (Card c : vector_of_cards) {
			++values[Tools::cards(c.Power()) - 2];
			++suits[Tools::suits(c.Suit()) - 1];
		}

		std::vector<std::pair<char, std::uint8_t>> player_cards;
		player_cards.reserve(Poker::count_of_cards_on_flop);

		for (std::uint8_t i = 0; i < values.size(); ++i) {
			if (values[i] != 0) {
				player_cards.push_back({Tools::int_to_cards(i + 2), values[i]});
			}
		}

		std::sort(player_cards.begin(), player_cards.end(), Tools::comparator);

		std::uint8_t royal_flush = 0;
		std::uint8_t straight_flush = 0;
		std::uint8_t care = 0;
		std::uint8_t full_house = 0;
		std::uint8_t flush = 0;
		std::uint8_t straight = 0;
		std::uint8_t set = 0;
		std::uint8_t two_pair = 0;
		std::uint8_t pair = 0;

		std::uint8_t flush_series = 0;
		for (auto suit : suits) {
			if (suit != 0) { ++flush_series; }
		}

		if (flush_series == 1) { ++flush; }

		//Street check;
		std::uint8_t straight_series = 0;
		for (std::uint8_t i = 1; i < player_cards.size(); ++i) {
			if (std::abs(Tools::cards(player_cards[i].first)
				- Tools::cards(player_cards[i - 1].first)) == 1)
			{
				++straight_series;
			}
		}

		bool ace_low = false;
		if (player_cards.back().first == 'A' && player_cards.front().first == '2') {
			++straight_series;
			ace_low = true;
		}

		if (straight_series == 4) { ++straight; }

		if (straight == 1 && flush == 1 && player_cards.back().first == 'A' && player_cards.front().first == 'T') {
			++royal_flush;
		}
		else if (straight == 1 && flush == 1) { ++straight_flush; }

		for (auto [card, count] : player_cards) {
			if (count == 2) { ++pair; }
			else if (count == 3) { ++set; }
			else if (count == 4) { ++care; }
		}

		if (set == 1 && pair == 1) { ++full_house; }
		else if (pair == 2) { ++two_pair; }

		// Power initialization
		std::array<std::uint8_t, 9> res = {
			royal_flush, straight_flush, care, full_house, flush, straight, set, two_pair, pair
		};

		for (std::uint8_t i = 0, potential_power = 9; i < res.size(); ++i, --potential_power) {
			if (res[i] == 1) {
				power = static_cast<Poker::Combination>(potential_power);
				break;
			}
		}

		// High_Card initialization
		char second_high_card = ' ';

		if (power == Poker::Combination::High_card || power == Poker::Combination::Flush
			|| power == Poker::Combination::Royal_flush)
		{
			high_card = player_cards.back().first;
		}
		else if (power == Poker::Combination::Pair) {
			for (auto [card, count] : player_cards) {
				if (count == 2) {
					high_card = card;
					break;
				}
			}
		}
		else if (power == Poker::Combination::Two_pair) {
			bool high_card_checker = true;
			for (auto [card, count] : player_cards | std::ranges::views::reverse) {
				if (count == 2 && high_card_checker) {
					high_card = card;
					high_card_checker = false;
				}
				else if (count == 2 && !high_card_checker) {
					second_high_card = card;
				}
			}
		}
		else if (power == Poker::Combination::Set) {
			for (auto [card, count] : player_cards) {
				if (count == 3) {
					high_card = card;
					break;
				}
			}
		}
		else if (power == Poker::Combination::Full_house) {
			for (auto [card, count] : player_cards) {
				if (count == 3) {
					high_card = card;
				}
				else if (count == 2) {
					second_high_card = card;
				}
			}
		}
		else if (power == Poker::Combination::Care) {
			for (auto [card, count] : player_cards) {
				if (count == 4) {
					high_card = card;
					break;
				}
			}
		}
		else if (power == Poker::Combination::Straight || power == Poker::Combination::Straight_flush) {
			high_card = player_cards.back().first;
			if (ace_low) { high_card = player_cards[player_cards.size() - 2].first; }
		}
		else {
			throw std::runtime_error("Error");
		}

		//kickers initialization
		std::uint8_t count_of_kickers = 0;

		for (auto [card, count] : player_cards) {
			if (card != high_card && card != second_high_card) {
				kickers[count_of_kickers++] = card;
			}
		}
		if (second_high_card != ' ') {
			kickers[count_of_kickers++] = second_high_card;
		}
		std::reverse(kickers.begin(), kickers.end());

		if (ace_low) {
			for (std::uint8_t i = 0; i + 1 < kickers.size(); ++i) {
				std::swap(kickers[i], kickers[i + 1]);
			}
		}
	}
}

CardCombination::CardCombination(std::initializer_list<Card> lst) {
	std::vector<Card> vec_of_cards = { std::move(lst) };
	CardCombination result = { vec_of_cards };

	power = std::move(result.power);
	high_card = std::move(result.high_card);
	kickers = std::move(result.kickers);
}

CardCombination::CardCombination(const std::string& string_of_cards) {
	if (string_of_cards.size() != Poker::count_of_str_cards_on_flop
		&& string_of_cards.size() != Poker::count_of_str_cards_on_tern
		&& string_of_cards.size() != Poker::count_of_str_cards_on_river)
	{
		throw std::runtime_error("Uncorrected count of cards");
	}
	std::vector<Card> vector_of_cards;
	vector_of_cards.reserve(Poker::count_of_cards_on_river);

	for (std::uint8_t i = 0; i < string_of_cards.size(); i += 3) {
		vector_of_cards.push_back({string_of_cards[i], string_of_cards[i + 1]});
	}

	CardCombination combination(vector_of_cards);

	power = std::move(combination.power);
	high_card = std::move(combination.high_card);
	kickers = std::move(combination.kickers);
}

CardCombination::CardCombination(const char* string_of_cards) 
	: CardCombination::CardCombination(std::string(string_of_cards)) {}

void CardCombination::ShowCombination() const noexcept {
	std::cout << power << ": High cart - " << high_card << '\n';
}

bool operator<(CardCombination comb1, CardCombination comb2) noexcept {
	if (comb1.GetPower() == comb2.GetPower()) {
		if (comb1.GetHighCard() == comb2.GetHighCard()) {
			auto kickers1 = comb1.GetKickers();
			auto kickers2 = comb2.GetKickers();
		
			for (std::uint8_t i = 0; i < kickers1.size(); ++i) {
				if ((kickers1[i] != ' ' && kickers2[i] != ' ') 
					&& (Tools::cards(kickers1[i]) != Tools::cards(kickers2[i])))
				{
					return Tools::cards(kickers1[i]) < Tools::cards(kickers2[i]);
				}
			}
			return false;
		}
		return Tools::cards(comb1.GetHighCard()) < Tools::cards(comb2.GetHighCard());
	}
	return comb1.GetPower() < comb2.GetPower();
}

bool operator>(CardCombination comb1, CardCombination comb2) noexcept {
	return comb2 < comb1;
}

bool operator==(CardCombination comb1, CardCombination comb2) noexcept {
	return !(comb1 < comb2) && !(comb2 < comb1);
}

bool operator!=(CardCombination comb1, CardCombination comb2) noexcept {
	return !(comb1 == comb2);
}

bool operator<=(CardCombination comb1, CardCombination comb2) noexcept {
	return !(comb2 < comb1);
}

bool operator>=(CardCombination comb1, CardCombination comb2) noexcept {
	return comb2 <= comb1;
}

namespace Poker {
	Result compare_combinations(CardCombination comb1, CardCombination comb2) noexcept {
		if (comb1 < comb2) {
			return Result::Loss;
		}
		else if (comb1 > comb2) {
			return Result::Win;
		}
		else {
			return Result::Draw;
		}
	}

	auto Find_Probability(const std::span<Card>& vector_of_cards)
		-> std::array<std::tuple<float, float, float, Poker::Combination>, 9>
	{
		if (vector_of_cards.size() != Poker::count_of_cards_on_flop) {
			throw std::runtime_error("Uncorrected count of cards for this stage");
		}

		std::array<char, 5> striaght_combination_1 = { '2','3','4','5','6' };
		std::array<char, 5> striaght_combination_2 = { '3','4','5','6','7' };
		std::array<char, 5> striaght_combination_3 = { '4','5','6','7','8' };
		std::array<char, 5> striaght_combination_4 = { '5','6','7','8','9' };
		std::array<char, 5> striaght_combination_5 = { '6','7','8','9','T' };
		std::array<char, 5> striaght_combination_6 = { '7','8','9','T','J' };
		std::array<char, 5> striaght_combination_7 = { '8','9','T','J','Q' };
		std::array<char, 5> striaght_combination_8 = { '9','T','J','Q','K' };
		std::array<char, 5> striaght_combination_9 = { 'T','J','Q','K','A' };
		std::array<char, 5> striaght_combination_10 = { '2','J','Q','K','A' };
		std::array<char, 5> striaght_combination_11 = { '2','3','Q','K','A' };
		std::array<char, 5> striaght_combination_12 = { '2','3','4','K','A' };
		std::array<char, 5> striaght_combination_13 = { '2','3','4','5','A' };

		std::array<std::array<char, 5>, 13> all_straight_combinations = {
			striaght_combination_1, striaght_combination_2, striaght_combination_3,
			striaght_combination_4, striaght_combination_5, striaght_combination_6,
			striaght_combination_7, striaght_combination_8, striaght_combination_9,
			striaght_combination_10, striaght_combination_11, striaght_combination_12,
			striaght_combination_13
		};

		auto find_outs = [](std::array<char, 5> cards, const std::vector<std::pair<char, std::uint8_t>>& vector_of_cards)
			-> std::pair<char, char>
		{
			std::pair<char, char> result = { ' ', ' ' };

			if (vector_of_cards.size() < 3) {
				return result;
			}

			std::vector<char> values_of_card;
			values_of_card.reserve(5);

			for (auto pair : vector_of_cards) {
				values_of_card.push_back(pair.first);
			}

			std::vector<char> res;

			std::set_difference(
				cards.begin(),
				cards.end(),
				values_of_card.begin(),
				values_of_card.end(),
				std::back_inserter(res),
				[](char card_from_cards, char card_from_values_of_card) {
					return Tools::cards(card_from_cards) < Tools::cards(card_from_values_of_card);
				}
			);

			if (res.size() == 1) {
				result.first = res.back();
			}
			else if (res.size() == 2) {
				result.first = res.front();
				result.second = res.back();
			}

			return result;
		};

		auto straight_check = [&all_straight_combinations, &find_outs]
		(const std::vector<std::pair<char, std::uint8_t>>& vector_of_cards, bool straight_flush = false)
			-> std::pair<std::vector<char>, std::vector<std::pair<char,char>>>
		{
			std::unordered_set<char> one_cards;
			std::unordered_set <std::pair<char, char>, decltype([](std::pair<char, char> pair) {
				std::size_t h1 = std::hash<char>{}(pair.first);
				std::size_t h2 = std::hash<char>{}(pair.second);
				return h1 << h2;
			})> pairs_cards;

			for (std::uint8_t i = 0; i < all_straight_combinations.size(); ++i) {
				if (i != 8 || !straight_flush) {
					auto pair_outs = find_outs(all_straight_combinations[i], vector_of_cards);

					if (!(pair_outs.first == ' ' && pair_outs.second == ' ')) {
						if (pair_outs.second == ' ') {
							one_cards.emplace(pair_outs.first);
						}
						else {
							pairs_cards.emplace(pair_outs);
						}
					}
				}
			}
			return { 
				std::vector<char>(one_cards.begin(), one_cards.end()),
				std::vector<std::pair<char,char>>(pairs_cards.begin(), pairs_cards.end())
			};
		};

		CardCombination combination = vector_of_cards;
		Poker::Combination current_power = combination.GetPower();

		std::array<std::tuple<float, float, float, Poker::Combination>, 9> results = {};
		std::uint8_t count_of_results = 0;

		std::array<std::uint8_t, 13> values = { 0 };
		std::array<std::uint8_t, 4> suits = { 0 };

		for (Card card : vector_of_cards) {
			++values[Tools::cards(card.Power()) - 2];
			++suits[Tools::suits(card.Suit()) - 1];
		}

		std::vector<std::pair<char, std::uint8_t>> player_cards;
		player_cards.reserve(Poker::count_of_cards_on_flop);

		for (std::uint8_t i = 0; i < values.size(); ++i) {
			if (values[i] != 0) {
				player_cards.push_back({ Tools::int_to_cards(i + 2), values[i] });
			}
		}
		std::sort(player_cards.begin(), player_cards.end(), Tools::comparator);

		std::uint8_t max_flush_series = 0;
		for (auto suit : suits) {
			max_flush_series = std::max(max_flush_series, suit);
		}

		char top_suit = ' ';
		for (std::uint8_t i = 0; i < suits.size(); ++i) {
			if (max_flush_series == suits[i]) {
				top_suit = Tools::int_to_suits(i + 1);
				break;
			}
		}

		std::vector<Card> suited_cards;
		suited_cards.reserve(Poker::count_of_cards_on_flop);

		std::copy_if(vector_of_cards.begin(), vector_of_cards.end(), std::back_inserter(suited_cards),
			[&top_suit](Card card) {
				return card.Suit() == top_suit;
			}
		);
		std::sort(suited_cards.begin(), suited_cards.end());

		std::vector<std::pair<char, std::uint8_t>> straight_flush_cards;
		straight_flush_cards.reserve(5);

		for (Card card : suited_cards) {
			straight_flush_cards.push_back({ card.Power(), 1 });
		}

		std::pair<std::vector<char>, std::vector<std::pair<char, char>>> straight_outs
			= straight_check(player_cards);

		std::pair<std::vector<char>, std::vector<std::pair<char, char>>> straight_flush_outs
			= straight_check(straight_flush_cards, true);

		std::uint8_t straight_one_need_cards = straight_outs.first.size();
		std::uint8_t straight_two_need_cards = straight_outs.second.size();

		std::uint8_t straight_flush_one_need_cards = straight_flush_outs.first.size();
		std::uint8_t straight_flush_two_need_cards = straight_flush_outs.second.size();

		auto compare_pair = [](auto pair_1, auto pair_2) {
			return ((pair_1.first == pair_2.first) || (pair_1.first == pair_2.second)
				&& (pair_1.second == pair_2.first) || (pair_1.second == pair_2.second));
		};

		constexpr float count_all_cards_tern = 47.0f;
		constexpr float count_all_cards_river = 46.0f;

		for (std::uint8_t predict_power = static_cast<std::uint8_t>(current_power) + 1;
			predict_power <= 9; ++predict_power)
		{
			//Pair
			if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Pair)) {
				float probability_tern = 0.0f;
				float probability_river = 0.0f;
				float probability_tern_or_river = 0.0f;

				if (max_flush_series == 4) {
					probability_tern = (5.0f * 2.0f) / count_all_cards_tern;
					probability_river = (6.0f * 2.0f) / count_all_cards_river;
				}
				else {
					probability_tern = (5.0f * 3.0f) / count_all_cards_tern;
					probability_river = (6.0f * 3.0f) / count_all_cards_river;
				}

				probability_tern_or_river = probability_tern + probability_river;

				results[count_of_results++]
					= { probability_tern, probability_river, probability_tern_or_river, Poker::Combination::Pair };
			}
			//Two_pair
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Two_pair)) {
				float probability_tern = 0.0f;
				float probability_river = 0.0f;
				float probability_tern_or_river = 0.0f;

				if (current_power == Poker::Combination::Pair) {
					if (max_flush_series == 4) {
						probability_tern = (3.0f * 2.0f) / count_all_cards_tern;
						probability_river = (4.0f * 2.0f) / count_all_cards_river;
					}
					else {
						probability_tern = (3.0f * 3.0f) / count_all_cards_tern;
						probability_river = (4.0f * 3.0f) / count_all_cards_river;
					}

					probability_tern_or_river = probability_tern + probability_river;
				}
				else if (current_power == Poker::Combination::High_card) {
					if (max_flush_series >= 3) {
						probability_river = ((5.0f * 2.0f) / count_all_cards_tern) * ((4.0f * 2.0f) / count_all_cards_river);
					}
					else {
						probability_river = ((5.0f * 3.0f) / count_all_cards_tern) * ((4.0f * 3.0f) / count_all_cards_river);
					}
				}

				results[count_of_results++]
					= { probability_tern, probability_river, probability_tern_or_river, Poker::Combination::Two_pair };
			}
			//Set
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Set)) {
				float probability_tern = 0.0f;
				float probability_river = 0.0f;
				float probability_tern_or_river = 0.0f;

				//Two pair: Nothing

				if (current_power == Poker::Combination::Pair) {
					if (max_flush_series == 4) {
						probability_tern = 1.0f / count_all_cards_tern;
						probability_river = 1.0f / count_all_cards_river;
					}
					else {
						probability_tern = 2.0f / count_all_cards_tern;
						probability_river = 2.0f / count_all_cards_river;
					}
					
					probability_tern_or_river = probability_tern + probability_river;
				}
				else if (current_power == Poker::Combination::High_card) {
					if (max_flush_series >= 3) {
						probability_river = ((5.0f * 2.0f) / count_all_cards_tern) * (1.0f / count_all_cards_river);
					}
					else {
						probability_river = ((5.0f * 3.0f) / count_all_cards_tern) * (2.0f / count_all_cards_river);
					}
				}

				results[count_of_results++]
					= { probability_tern, probability_river, probability_tern_or_river, Poker::Combination::Set };
			}
			//Straight
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Straight)) {
				float probability_tern = 0.0f;
				float probability_river = 0.0f;
				float probability_tern_or_river = 0.0f;

				bool filtered_one = false;
				bool filtered_two = false;

				if (straight_one_need_cards != 0) {
					if (!straight_outs.first.empty() && !straight_flush_outs.first.empty()) {
						if (((straight_outs.first[0] == straight_flush_outs.first[0])
							|| (straight_outs.first[0] == straight_flush_outs.first[1])) ||
							(straight_outs.first[1] == straight_flush_outs.first[0])
							|| (straight_outs.first[1] == straight_flush_outs.first[1]))
						{
							filtered_one = true;
						}
					}
				}
				else if (straight_two_need_cards != 0) {
					if (!straight_outs.second.empty() && !straight_flush_outs.second.empty()) {
						if (((compare_pair(straight_outs.second[0], straight_flush_outs.second[0]))
							|| (compare_pair(straight_outs.second[0], straight_flush_outs.second[1]))) ||
							((compare_pair(straight_outs.second[1], straight_flush_outs.second[0]))
								|| (compare_pair(straight_outs.second[1], straight_flush_outs.second[1]))))
						{
							filtered_two = true;
						}
					}
				}

				if (player_cards.size() >= 3) {
					if (straight_one_need_cards == 0) {
						float prob_two_cards = 0.0f;

						if (max_flush_series >= 3 || filtered_two) {
							prob_two_cards = 2.0f * ((3.0f / count_all_cards_tern) * (3.0f / count_all_cards_river));
						}
						else {
							prob_two_cards = 2.0f * ((4.0f / count_all_cards_tern) * (4.0f / count_all_cards_river));
						}

						probability_river = straight_two_need_cards * prob_two_cards;
					}
					else {
						float prob_one_card_tern = 0.0f;
						float prob_one_card_river = 0.0f;

						if (max_flush_series == 4 || filtered_one) {
							prob_one_card_tern = (straight_one_need_cards * 3.0f) / count_all_cards_tern;
							prob_one_card_river = (straight_one_need_cards * 3.0f) / count_all_cards_river;
						}
						else {
							prob_one_card_tern = (straight_one_need_cards * 4.0f) / count_all_cards_tern;
							prob_one_card_river = (straight_one_need_cards * 4.0f) / count_all_cards_river;
						}
						
						probability_tern = prob_one_card_tern;
						probability_river = prob_one_card_river;
						probability_tern_or_river = probability_tern + probability_river;
					}
				}

				results[count_of_results++]
					= { probability_tern, probability_river, probability_tern_or_river, Poker::Combination::Straight };
				
			}
			//Flush
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Flush)) {
				float probability_tern = 0.0f;
				float probability_river = 0.0f;
				float probability_tern_or_river = 0.0f;

				if (max_flush_series == 4) {
					probability_tern = (9.0f - straight_flush_one_need_cards) / count_all_cards_tern;
					probability_river = (9.0f - straight_flush_one_need_cards) / count_all_cards_river;
					probability_tern_or_river = probability_tern + probability_river;
				}
				else if (max_flush_series == 3) {
					if (straight_flush_one_need_cards == 0) {
						probability_river = (10.0f / count_all_cards_tern)
							* ((9.0f - straight_flush_two_need_cards) / count_all_cards_river);
					}
					else {
						probability_river = ((10.0f - straight_flush_one_need_cards) / count_all_cards_tern)
							* ((9.0f - straight_flush_one_need_cards) / count_all_cards_river);
					}
				}

				results[count_of_results++]
					= { probability_tern, probability_river, probability_tern_or_river, Poker::Combination::Flush };
			}
			//Full_house
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Full_house)) {
				float probability_tern = 0.0f;
				float probability_river = 0.0f;
				float probability_tern_or_river = 0.0f;

				//Flush, Straight, High_card - Nothing

				if (current_power == Poker::Combination::Set) {
					probability_tern = 6.0f / count_all_cards_tern;
					probability_river = 6.0f / count_all_cards_river;
					probability_tern_or_river = probability_tern + probability_river;
				}
				else if (current_power == Poker::Combination::Two_pair) {
					probability_tern = 4.0f / count_all_cards_tern;
					probability_river = 4.0f / count_all_cards_river;
					probability_tern_or_river = probability_tern + probability_river;
				}
				else if (current_power == Poker::Combination::Pair) {
					probability_river = 2 * (2.0f / count_all_cards_tern) * (9.0f / count_all_cards_river);
				}

				results[count_of_results++]
					= { probability_tern, probability_river, probability_tern_or_river, Poker::Combination::Full_house };
			}
			//Care
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Care)) {
				float probability_tern = 0.0f;
				float probability_river = 0.0f;
				float probability_tern_or_river = 0.0f;

				//Flush, Straight, High_card - Nothing

				if (current_power == Poker::Combination::Full_house) {
					probability_tern = 1.0f / count_all_cards_tern;
					probability_river = 1.0f / count_all_cards_river;
					probability_tern_or_river = probability_tern + probability_river;
				}
				else if (current_power == Poker::Combination::Set) {
					probability_tern = 1.0f / count_all_cards_tern;
					probability_river = 1.0f / count_all_cards_river;
					probability_tern_or_river = probability_tern + probability_river;
				}
				else if (current_power == Poker::Combination::Two_pair) {
					probability_river = (4.0f / count_all_cards_tern) * (1.0f / count_all_cards_river);
				}
				else if (current_power == Poker::Combination::Pair) {
					probability_river = (2.0f / count_all_cards_tern) * (1.0f / count_all_cards_river);
				}

				results[count_of_results++]
					= { probability_tern, probability_river, probability_tern_or_river, Poker::Combination::Care };
			}
			//Straight_flush
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Straight_flush)) {
				float probability_tern = 0.0f;
				float probability_river = 0.0f;
				float probability_tern_or_river = 0.0f;

				//Care, Full_house - Nothing

				if (current_power == Poker::Combination::Flush || current_power == Poker::Combination::Straight
					|| current_power == Poker::Combination::Set || current_power == Poker::Combination::Two_pair
					|| current_power == Poker::Combination::Pair|| current_power == Poker::Combination::High_card)
				{
					
					if (straight_flush_cards.size() >= 3) {
						if (straight_flush_one_need_cards == 0) {
							constexpr float prob_two_cards = 2.0f * ((1.0f / count_all_cards_tern)
								* (1.0f / count_all_cards_river));

							probability_river = straight_flush_two_need_cards * prob_two_cards;
						}
						else {
							float prob_one_card_tern = (straight_flush_one_need_cards * 1.0f) / count_all_cards_tern;
							float prob_one_card_river = (straight_flush_one_need_cards * 1.0f) / count_all_cards_river;

							probability_tern = prob_one_card_tern;
							probability_river = prob_one_card_river;
							probability_tern_or_river = probability_tern + probability_river;
						}
					}
				}

				results[count_of_results++]
					= { probability_tern, probability_river, probability_tern_or_river, Poker::Combination::Straight_flush };
			}
			//Royal_flush
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Royal_flush)) {
				float probability_tern = 0.0f;
				float probability_river = 0.0f;
				float probability_tern_or_river = 0.0f;
				
				auto need_cards = find_outs(striaght_combination_9, straight_flush_cards);
				std::pair<std::uint8_t, std::uint8_t> outs = {0, 0};

				outs.second += (need_cards.second != ' ' && need_cards.first != ' ');
				outs.first += (need_cards.second == ' ' && need_cards.first != ' ');
				
				if (outs.first == 0) {
					constexpr float prob_two_cards = 2.0f * ((1.0f / count_all_cards_tern)
						* (1.0f / count_all_cards_river));

					probability_river = outs.second * prob_two_cards;
				}
				else {
					float prob_one_card_tern = (outs.first * 1.0f) / count_all_cards_tern;
					float prob_one_card_river = (outs.first * 1.0f) / count_all_cards_river;

					probability_tern = prob_one_card_tern;
					probability_river = prob_one_card_river;
					probability_tern_or_river = probability_tern + probability_river;
				}

				results[count_of_results++]
					= { probability_tern, probability_river, probability_tern_or_river, Poker::Combination::Royal_flush };
			}
		}
		return results;
	}
}