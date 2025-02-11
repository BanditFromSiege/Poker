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
				player_cards.push_back({Tools::values_cards(i + 2), values[i]});
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

		CardCombination combination = vector_of_cards;
		Poker::Combination current_power = combination.GetPower();

		std::array<std::tuple<float, float, float, Poker::Combination>, 9> results = {};
		std::uint8_t count_of_results = 0;

		std::array<std::uint8_t, 13> values = { 0 };
		std::array<std::uint8_t, 4> suits = { 0 };

		for (Card c : vector_of_cards) {
			++values[Tools::cards(c.Power()) - 2];
			++suits[Tools::suits(c.Suit()) - 1];
		}

		for (std::uint8_t predict_power = static_cast<std::uint8_t>(current_power) + 1;
			predict_power <= 9; ++predict_power)
		{
			//Pair
			if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Pair)) {
				constexpr float probabilty_tern = 15.0f / 47.0f;
				constexpr float probabilty_river = 18.0f / 46.0f;
				constexpr float probabilty_tern_or_river = probabilty_tern + probabilty_river;

				results[count_of_results++]
					= { probabilty_tern, probabilty_river, probabilty_tern_or_river, Poker::Combination::Pair };
			}
			//Two_pair
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Two_pair)) {
				if (current_power == Poker::Combination::Pair) {
					constexpr float probabilty_tern = 9.0f / 47.0f;
					constexpr float probabilty_river = 12.0f / 46.0f;
					constexpr float probabilty_tern_or_river = probabilty_tern + probabilty_river;

					results[count_of_results++]
						= { probabilty_tern, probabilty_river, probabilty_tern_or_river, Poker::Combination::Two_pair };
				}
				else if (current_power == Poker::Combination::High_card) {
					constexpr float probabilty_river = (15.0f / 47.0f) * (12.0f / 46.0f);

					results[count_of_results++]
						= { 0.0f, probabilty_river, 0.0f, Poker::Combination::Two_pair };
				}
			}
			//Set
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Set)) {
				if (current_power == Poker::Combination::Two_pair) {
					results[count_of_results++]
						= { 0.0f, 0.0f, 0.0f, Poker::Combination::Set };
				}
				else if (current_power == Poker::Combination::Pair) {
					constexpr float probabilty_tern = 2.0f / 47.0f;
					constexpr float probabilty_river = 2.0f / 46.0f;
					constexpr float probabilty_tern_or_river = probabilty_tern + probabilty_river;

					results[count_of_results++]
						= { probabilty_tern, probabilty_river, probabilty_tern_or_river, Poker::Combination::Set };
				}
				else if (current_power == Poker::Combination::High_card) {
					constexpr float probabilty_river = (15.0f / 47.0f) * (2.0f / 46.0f);

					results[count_of_results++]
						= { 0.0f, probabilty_river, 0.0f, Poker::Combination::Set };
				}
			}
			//Straight
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Straight)) {
				//Maybe remake
				std::vector<std::pair<char, std::uint8_t>> player_cards;
				player_cards.reserve(Poker::count_of_cards_on_flop);

				for (std::uint8_t i = 0; i < values.size(); ++i) {
					if (values[i] != 0) {
						player_cards.push_back({ Tools::values_cards(i + 2), values[i] });
					}
				}

				std::sort(player_cards.begin(), player_cards.end(), Tools::comparator);

				std::array<std::uint8_t, 5> diff = {0, 0, 0, 0, 0};
				std::uint8_t count_diff = 0;

				std::uint8_t straight_series = 0;
				for (std::uint8_t i = 1; i < player_cards.size(); ++i) {
					diff[count_diff] = std::abs(Tools::cards(player_cards[i].first)
						- Tools::cards(player_cards[i - 1].first));

					if (diff[count_diff] == 1) {
						++straight_series;
					}
					++count_diff;
				}

				if (player_cards.back().first == 'A' && player_cards.front().first == '2') {
					++straight_series;
					++diff[count_diff];
					++count_diff;

					for (std::int8_t i = diff.size() - 1; i > 0; --i) {
						std::swap(diff[i], diff[i - 1]);
					}
				}

				float probabilty_tern = 0.0f;
				float probabilty_river = 0.0f;
				float probabilty_tern_or_river = 0.0f;

				std::uint8_t max_length = 0;
				std::uint8_t temp_length = 0;

				std::uint8_t begin_position = 0;
				std::uint8_t temp_position = 0;

				if (straight_series >= 2) {
					bool begin = true;
					for (std::uint8_t i = 0; i < diff.size(); ++i) {
						if (diff[i] == 1) {
							++temp_length;
							if (begin) {
								temp_position = i;
								begin = false;
							}
						}
						else {
							if (max_length < temp_length) {
								max_length = temp_length;
								begin_position = temp_position;
							}
							begin = true;
							temp_length = 0;
						}
					}
					max_length = std::max(temp_length, max_length);

					if (max_length == 3) {
						probabilty_tern = 8.0f / 47.0f;
						probabilty_river = 8.0f / 46.0f;
						probabilty_tern_or_river = probabilty_tern + probabilty_river;
					}
					else if (max_length == 2) {
						std::uint8_t next_index = begin_position + max_length;
						std::int8_t prev_index = begin_position - 1;

						if (next_index <= 4) {
							if (diff[next_index] == 2) {
								probabilty_tern += 4.0f / 47.0f;
								probabilty_river += 4.0f / 46.0f;
							}
							else if (diff[next_index] >= 3) {
								probabilty_river += (4.0f / 47.0f) * (4.0f / 46.0f);
							}
						}

						if (prev_index >= 0) {
							if (diff[prev_index] == 2) {
								probabilty_tern += 4.0f / 47.0f;
								probabilty_river += 4.0f / 46.0f;
							}
							else if (diff[prev_index] >= 3) {
								probabilty_river += (4.0f / 47.0f) * (4.0f / 46.0f);
							}
						}

						else if (prev_index < 0) {
							if (next_index <= 4 && diff[next_index] >= 3) {
								probabilty_river += (4.0f / 47.0f) * (8.0f / 46.0f);
							}
							else {
								probabilty_river += (4.0f / 47.0f) * (4.0f / 46.0f);
							}
						}
					}
					else if (max_length == 1) {
						//TODO
						std::uint8_t next_index = begin_position + 1;
						std::int8_t prev_index = begin_position - 1;
					}

					results[count_of_results++]
						= { probabilty_tern, probabilty_river, probabilty_tern_or_river, Poker::Combination::Straight };
				}
				else {
					results[count_of_results++]
						= { 0.0f, 0.0f, 0.0f, Poker::Combination::Straight };
				}
			}
			//Flush
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Flush)) {
				std::uint8_t max_flush_series = 0;
				for (auto suit : suits) {
					max_flush_series = std::max(max_flush_series, suit);
				}

				if (max_flush_series == 4) {
					constexpr float probabilty_tern = 9.0f / 47.0f;
					constexpr float probabilty_river = 9.0f / 46.0f;
					constexpr float probabilty_tern_or_river = probabilty_tern + probabilty_river;

					results[count_of_results++]
						= { probabilty_tern, probabilty_river, probabilty_tern_or_river, Poker::Combination::Flush };
				}
				else if (max_flush_series == 3) {
					constexpr float probabilty_river = (9.0f / 47.0f) * (9.0f / 46.0f);

					results[count_of_results++]
						= { 0.0f, probabilty_river, 0.0f, Poker::Combination::Flush };
				}
				else {
					results[count_of_results++]
						= { 0.0f, 0.0f, 0.0f, Poker::Combination::Flush };
				}
			}
			//Full_house
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Full_house)) {
				if (current_power == Poker::Combination::Flush) {
					//TODO
				}
				else if (current_power == Poker::Combination::Straight) {
					results[count_of_results++]
						= { 0.0f, 0.0f, 0.0f, Poker::Combination::Full_house };
				}
				else if (current_power == Poker::Combination::Set) {
					constexpr float probabilty_tern = 6.0f / 47.0f;
					constexpr float probabilty_river = 6.0f / 46.0f;
					constexpr float probabilty_tern_or_river = probabilty_tern + probabilty_river;

					results[count_of_results++]
						= { probabilty_tern, probabilty_river, probabilty_tern_or_river, Poker::Combination::Full_house };
				}
				else if (current_power == Poker::Combination::Two_pair) {
					constexpr float probabilty_tern = 4.0f / 47.0f;
					constexpr float probabilty_river = 4.0f / 46.0f;
					constexpr float probabilty_tern_or_river = probabilty_tern + probabilty_river;

					results[count_of_results++]
						= { probabilty_tern, probabilty_river, probabilty_tern_or_river, Poker::Combination::Full_house };
				}
				else if (current_power == Poker::Combination::Pair) {
					constexpr float probabilty_river = 2 * (2.0f / 47.0f) * (9.0f / 46.0f);

					results[count_of_results++]
						= { 0.0f, probabilty_river, 0.0f, Poker::Combination::Full_house };
				}
				else {
					results[count_of_results++]
						= { 0.0f, 0.0f, 0.0f, Poker::Combination::Full_house };
				}
			}
			//Care
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Care)) {
				//TODO
			}
			//Straight_flush
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Straight_flush)) {
				//TODO
			}
			//Royal_flush
			else if (predict_power == static_cast<std::uint8_t>(Poker::Combination::Royal_flush)) {
				//TODO
			}
		}
		return results;
	}
}