#include "game.h"
#include "tortue.h"
#include "ligne.h"


game::game()
{
	Vm.height = 900;
	Vm.width = 1500;
	window = new sf::RenderWindow(Vm, "Logo", sf::Style::Titlebar | sf::Style::Close);
	nb_ins= 0;
	font.loadFromFile("arial.ttf");
	// bouton lance
	texte_bt_lance.setString("Lancer");
	texte_bt_lance.setColor(sf::Color::White);
	texte_bt_lance.setCharacterSize(30);
	texte_bt_lance.setFont(font);
	bouton_lance.setSize({200,100});
	bouton_lance.setFillColor({ 34, 139, 34 });
	bouton_lance.setPosition({ 0,700 });
	float xPos = ( (bouton_lance.getLocalBounds().width / 2) - (texte_bt_lance.getLocalBounds().width / 2));
	float yPos = (700 + (bouton_lance.getLocalBounds().height / 2) - (texte_bt_lance.getLocalBounds().height / 2));
	texte_bt_lance.setPosition(xPos, yPos);
	Over_lancer = false;
	// bouton nettoie
	texte_bt_nettoyer.setString("Nettoyer");
	texte_bt_nettoyer.setColor(sf::Color::White);
	texte_bt_nettoyer.setCharacterSize(30);
	texte_bt_nettoyer.setFont(font);
	bouton_nettoyer.setSize({ 200,100 });
	bouton_nettoyer.setFillColor({ 34, 139, 34 });
	bouton_nettoyer.setPosition({ 400,700 });
	float xPos1 = (400+(bouton_nettoyer.getLocalBounds().width / 2) - (texte_bt_nettoyer.getLocalBounds().width / 2));
	float yPos1= (700 + (bouton_nettoyer.getLocalBounds().height / 2) - (texte_bt_nettoyer.getLocalBounds().height / 2));
	texte_bt_nettoyer.setPosition(xPos1, yPos1);
	click_nettoyer = false;
}

game::~game()
{
	delete window;
}


void game::update()
{	

	while (window->pollEvent(ev))
	{
		//cout << "Mouse x: " << sf::Mouse::getPosition().x << ", y: " << sf::Mouse::getPosition().y << endl;
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
				string N2;
				float w;
				is >> N2 >> w; // Extraire un réel du flux
				intruction A = AvoirIntruct(N2);
				if (A != lancer)
				{
					instructions.push_back(A);
					historique.push_back(text.str());
					file.push_back(text.str());
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
		case sf::Event::MouseMoved:
			if (sf::Mouse::getPosition().x<374 && sf::Mouse::getPosition().x>267 && sf::Mouse::getPosition().y< 906 && sf::Mouse::getPosition().y> 875)
		{
				texte_bt_lance.setColor(sf::Color::Red);
				Over_lancer = true;
		}
			else {
				Over_lancer = false;
				texte_bt_lance.setColor(sf::Color::White);
			}
			if (sf::Mouse::getPosition().x < 780 && sf::Mouse::getPosition().x>655 && sf::Mouse::getPosition().y < 906 && sf::Mouse::getPosition().y> 870)
			{
				texte_bt_nettoyer.setColor(sf::Color::Red);

			}
			else {
				texte_bt_nettoyer.setColor(sf::Color::White);
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (sf::Mouse::getPosition().x < 374 && sf::Mouse::getPosition().x>267 && sf::Mouse::getPosition().y < 906 && sf::Mouse::getPosition().y> 875)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					lance = true;
				}
			
			}
			if (sf::Mouse::getPosition().x < 780 && sf::Mouse::getPosition().x>655 && sf::Mouse::getPosition().y < 906 && sf::Mouse::getPosition().y> 870)
			{
				click_nettoyer = true;

			}
			break;
		}

	}
	
}

void game::render()
{
	/*window->clear();
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
	window->display();*/
}

void game::InputText(sf::Event input)
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

void game::setFont(sf::Font& font)
{
	Textbox.setFont(font);
}

void game::setposition(sf::Vector2f pos)
{
	Textbox.setPosition(pos);
}

void game::est_select(bool sel)
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

void game::inputChar(int entree) {
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

void game::deletelastchar()
{
	string t = text.str();
	string newt = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newt += t[i];
	}
	text.str("");
	text << newt;
	Textbox.setString(text.str());
}