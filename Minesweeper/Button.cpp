#include "Button.h"

Button::Button(float width, float height)
{
	button.setSize(sf::Vector2f(width, height));
}

void Button::setTexture(sf::Texture& texture)
{
	button.setTexture(&texture);
}

bool Button::isMouseOver(sf::RenderWindow& window)
{
	sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
	sf::Vector2f buttonPosition = this->getPosition();

	if (mouseCoords.x > buttonPosition.x && mouseCoords.x < buttonPosition.x + button.getSize().x &&
		mouseCoords.y>buttonPosition.y && mouseCoords.y < buttonPosition.y + button.getSize().y)
		return true;
	return false;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(button, states);
}

void Button::setPos(float x, float y)
{
	this->setPosition(x, y);
	button.setPosition(x, y);
}
