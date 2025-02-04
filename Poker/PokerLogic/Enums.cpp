#include "Enums.h"

std::ostream& operator<<(std::ostream& out, Poker::Result res) noexcept {
	switch (res) {
		case Poker::Result::Draw : out << "Draw";
			break;
		case Poker::Result::Win : out << "Win";
			break;
		case Poker::Result::Loss : out << "Loss";
			break;
		default:
			break;
	}
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
