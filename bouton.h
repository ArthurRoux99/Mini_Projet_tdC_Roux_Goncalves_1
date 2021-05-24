#pragma once
#include "game.h"
#include "tortue.h"


//Cette classe n'a pas été utilisé dû à l'impossibilité d'utilisé sf::mouse::getposition(window) car chez nous window est renderwindow*
//néanmoins la déclaration de nos boutons a été faites en utilisant ces méthodes
//Classe gérant tous les éléments d'un bouton
//Auteurs: Mathilde Gonçalvès de Carvalho
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
	Bouton(string text, sf::Vector2f size, int charsize, sf::Color back, sf::Color texteColor)//constructeur
	{
		texte.setString(text);
		texte.setColor(texteColor);
		texte.setCharacterSize(charsize);
		bouton.setSize(size);
		bouton.setFillColor(back);
	};
	void setFont(sf::Font& font)//applique une police au bouton
	{
		texte.setFont(font);
	};
	void setSize()//applique une taille au nom sur le bouton
	{
		int taille = texte.getCharacterSize();
		texte.setCharacterSize(taille + 2);
	};

	void setBack(sf::Color color)//sélectionne une couleur en fond du bouton
	{
		bouton.setFillColor(color);
	};

	void setposition(sf::Vector2f pos)//positionne le bouton et fait que le texte soit centre dans le bouton
	{
		bouton.setPosition(pos);
		float xPos = (pos.x + (bouton.getLocalBounds().width / 2) - (texte.getLocalBounds().width / 2));
		float yPos = (pos.y + (bouton.getLocalBounds().height / 2) - (texte.getLocalBounds().height / 2));
		texte.setPosition(xPos, yPos);
	};

	void drawTo(sf::RenderWindow& window)//dessine le bouton sur la fenetre
	{
		window.draw(bouton);
		window.draw(texte);
	};
	
	bool isMouseOver(sf::RenderWindow window)//renvoi true si la souris est au dessus du bouton
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