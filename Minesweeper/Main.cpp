#include<iostream>
#include<SFML\Graphics.hpp>
#include "Minesweeper.h"
#include "Button.h"



int main()
{
	//create window 
	sf::RenderWindow window(sf::VideoMode(COLS*IMAGE_SIZE, ROWS*IMAGE_SIZE + 100), "Minesweeper", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	Minesweeper minesweeper;
	minesweeper.setPosition(0, 100);


	//load button textures
	sf::Texture playedButtonTexture;
	playedButtonTexture.loadFromFile("res/img/play.png");

	sf::Texture winButtonTexture;
	winButtonTexture.loadFromFile("res/img/win.png");

	sf::Texture loseButtonTexture;
	loseButtonTexture.loadFromFile("res/img/lose.png");

	//button for starting new game 
	Button play(IMAGE_SIZE, IMAGE_SIZE);
	play.setPos((COLS*IMAGE_SIZE - IMAGE_SIZE) / 2, 10.f);
	play.setTexture(playedButtonTexture);

	int bombCount = BOMBS;

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape) window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					minesweeper.pressRightButton(window);
					bombCount--;
				}
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (play.isMouseOver(window))
					{
						minesweeper.newGame();
						bombCount = BOMBS;
						play.setTexture(playedButtonTexture);
					}
					else
						minesweeper.pressLeftButton(window);
				}
			}
		}

		//drawing all objects on the window
		if (minesweeper.getStatus() == GameState::LOSER)
			play.setTexture(loseButtonTexture);
		if (minesweeper.getStatus() == GameState::WINNER)
			play.setTexture(winButtonTexture);
		window.clear(sf::Color(192, 192, 192));
		window.draw(minesweeper);
		window.draw(play);
		window.display();
	}
	return 0;
}