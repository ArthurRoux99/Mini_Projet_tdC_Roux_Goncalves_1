#pragma once

#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include <string>
#include <list>
#include<SFML/Network.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

#define delete_key 8
#define enter_key 13
#define escape_key 27

enum intruction
{
	avance,
	recule,
	droite,
	gauche,
	stylohaut,
	stylobas,
	lancer,
	repeter,
	finrepeter,
	infoinstruc,
	nettoyer,
	cachertortue,
	affichertortue,
	rien,
};


class game
{
protected:
	//Var
	int nb;
	sf::RenderWindow* window;
	sf::VideoMode Vm;
	sf::Event ev;
	sf::Text Textbox;
	sf::Font font;
	ostringstream text;
	vector<intruction> instructions;
	vector<string> historique;
	vector<string> file;
	sf::Text histo;
	int nb_ins;
	//Bouton lancer
	sf::RectangleShape bouton_lance;
	sf::Text texte_bt_lance;
	//Bouton nettoyer
	sf::RectangleShape bouton_nettoyer;
	sf::Text texte_bt_nettoyer;
	bool click_nettoyer;
	bool Over_lancer;
	bool Select_textbox;
	bool lance;
	void inputChar(int entree) {
		if (entree != delete_key && entree != enter_key && entree != escape_key)
		{
			text << static_cast<char>(entree);
		}
		else if (entree == delete_key)
		{
			if (text.str().length() > 0)
			{
				deletelastchar();
			}
		}
		Textbox.setString(text.str() + "_");
	}
	void deletelastchar()
	{
		string t = text.str();
		string newt = "";
		for ( int i = 0;  i < t.length()-1; i++)
		{
			newt += t[i];
		}
		text.str("");
		text << newt;
		Textbox.setString(text.str());
	}
public: 
	game(); //constructeur
	~game(); // destructeur
	// fonction
	const bool running()const {return window->isOpen();};
	void afficher_fenetre() { window->setVisible(true ) ; };
	void update();
	virtual void render();
	string getText() { return text.str(); };
	float mousepos() {};
	void creategame() { window->create(Vm, "Logo", sf::Style::Titlebar | sf::Style::Close); };
	intruction AvoirIntruct(string input) {
		if (input == "avance") return avance;
		if (input == "recule") return recule;
		if (input == "gauche") return gauche;
		if (input == "droite") return droite;
		if (input == "lancer") return lancer;
		if (input == "stylohaut") return stylohaut;
		if (input == "stylobas") return stylobas;
		if (input == "repeter") return repeter;
		if (input == "finrepeter") return finrepeter;
		if (input == "infoinstruct") return infoinstruc;
		if (input == "nettoyer") return nettoyer;
		if (input == "cachertortue") return cachertortue;
		if (input == "affichertortue") return affichertortue;
		//...
		else cout << "Ce n'est pas une intruction" << endl;
	};
	void InputText(sf::Event input)
	{
		if (Select_textbox)
		{
			int chartype = input.text.unicode;
			if (chartype < 128)
			{
				inputChar(chartype);
			}
		}
	}
	void setFont(sf::Font& font)
	{
		Textbox.setFont(font);
	}
	void setposition(sf::Vector2f pos)
	{
		Textbox.setPosition(pos);
	}
	void est_select(bool sel)
	{
		Select_textbox = sel;
		if (!sel)
		{
			string t = text.str();
			string newt = "";
			for (int i = 0; i < t.length() - 1; i++)
			{
				newt += t[i];
			}
			text.str("");
			text << newt;
			Textbox.setString(newt);
		}
	}
};

