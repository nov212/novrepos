#pragma once
#pragma once
#include<SFML\Graphics.hpp>

class Button : public sf::Drawable, public sf::Transformable
{
private:
	sf::Texture buttonTexture;
	sf::RectangleShape button;
public:
	Button(float width, float height);
	void setTexture(sf::Texture& texture);
	bool isMouseOver(sf::RenderWindow& window);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setPos(float x, float y);
};
