#pragma once

#include "Headers.h"

class PokerGame {
private:
	const sf::VideoMode windowSize = {1920, 1080};
	const std::string windowTitle = "Poker";

	sf::RenderWindow window{};

	void Input();
	void Update_frame(float iter_time);
	void Draw_frame();
	/*
	void KeyPress(sf::Keyboard::Key key);
	void MousePress(sf::Mouse::Button mousebutton);
	*/
public:
	PokerGame();
	void RunGame();
};

