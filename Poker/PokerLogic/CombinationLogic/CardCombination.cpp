#include "CardCombination.h"

CardCombination CardCombination::find_best_six_cards(const std::vector<Card>& vec_of_cards) {
	if (vec_of_cards.size() != 6) {
		throw std::runtime_error("Not six cards for combination");
	}

	std::vector<std::vector<Card>> combinations = {
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[5] },
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[5], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[5], vec_of_cards[3], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[5], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] },
		{ vec_of_cards[5], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] },
	};

	CardCombination res = combinations[0];
	for (std::uint8_t i = 1; i < combinations.size(); ++i) {
		res = std::max(res, CardCombination(combinations[i]));
	}

	return res;
}

CardCombination CardCombination::cast_string_six_cards(const std::string& str_of_cards) {
	if (str_of_cards.size() != 17) {
		throw std::runtime_error("Not six cards for combination");
	}
	
	std::vector<Card> vector_of_cards;
	vector_of_cards.reserve(6);

	for (std::uint8_t i = 0; i < str_of_cards.size(); i += 3) {
		vector_of_cards.push_back({ str_of_cards[i], str_of_cards[i + 1] });
	}

	return find_best_six_cards(vector_of_cards);
}

CardCombination CardCombination::find_best_seven_cards(const std::vector<Card>& vec_of_cards) {
	if (vec_of_cards.size() != 7) {
		throw std::runtime_error("Not seven cards for combination");
	}

	std::vector<std::vector<Card>> combinations = {
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] },

		{ vec_of_cards[5], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[5], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[5], vec_of_cards[3], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[5], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[5] },

		{ vec_of_cards[6], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[6], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[6], vec_of_cards[3], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[6], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[6] },

		{ vec_of_cards[5], vec_of_cards[6], vec_of_cards[2], vec_of_cards[3], vec_of_cards[4] },
		{ vec_of_cards[5], vec_of_cards[1], vec_of_cards[6], vec_of_cards[3], vec_of_cards[4] },
		{ vec_of_cards[5], vec_of_cards[1], vec_of_cards[2], vec_of_cards[6], vec_of_cards[4] },
		{ vec_of_cards[5], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[6] },

		{ vec_of_cards[0], vec_of_cards[6], vec_of_cards[5], vec_of_cards[3], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[6], vec_of_cards[2], vec_of_cards[5], vec_of_cards[4] },
		{ vec_of_cards[0], vec_of_cards[6], vec_of_cards[2], vec_of_cards[3], vec_of_cards[5] },

		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[2], vec_of_cards[5], vec_of_cards[6] },
		{ vec_of_cards[0], vec_of_cards[1], vec_of_cards[5], vec_of_cards[3], vec_of_cards[6] },
		{ vec_of_cards[5], vec_of_cards[1], vec_of_cards[2], vec_of_cards[3], vec_of_cards[6] }
	};

	CardCombination res = combinations[0];
	for (std::uint8_t i = 1; i < combinations.size(); ++i) {
		res = std::max(res, CardCombination(combinations[i]));
	}

	return res;
}

CardCombination CardCombination::cast_string_seven_cards(const std::string& str_of_cards) {
	if (str_of_cards.size() != 20) {
		throw std::runtime_error("Not seven cards for combination");
	}

	std::vector<Card> vector_of_cards;
	vector_of_cards.reserve(7);

	for (std::uint8_t i = 0; i < str_of_cards.size(); i += 3) {
		vector_of_cards.push_back({ str_of_cards[i], str_of_cards[i + 1] });
	}

	return find_best_seven_cards(vector_of_cards);
}

Poker::Combination CardCombination::getPower() const noexcept {
	return power;
}

char CardCombination::getHighCard() const noexcept {
	return high_card;
}

constexpr std::array<char, 4> CardCombination::getKickers() const noexcept {
	return kickers;
}

CardCombination::CardCombination() noexcept = default;

