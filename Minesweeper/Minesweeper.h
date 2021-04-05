#pragma once
#pragma once
#include<SFML\Graphics.hpp>
#include "Config.h"
#include "Game.h"



class Minesweeper : public sf::Drawable, public sf::Transformable
{
private:
	sf::Texture zeroTexture;
	sf::Texture numOneTexture;
	sf::Texture numTwoTexture;
	sf::Texture numThreeTexture;
	sf::Texture numFourTexture;
	sf::Texture numFiveTexture;
	sf::Texture numSixTexture;
	sf::Texture numSevenTexture;
	sf::Texture numEightTexture;
	sf::Texture closedTexture;
	sf::Texture openedTexture;
	sf::Texture flagedTexture;
	sf::Texture bombTexture;
	sf::Texture bombedTexture;
	sf::Texture nobombTexture;
	void loadTextures();
	Game* game;
public:
	Minesweeper();
	void pressRightButton(sf::RenderWindow& window);
	void pressLeftButton(sf::RenderWindow& window);
	bool isMouseOver(sf::RenderWindow& window);
	GameState getStatus();
	int getWidth();
	int getHeight();
	void newGame();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
