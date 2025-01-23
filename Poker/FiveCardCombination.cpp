#include "FiveCardCombination.h"

std::uint8_t FiveCardCombination::CombinationPower() const noexcept {
	return power;
}

char FiveCardCombination::HighCard() const noexcept {
	return high_card;
}

FiveCardCombination::FiveCardCombination() noexcept = default;

constexpr std::array<char, 4> FiveCardCombination::Kickers() const noexcept {
	return kickers;
}

FiveCardCombination::FiveCardCombination(std::vector<Card> lst) {
	if (lst.size() > 5) { throw std::runtime_error("Too many cards for combination"); }

	std::unordered_map<char, std::uint8_t> values;
	std::unordered_map<char, std::uint8_t> suits;

	for (Card c : lst) {
		++values[c.Power()];
		++suits[c.Suit()];
	}

	std::vector<std::pair<char, std::uint8_t>> player_cards(values.begin(), values.end());
	std::sort(player_cards.begin(), player_cards.end(), Tools::comparator);

	std::uint8_t flash_royal = 0;
	std::uint8_t street_flash = 0;
	std::uint8_t care = 0;
	std::uint8_t full_haus = 0;
	std::uint8_t flash = 0;
	std::uint8_t street = 0;
	std::uint8_t set = 0;
	std::uint8_t dobpare = 0;
	std::uint8_t pare = 0;

	if (suits.size() == 1) { ++flash; }

	//Street check;
	std::uint8_t street_series = 0;
	bool gap = false;
	for (std::uint8_t i = 1; i < player_cards.size(); ++i) {
		if (std::abs(Tools::cards.find(player_cards[i].first)->second 
			- Tools::cards.find(player_cards[i - 1].first)->second) == 1)
		{
			++street_series;
		} 
		else if (!gap) {
			gap = true;
		} else if (gap) {
			break;
		}
	}

	if (player_cards.back().first == 'A' && player_cards.front().first == '2') { ++street_series; }

	if (street_series == 4) { ++street; }

	if (street == 1 && flash == 1 && player_cards.back().first == 'A' && player_cards.front().first == 'T') {
		++flash_royal;
	}
	else if (street == 1 && flash == 1) { ++street_flash; }

	for (auto& [x, y] : player_cards) {
		if (y == 2) { ++pare; }
		else if (y == 3) { ++set; }
		else if (y == 4) { ++care; }
	}

	if (set == 1 && pare == 1) { ++full_haus; }
	else if (pare == 2) { ++dobpare; }

	// Power initialization
	std::vector<std::reference_wrapper<std::uint8_t>> res = {
		flash_royal, street_flash, care, full_haus, flash, street, set, dobpare, pare
	};

	std::uint8_t p = 9;
	for (std::uint8_t i = 0; i < res.size(); ++i, --p) {
		if (res[i] == 1) {
			power = p;
			break;
		}
	}

	// High_Card initialization
	bool ace_low = false;
	// no comb or flash or royal flash
	if (power == 0 || power == 5 || power == 9) {
		high_card = player_cards.back().first;
	}
	else if (power == 1) { // pair
		for (auto& [x, y] : player_cards) {
			if (y == 2) {
				high_card = x;
				break;
			}
		}
	}
	else if (power == 2) {  // dob pair
		for (auto& [x, y] : player_cards) {
			if (y == 2) {
				if (high_card == ' ') {
					high_card = x;
				}
				else if (Tools::cards.find(high_card)->second < Tools::cards.find(x)->second) {
					high_card = x;
				}
			}
		}
	}
	else if (power == 3 || power == 6) { // set or full haus
		for (auto& [x, y] : player_cards) {
			if (y == 3) {
				high_card = x;
				break;
			}
		}
	}
	else if (power == 7) { // care
		for (auto& [x, y] : player_cards) {
			if (y == 4) {
				high_card = x;
				break;
			}
		}
	} 
	else if (power == 4 || power == 8) { //street or street flash
		high_card = player_cards.back().first;
		if ((high_card == 'A' && gap) || (high_card == 'A' && player_cards.front().first == '2')) {
			high_card = player_cards[player_cards.size() - 2].first;
			ace_low = true;
		}
	}
	else {
		throw std::runtime_error("Error");
	}

	//kickers initialization
	std::uint8_t count_of_kickers = 0;
	for (auto& [x, y] : player_cards) {
		if (x != high_card) {
			for (std::uint8_t i = 0; i < y; ++i, ++count_of_kickers) {
				kickers[count_of_kickers] = x;
			}
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

FiveCardCombination::FiveCardCombination(std::string str) {
	if (str.size() > 14) { throw std::runtime_error("Too many cards for combination"); }

	std::vector<Card> vec;
	vec.reserve(5);

	for (std::uint8_t i = 0; i < str.size(); i += 3) {
		vec.push_back({str[i], str[i + 1]});
	}

	FiveCardCombination comb(std::move(vec));

	power = std::move(comb.power);
	high_card = std::move(comb.high_card);
	kickers = std::move(comb.kickers);
}

FiveCardCombination::FiveCardCombination(const char* str) 
	: FiveCardCombination::FiveCardCombination(std::string(str)) {}

void FiveCardCombination::Combination() const noexcept {
	switch (power) {
	case 9: std::cout << "Flash-Royal: " << "High cart - " << high_card;
		break;
	case 8: std::cout << "Street-Flash: " << "High cart - " << high_card;
		break;
	case 7: std::cout << "Care: " << "High cart - " << high_card;
		break;
	case 6: std::cout << "Full-Haus: " << "High cart - " << high_card;
		break;
	case 5: std::cout << "Flash: " << "High cart - " << high_card;
		break;
	case 4: std::cout << "Street: " << "High cart - " << high_card;
		break;
	case 3: std::cout << "Set: " << "High cart - " << high_card;
		break;
	case 2: std::cout << "Double pair: " << "High cart - " << high_card;
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
	if (comb1.CombinationPower() == comb2.CombinationPower()) {
		if (comb1.HighCard() == comb2.HighCard()) {
			auto kickers1 = comb1.Kickers();
			auto kickers2 = comb2.Kickers();
		
			for (std::uint8_t i = 0; i < kickers1.size(); ++i) {
				if ((kickers1[i] != ' ' && kickers2[i] != ' ') 
					&& (Tools::cards.find(kickers1[i])->second != Tools::cards.find(kickers2[i])->second))
				{
					return Tools::cards.find(kickers1[i])->second < Tools::cards.find(kickers2[i])->second;
				}
			}
			return false;
		}
		return Tools::cards.find(comb1.HighCard())->second < Tools::cards.find(comb2.HighCard())->second;
	}
	return comb1.CombinationPower() < comb2.CombinationPower();
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
	Result compare_combinations(FiveCardCombination comb1, FiveCardCombination comb2) {
		if (comb1 < comb2) { return Result::Loss; }
		else if (comb1 > comb2) { return Result::Win; }
		else { return Result::Draw; }
	}

	void Index(std::size_t n) {
		switch (n) {
		case 9: std::cout << "Flash-Royal ";
			break;
		case 8: std::cout << "Street-Flash ";
			break;
		case 7: std::cout << "Care ";
			break;
		case 6: std::cout << "Full-Haus ";
			break;
		case 5: std::cout << "Flash ";
			break;
		case 4: std::cout << "Street ";
			break;
		case 3: std::cout << "Set ";
			break;
		case 2: std::cout << "Double pair ";
			break;
		case 1: std::cout << "Pair ";
			break;
		case 0: std::cout << "Upper cart ";
			break;
		default: std::cout << "Error ";
			break;
		}
	}
}

std::ostream& operator<<(std::ostream& out, Poker::Result res) {
	if (res == Poker::Result::Draw) { out << "Draw"; }
	else if (res == Poker::Result::Win) { out << "Win"; }
	else { out << "Loss"; }
	return out;
}