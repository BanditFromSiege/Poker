#include "../WindowRender/PokerGame.h"

void PokerGame::Input() {
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed 
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
		{
			window.close();
		}
	}
}

void PokerGame::Update_frame(float iter_time) {
	//TODO
}

void PokerGame::Draw_frame() {
	window.clear();
	window.display();
}

PokerGame::PokerGame() : window(windowSize, windowTitle) {}

void PokerGame::RunGame()
{
	sf::Clock iter_time_clock;
	while (window.isOpen()) {
		sf::Time iter_time = iter_time_clock.restart();

		Input();
		Update_frame(iter_time.asSeconds());
		Draw_frame();
	}
}
