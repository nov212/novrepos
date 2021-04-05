#include "Minesweeper.h"
#include "Ranges.h"

Minesweeper::Minesweeper()
{
	loadTextures();
	game = new Game(ROWS, COLS, BOMB);
}

void Minesweeper::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	sf::Sprite rect;
	for (Coord coord : Ranges::getAllCoords())
	{
		rect.setPosition(static_cast<float>(coord.getX()*IMAGE_SIZE), static_cast<float>(coord.getY()*IMAGE_SIZE));
		switch (game->getCell(coord))
		{
		case ZERO:
			rect.setTexture(zeroTexture);
			break;
		case NUM1:
			rect.setTexture(numOneTexture);
			break;
		case NUM2:
			rect.setTexture(numTwoTexture);
			break;
		case NUM3:
			rect.setTexture(numThreeTexture);
			break;
		case NUM4:
			rect.setTexture(numFourTexture);
			break;
		case NUM5:
			rect.setTexture(numFiveTexture);
			break;
		case NUM6:
			rect.setTexture(numSixTexture);
			break;
		case NUM7:
			rect.setTexture(numSevenTexture);
			break;
		case NUM8:
			rect.setTexture(numEightTexture);
			break;
		case BOMB:
			rect.setTexture(bombTexture);
			break;
		case OPENED:
			rect.setTexture(openedTexture);
			break;
		case CLOSED:
			rect.setTexture(closedTexture);
			break;
		case FLAGED:
			rect.setTexture(flagedTexture);
			break;
		case BOMBED:
			rect.setTexture(bombedTexture);
			break;
		case NOBOMB:
			rect.setTexture(nobombTexture);
			break;
		default:
			break;
		}
		target.draw(rect, states);
	}

}


void Minesweeper::loadTextures()
{
	zeroTexture.loadFromFile("res/img/zero.png");

	numOneTexture.loadFromFile("res/img/num1.png");

	numTwoTexture.loadFromFile("res/img/num2.png");

	numThreeTexture.loadFromFile("res/img/num3.png");

	numFourTexture.loadFromFile("res/img/num4.png");

	numFiveTexture.loadFromFile("res/img/num5.png");

	numSixTexture.loadFromFile("res/img/num6.png");

	numSevenTexture.loadFromFile("res/img/num7.png");

	numEightTexture.loadFromFile("res/img/num8.png");

	closedTexture.loadFromFile("res/img/closed.png");

	openedTexture.loadFromFile("res/img/opened.png");

	flagedTexture.loadFromFile("res/img/flaged.png");

	bombTexture.loadFromFile("res/img/bomb.png");

	bombedTexture.loadFromFile("res/img/bombed.png");

	nobombTexture.loadFromFile("res/img/nobomb.png");
}

void Minesweeper::pressRightButton(sf::RenderWindow& window)
{
	if (isMouseOver(window))
	{
		sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
		Coord cellCoord((mouseCoords.x - this->getPosition().x) / IMAGE_SIZE, (mouseCoords.y - this->getPosition().y) / IMAGE_SIZE);
		game->pressRightButton(cellCoord);
	}
}
void Minesweeper::pressLeftButton(sf::RenderWindow& window)
{
	if (isMouseOver(window))
	{
		sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
		Coord cellCoord((mouseCoords.x - this->getPosition().x) / IMAGE_SIZE, (mouseCoords.y - this->getPosition().y) / IMAGE_SIZE);
		game->pressLeftButton(cellCoord);
	}
}

GameState Minesweeper::getStatus()
{
	return game->getStatus();
}

int Minesweeper::getWidth()
{
	return Ranges::getSize().getX()*IMAGE_SIZE;
}

int Minesweeper::getHeight()
{
	return Ranges::getSize().getY()*IMAGE_SIZE;
}

bool Minesweeper::isMouseOver(sf::RenderWindow& window)
{
	sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
	sf::Vector2f fieldPosition = this->getPosition();

	if (mouseCoords.x > fieldPosition.x && mouseCoords.x < fieldPosition.x + getWidth() &&
		mouseCoords.y>fieldPosition.y && mouseCoords.y < fieldPosition.y + getWidth())
		return true;
	return false;
}

void Minesweeper::newGame()
{
	delete game;
	game = new Game(ROWS, COLS, BOMB);
}