CardCombination::CardCombination(const std::vector<Card>& vector_of_cards) {
	if (vector_of_cards.size() == 7) {
		CardCombination result = find_best_seven_cards(vector_of_cards);

		power = std::move(result.power);
		high_card = std::move(result.high_card);
		kickers = std::move(result.kickers);
	}
	else if (vector_of_cards.size() == 6) {
		CardCombination result = find_best_six_cards(vector_of_cards);

		power = std::move(result.power);
		high_card = std::move(result.high_card);
		kickers = std::move(result.kickers);
	}
	else if (vector_of_cards.size() != 5) { 
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
		std::uint8_t count_of_kickers = 0;

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
					kickers[count_of_kickers++] = card;
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
					kickers[count_of_kickers++] = card;
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
		for (auto [card, count] : player_cards) {
			if (card != high_card) {
				kickers[count_of_kickers++] = card;
			}
		}
		std::reverse(kickers.begin(), kickers.end());

		if (ace_low) {
			for (std::uint8_t i = 0; i + 1 < kickers.size(); ++i) {
				std::swap(kickers[i], kickers[i + 1]);
			}
		}
	}
}

CardCombination::CardCombination(std::initializer_list<Card> lst)
	: CardCombination::CardCombination(std::vector<Card>(std::move(lst))) {}

CardCombination::CardCombination(const std::string& string_of_cards) {
	std::vector<Card> vector_of_cards;
	vector_of_cards.reserve(7);

	for (std::uint8_t i = 0; i < string_of_cards.size(); i += 3) {
		vector_of_cards.push_back({string_of_cards[i], string_of_cards[i + 1]});
	}

	CardCombination combination(std::move(vector_of_cards));

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
	if (comb1.getPower() == comb2.getPower()) {
		if (comb1.getHighCard() == comb2.getHighCard()) {
			auto kickers1 = comb1.getKickers();
			auto kickers2 = comb2.getKickers();
		
			for (std::uint8_t i = 0; i < kickers1.size(); ++i) {
				if ((kickers1[i] != ' ' && kickers2[i] != ' ') 
					&& (Tools::cards(kickers1[i]) != Tools::cards(kickers2[i])))
				{
					return Tools::cards(kickers1[i]) < Tools::cards(kickers2[i]);
				}
			}
			return false;
		}
		return Tools::cards(comb1.getHighCard()) < Tools::cards(comb2.getHighCard());
	}
	return comb1.getPower() < comb2.getPower();
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

	std::int8_t find_outs(const std::string& string_of_cards, Poker::Combination comb, Poker::Stages stage) {
		if (stage <= Poker::Stages::Preflop || stage >= Poker::Stages::River || comb == Poker::Combination::High_card) {
			throw std::runtime_error("Uncorrected values");
		}

		if ((stage == Poker::Stages::Preflop && string_of_cards.size() != 5) ||
			(stage == Poker::Stages::Flop && string_of_cards.size() != 14) ||
			(stage == Poker::Stages::Tern && string_of_cards.size() != 17))
		{
			throw std::runtime_error("Uncorrected count of cards for this stage");
		}

		CardCombination combination = string_of_cards;
		Poker::Combination current_power = combination.getPower();

		if (current_power >= comb) {
			return -1;
		}

		if (comb == Poker::Combination::Pair) {
			switch (stage) {
				case Poker::Stages::Flop: return 5 * 3 * 2;
				case Poker::Stages::Tern: return 6 * 3 * 2;
			}
		}
		else if (comb == Poker::Combination::Set) {
			if (current_power == Poker::Combination::Pair) {
				switch (stage) {
					case Poker::Stages::Flop: return 2 * 2;
					case Poker::Stages::Tern: return 2 * 2;
				}
			}
			else {
				return -1;
			}
		}
		else if (comb == Poker::Combination::Straight) {
			std::unordered_map<char, std::uint8_t> values;
			//TODO

			for (std::uint8_t i = 0; i < string_of_cards.size(); i += 3) {
				++values[i];
				//TODO
			}

			std::vector<std::pair<char, std::uint8_t>> player_cards(values.begin(), values.end());

			std::uint8_t straight_series = 0;
			for (std::uint8_t i = 1; i < player_cards.size(); ++i) {
				if (std::abs(Tools::cards(player_cards[i].first)
					- Tools::cards(player_cards[i - 1].first)) == 1)
				{
					++straight_series;
					//TODO
				}
			}

			bool ace_low = false;
			if (player_cards.back().first == 'A' && player_cards.front().first == '2') {
				++straight_series;
				ace_low = true;
			}

			if (straight_series == 3) {
				//TODO
			}

		}
		else if (comb == Poker::Combination::Flush) {
			std::unordered_map<char, std::uint8_t> suits;
			//TODO
		}
		//TODO
	}
}