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

// declaration code unicode correspondant aux touches delete, entree, echap
#define delete_key 8
#define enter_key 13
#define escape_key 27

//enum comportant toutes les intructions pouvant �tre entr�e
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

// La classe game est la classe m�re de tortue. elle g�re tout ce qui est �venement sur la page, organisation de la fen�tre avec des bordure, mais aussi des �l�ment comme une
//textbox et des boutons
class game
{
protected:
	//Var
	int nb;
	sf::RenderWindow* window; //fenetre de jeu
	sf::VideoMode Vm;//parametre video de la fenetre
	sf::Event ev;// evenement lie a la page
	//variable textbox
	sf::Text Textbox;//textebox sur la page de jeu
	sf::Font font;// permet de stocker une police de caract�re
	ostringstream text;
	//vector pour le stockage d'information
	vector<intruction> instructions;
	vector<string> historique;
	vector<string> file;
	sf::Text histo; // permet l'affichage de l'historique en direct
	int nb_ins;
	//Bouton lancer
	sf::RectangleShape bouton_lance;
	sf::Text texte_bt_lance;
	bool lance;
	bool Over_lancer;
	//Bouton nettoyer
	sf::RectangleShape bouton_nettoyer;
	sf::Text texte_bt_nettoyer;
	bool click_nettoyer;
	bool Select_textbox;
	void inputChar(int entree);//fonction prive permettant d'utiliser les caract�re transformer gr�ce au code unicode d'un carat�re 
	//et permet de l'afficher il permet aussi de g�rer les actions lors de l'appui sur entr�e
	void deletelastchar();//permet de g�rer le fait d'appuyer sur la touche supprim�e 
public: 
	game(); //constructeur avec initialisation des boutons
	~game(); // destructeur
	// fonction
	const bool running()const {return window->isOpen();};//renvoie vrai si la fenetre jeu est ouverte
	void afficher_fenetre() { window->setVisible(true ) ; };//permet de param�trer la fenetre comme visible
	void update();// cette fonction g�re tout ce qui est event sur la page clique, appuie sur une touche du clavier,etc et applique des fonctions selon l'�v�nement
	virtual void render();//permet l'affichage d'objet entre display et clear ici d�clarer en virtual pour les tests la fonction render est tr�s important dans tortue
	string getText() { return text.str(); };// r�cup�re le texte de la textebox
	void creategame() { window->create(Vm, "Logo", sf::Style::Titlebar | sf::Style::Close); };//cr�e la fenetre de jeu en fonction des param�tre
	void InputText(sf::Event input);//transforme les caract�re tap�s gr�ce au code unicode
	void setFont(sf::Font& font);//r�cup�re la police de caract�re
	void setposition(sf::Vector2f pos);//positionne la textbox
	void est_select(bool sel);//g�re si la textbox est s�lectionn�
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
	// fonction qui permet de r�cup�rer une instruction en fonction d'un string en param�tre. cela permet d'effctuer un switch par la suite
};

