#pragma once
#include "game.h"
#include "tortue.h"

class Bouton
{
	sf::RectangleShape bouton;
	sf::Text texte;
	string text;
	sf::Vector2f size;
	int charsize; sf::Color back;
	sf::Color texteColor;
public:
	Bouton();
	Bouton(string text, sf::Vector2f size, int charsize, sf::Color back, sf::Color texteColor)
	{
		texte.setString(text);
		texte.setColor(texteColor);
		texte.setCharacterSize(charsize);
		bouton.setSize(size);
		bouton.setFillColor(back);
	};
	void setFont(sf::Font& font)
	{
		texte.setFont(font);
	};
	void setSize()
	{
		int taille = texte.getCharacterSize();
		texte.setCharacterSize(taille + 2);
	};
	void setBack(sf::Color color)
	{
		bouton.setFillColor(color);
	};

	void setposition(sf::Vector2f pos)
	{
		bouton.setPosition(pos);
		float xPos = (pos.x + (bouton.getLocalBounds().width / 2) - (texte.getLocalBounds().width / 2));
		float yPos = (pos.y + (bouton.getLocalBounds().height / 2) - (texte.getLocalBounds().height / 2));
		texte.setPosition(xPos, yPos);
	};

	void drawTo(sf::RenderWindow& window)
	{
		window.draw(bouton);
		window.draw(texte);
	};
	
	bool isMouseOver(sf::RenderWindow window)
	{
		float xMouse = sf::Mouse::getPosition(window).x;
		float yMouse = sf::Mouse::getPosition(window).y;
		float Btnxi = bouton.getPosition().x;
		float Btnyi = bouton.getPosition().y;
		float Btnxf = bouton.getPosition().x + bouton.getLocalBounds().width;
		float Btnyf = bouton.getPosition().y + bouton.getLocalBounds().height;

		if (xMouse<Btnxf && xMouse>Btnxi&& yMouse < Btnyf && yMouse > Btnyi)
		{
			return true;
		}
		return false;
	};
};