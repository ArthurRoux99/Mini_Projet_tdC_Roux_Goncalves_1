#pragma warning(disable : 4996)
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
#include"menu.h"
#include "bouton.h"
#include "tortue.h"


int main()
{
	tortue game;
	int x = 0;
	do
	{
		game.dessiner_toutes_les_lignes();
		x = menu();
		switch (x)
		{

		case 1:
			//game.afficher_fenetre();
			game.creategame();
			while (game.running())
			{
				game.update();
				game.render();
			}
			break;
		case 2:
			game.Exporte_Historique();
			break;
		case 3:
			break;
		default:
			break;
		}

	} while (x!= 4);
	return 0;
}