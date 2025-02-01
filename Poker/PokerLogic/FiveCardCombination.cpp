#include "../PokerLogic/FiveCardCombination.h"

Poker::Combination FiveCardCombination::getPower() const noexcept {
	return power;
}

char FiveCardCombination::getHighCard() const noexcept {
	return high_card;
}

constexpr std::array<char, 4> FiveCardCombination::getKickers() const noexcept {
	return kickers;
}

FiveCardCombination::FiveCardCombination() noexcept = default;

FiveCardCombination::FiveCardCombination(const std::vector<Card>& vector_of_cards) {
	if (vector_of_cards.size() != 5) { 
		throw std::runtime_error("Not five cards for combination");
	}

	std::unordered_map<char, std::uint8_t> values;
	std::unordered_map<char, std::uint8_t> suits;

	for (Card c : vector_of_cards) {
		++values[c.Power()];
		++suits[c.Suit()];
	}

	std::vector<std::pair<char, std::uint8_t>> player_cards(values.begin(), values.end());
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

	if (suits.size() == 1) { ++flush; }

	//Street check;
	std::uint8_t straight_series = 0;
	for (std::uint8_t i = 1; i < player_cards.size(); ++i) {
		if (std::abs(Tools::cards.find(player_cards[i].first)->second 
			- Tools::cards.find(player_cards[i - 1].first)->second) == 1)
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
	std::vector<std::reference_wrapper<std::uint8_t>> res = {
		royal_flush, straight_flush, care, full_house, flush, straight, set, two_pair, pair
	};

	std::uint8_t p = 9;
	for (std::uint8_t i = 0; i < res.size(); ++i, --p) {
		if (res[i] == 1) {
			power = static_cast<Poker::Combination>(p);
			break;
		}
	}

	// High_Card initialization
	std::uint8_t count_of_kickers = 0;
	
	if (power == Poker::Combination::high_card || power == Poker::Combination::flush 
		|| power == Poker::Combination::royal_flush)
	{
		high_card = player_cards.back().first;
	}
	else if (power == Poker::Combination::pair) {
		for (auto [card, count] : player_cards) {
			if (count == 2) {
				high_card = card;
				break;
			}
		}
	}
	else if (power == Poker::Combination::two_pair) {
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
	else if (power == Poker::Combination::set) {
		for (auto [card, count] : player_cards) {
			if (count == 3) {
				high_card = card;
				break;
			}
		}
	}
	else if (power == Poker::Combination::full_house) {
		for (auto [card, count] : player_cards) {
			if (count == 3) {
				high_card = card;
			} else if (count == 2) {
				kickers[count_of_kickers++] = card;
			}
		}
	}
	else if (power == Poker::Combination::care) {
		for (auto [card, count] : player_cards) {
			if (count == 4) {
				high_card = card;
				break;
			}
		}
	} 
	else if (power == Poker::Combination::straight || power == Poker::Combination::straight_flush) {
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

FiveCardCombination::FiveCardCombination(std::initializer_list<Card> lst)
	: FiveCardCombination::FiveCardCombination(std::vector<Card>(std::move(lst))) {}

FiveCardCombination::FiveCardCombination(const std::string& string_of_cards) {
	if (string_of_cards.size() != 14) { 
		throw std::runtime_error("Not five cards for combination");
	}

	std::vector<Card> vector_of_cards;
	vector_of_cards.reserve(5);

	for (std::uint8_t i = 0; i < string_of_cards.size(); i += 3) {
		vector_of_cards.push_back({string_of_cards[i], string_of_cards[i + 1]});
	}

	FiveCardCombination combination(std::move(vector_of_cards));

	power = std::move(combination.power);
	high_card = std::move(combination.high_card);
	kickers = std::move(combination.kickers);
}

FiveCardCombination::FiveCardCombination(const char* string_of_cards) 
	: FiveCardCombination::FiveCardCombination(std::string(string_of_cards)) {}

void FiveCardCombination::ShowCombination() const noexcept {
	switch (static_cast<std::uint8_t>(power)) {
	case 9: std::cout << "Flush-Royal: " << "High cart - " << high_card;
		break;
	case 8: std::cout << "Straight-Flush: " << "High cart - " << high_card;
		break;
	case 7: std::cout << "Care: " << "High cart - " << high_card;
		break;
	case 6: std::cout << "Full-House: " << "High cart - " << high_card;
		break;
	case 5: std::cout << "Flush: " << "High cart - " << high_card;
		break;
	case 4: std::cout << "Straight: " << "High cart - " << high_card;
		break;
	case 3: std::cout << "Set: " << "High cart - " << high_card;
		break;
	case 2: std::cout << "Two pair: " << "High cart - " << high_card;
		break;
	case 1: std::cout << "Pair: " << "High cart - " << high_card;
		break;
	case 0: std::cout << "High cart - " << high_card;
		break;
	default: std::cout << "Error ";
		break;
	}
	std::cout << '\n';
}

bool operator<(FiveCardCombination comb1, FiveCardCombination comb2) noexcept {
	if (comb1.getPower() == comb2.getPower()) {
		if (comb1.getHighCard() == comb2.getHighCard()) {
			auto kickers1 = comb1.getKickers();
			auto kickers2 = comb2.getKickers();
		
			for (std::uint8_t i = 0; i < kickers1.size(); ++i) {
				if ((kickers1[i] != ' ' && kickers2[i] != ' ') 
					&& (Tools::cards.find(kickers1[i])->second != Tools::cards.find(kickers2[i])->second))
				{
					return Tools::cards.find(kickers1[i])->second < Tools::cards.find(kickers2[i])->second;
				}
			}
			return false;
		}
		return Tools::cards.find(comb1.getHighCard())->second < Tools::cards.find(comb2.getHighCard())->second;
	}
	return comb1.getPower() < comb2.getPower();
}

bool operator>(FiveCardCombination comb1, FiveCardCombination comb2) noexcept {
	return comb2 < comb1;
}

bool operator==(FiveCardCombination comb1, FiveCardCombination comb2) noexcept {
	return !(comb1 < comb2) && !(comb2 < comb1);
}

bool operator!=(FiveCardCombination comb1, FiveCardCombination comb2) noexcept {
	return !(comb1 == comb2);
}

bool operator<=(FiveCardCombination comb1, FiveCardCombination comb2) noexcept {
	return !(comb2 < comb1);
}

bool operator>=(FiveCardCombination comb1, FiveCardCombination comb2) noexcept {
	return comb2 <= comb1;
}

namespace Poker {
	Result compare_combinations(FiveCardCombination comb1, FiveCardCombination comb2) noexcept {
		if (comb1 < comb2) { return Result::Loss; }
		else if (comb1 > comb2) { return Result::Win; }
		else { return Result::Draw; }
	}
}

std::ostream& operator<<(std::ostream& out, Poker::Result res) noexcept {
	if (res == Poker::Result::Draw) { out << "Draw"; }
	else if (res == Poker::Result::Win) { out << "Win"; }
	else { out << "Loss"; }
	return out;
}

std::ostream& operator<<(std::ostream& out, Poker::Combination comb) noexcept {
	switch (static_cast<std::uint8_t>(comb)) {
	case 9: out << "Flush-Royal";
		break;
	case 8: out << "Straight-Flush";
		break;
	case 7: out << "Care";
		break;
	case 6: out << "Full-House";
		break;
	case 5: out << "Flush";
		break;
	case 4: out << "Straight";
		break;
	case 3: out << "Set";
		break;
	case 2: out << "Two pair";
		break;
	case 1: out << "Pair";
		break;
	case 0: out << "High cart";
		break;
	default: out << "Error";
		break;
	}
	return out;
}