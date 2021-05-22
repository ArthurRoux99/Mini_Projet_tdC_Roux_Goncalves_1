#include "game.h"
#include "tortue.h"
#include "ligne.h"


game::game()
{
	Vm.height = 900;
	Vm.width = 1500;
	window = new sf::RenderWindow(Vm, "Logo", sf::Style::Titlebar | sf::Style::Close);
	nb_ins= 0;
	//window->setVisible(false);
	//Bouton LanceExec("Lancer", { 80, 30 }, 40, { 128, 128, 128 }, sf::Color::Black);
}

game::~game()
{
	delete window;
}


void game::update()
{	

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		est_select(true);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		est_select(false);
	}*/
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
			{
				window->close();
			}
			if (ev.key.code == sf::Keyboard::Enter)
			{
				istringstream is(text.str()); // Flux d'entrée associé à la chaîne
				historique.push_back(text.str());
				string N2;
				float w;
				is >> N2 >> w; // Extraire un réel du flux
				intruction A = AvoirIntruct(N2);
				if (A != lancer)
				{
					instructions.push_back(A);
					nb_ins++;
				}
				else
				{
					lance = true;
				}
				text.str("");
			}
			break;
		case sf::Event::TextEntered:
			InputText(ev);
			break;
		/*case sf::Event::MouseMoved:
			sf::RenderWindow test = window;
			if (LanceExec.isMouseOver(window))
			{
				LanceExec.setSize();
			}*/
		}
	}
}

void game::render()
{
	window->clear();
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(10, 10)),
		sf::Vertex(sf::Vector2f(300, 300))
	};
	sf::Vertex line1[] =
	{
		sf::Vertex(sf::Vector2f(300, 300)),
		sf::Vertex(sf::Vector2f(50, 300))
	};

	window->draw(line, 2, sf::Lines);
	window->draw(line1, 2, sf::Lines);
	window->display();
}
