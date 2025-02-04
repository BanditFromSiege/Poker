#pragma once

#include "../Headers.h"

namespace Poker {
	enum class Combination : std::uint8_t {
		High_card,
		Pair,
		Two_pair,
		Set,
		Straight,
		Flush,
		Full_house,
		Care,
		Straight_flush,
		Royal_flush
	};

	enum class Result : std::uint8_t {
		Draw, 
		Win, 
		Loss
	};

	enum class Stages : std::uint8_t {
		Begin,
		Preflop, 
		Flop,
		Tern,
		River,
		End
	};
}

std::ostream& operator<<(std::ostream& out, Poker::Result res) noexcept;
std::ostream& operator<<(std::ostream& out, Poker::Combination comb) noexcept;