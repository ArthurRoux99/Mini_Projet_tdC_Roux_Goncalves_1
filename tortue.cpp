

#include "tortue.h"



tortue::tortue()
{
    historique.clear();
    file.clear();
	texture.loadFromMemory(__turtle_png, 1479);
	sprite.setTexture(texture);
    pen_down = true;
    x = 900;
    y = 300;
    Textbox.setCharacterSize(30);
    Select_textbox = true;
    window->setVisible(false);
    if (Select_textbox)
    {
        Textbox.setString("_");
    }
    else {
        Textbox.setString("");
    }
    lance = false;
    tortue_visible = true;
    sprite.setPosition(x, y);
}

void tortue::render()
{
    window->setVisible(true);
    window->clear();
    int j = 0;
    bool test_rep=false;
    dessiner_toutes_les_lignes();
    sf::Font style;
    sf::RectangleShape rectangle;
    sf::RectangleShape rectangle1;
    sf::RectangleShape rectangle2;
    style.loadFromFile("arial.ttf");
    Textbox.setFont(style);
    Textbox.setColor(sf::Color::Black);
    setposition({ 900, 750 });
    rectangle.setSize({ 300,900 });
    rectangle.setPosition(0, 0);
    rectangle.setFillColor({ 34, 139, 34 });
    rectangle1.setSize({ 1500,200 });
    rectangle1.setPosition(0, 700);
    rectangle1.setFillColor({ 34, 139, 34 });
    rectangle2.setSize({ 400,100 });
    rectangle2.setPosition(850, 750);
    rectangle2.setFillColor({128,128,128});
    rectangle2.setOutlineThickness(10);
    rectangle2.setOutlineColor(sf::Color::Black);
   // string N1;
   // //cout << "entrez valeur" << endl;
   //// getline(cin, N1);
   // istringstream is(N1); // Flux d'entrée associé à la chaîne
   // string N2;
   // float w;
   // is >> N2 >> w; // Extraire un réel du flux
   // //cout << "N2 : " << N2 << " , X= " << x << endl;
   // switch (AvoirIntruct(N2))
   // {
   // case avance:
   //     cout << "avance de " << w << endl;
   //     Avance(w);
   //     cout << "X :" << x << "Y :" << y << endl;
   //     break;
   // case recule:
   //     cout << "recule de " << w << endl;
   //     Recule(w);
   //     cout << "X :" << x << "Y :" << y << endl;
   //     break;
   // case gauche:
   //     cout << "Va a gauche de " << w << endl;
   //     Gauche(w);
   //     cout << "X :" << x << "Y :" << y << endl;
   //     break;
   // case droite:
   //     cout << "Va a droite de " << w << endl;
   //     Droite(w);
   //     cout << "X :" << x << "Y :" << y << endl;
   //     break;
   // case rien:
   //     cout << "Instruction n'existe pas" << endl;
   //     break;
   // default:
   //     break;
   // }
    //Avance(150);
    //Gauche(200);
    //Recule(200);
    //sf::FileStream stream;
    //stream.open("image.png");

    //sf::Texture texture;
    //texture.loadFromStream(stream);
    if (click_nettoyer == true)
    {
        Nettoyer();
        click_nettoyer = false;
    }
    if (lance == true)
    {
        for (auto instruct : file)
        {
            istringstream is(instruct); // Flux d'entrée associé à la chaîne
            string N2;
            float w;
            is >> N2 >> w; // Extraire un réel du flux
            intruction A = AvoirIntruct(N2);
            switch (A)
                 {
                 case avance:
                     cout << "avance de " << w << endl;
                     Avance(w);
                     cout << "X :" << x << "Y :" << y << endl;
                     sprite.setPosition(x-16, y-32);
                     sprite.setRotation(0);
                     break;
                 case recule:
                     cout << "recule de " << w << endl;
                     Recule(w);
                     cout << "X :" << x << "Y :" << y << endl;
                     sprite.setPosition(x+16, y+32);
                     sprite.setRotation(180);
                     break;
                 case gauche:
                     cout << "Va a gauche de " << w << endl;
                     Gauche(w);
                     cout << "X :" << x << "Y :" << y << endl;
                     sprite.setPosition(x-32, y+16);
                     sprite.setRotation(270);
                     break;
                 case droite:
                     cout << "Va a droite de " << w << endl;
                     Droite(w);
                     cout << "X :" << x << "Y :" << y << endl;
                     sprite.setPosition(x+32, y-16);
                     sprite.setRotation(90);
                     break;
                 case stylohaut:
                     lever_crayon();
                     break;
                 case stylobas:
                     poser_crayon();
                     break;
                 case cachertortue:
                     tortue_visible = false;
                     break;
                 case affichertortue:
                     tortue_visible = true;
                     break;
                 case rien:
                     cout << "Instruction n'existe pas" << endl;
                     break;
                 case nettoyer:
                     Nettoyer();
                     break;
                 case repeter:
                     cout << "repeter" << endl;
                     for (auto rep:file)
                     {
                         istringstream is(rep); // Flux d'entrée associé à la chaîne
                         string repetition;
                         float nombre;
                         is >> repetition >> nombre; // Extraire un réel du flux
                         intruction C = AvoirIntruct(repetition);
                         if (C== finrepeter)
                         {
                             test_rep = false;
                         }
                         if (test_rep)
                         {
                             act_repeter.push_back(rep);
                         }
                         if (C == repeter)
                         {
                             test_rep = true;
                         }
                     }
                     for (int b = 0; b < w - 1; b++)
                     {
                         for (auto repetition : act_repeter)
                         {
                            //cout << repetition << endl;
                             istringstream is(repetition); // Flux d'entrée associé à la chaîne
                             string action_repeter;
                             float valeur;
                             is >> action_repeter >> valeur; // Extraire un réel du flux
                             intruction A = AvoirIntruct(action_repeter);
                             switch (A)
                             {
                             case avance:
                                 cout << "avance de " << valeur << endl;
                                 Avance(valeur);
                                 cout << "X :" << x << "Y :" << y << endl;
                                 sprite.setPosition(x - 16, y - 32);
                                 sprite.setRotation(0);
                                 break;
                             case recule:
                                 cout << "recule de " << valeur << endl;
                                 Recule(valeur);
                                 cout << "X :" << x << "Y :" << y << endl;
                                 sprite.setPosition(x + 16, y + 32);
                                 sprite.setRotation(180);
                                 break;
                             case gauche:
                                 cout << "Va a gauche de " << valeur << endl;
                                 Gauche(valeur);
                                 cout << "X :" << x << "Y :" << y << endl;
                                 sprite.setPosition(x - 32, y + 16);
                                 sprite.setRotation(270);
                                 break;
                             case droite:
                                 cout << "Va a droite de " << valeur << endl;
                                 Droite(valeur);
                                 cout << "X :" << x << "Y :" << y << endl;
                                 sprite.setPosition(x + 32, y - 16);
                                 sprite.setRotation(90);
                                 break;
                             case stylohaut:
                                 lever_crayon();
                                 break;
                             case stylobas:
                                 poser_crayon();
                                 break;
                             case cachertortue:
                                 tortue_visible = false;
                                 break;
                             case affichertortue:
                                 tortue_visible = true;
                                 break;
                             case rien:
                                 cout << "Instruction n'existe pas" << endl;
                                 break;
                             case nettoyer:
                                 Nettoyer();
                                 break;
                             }
                        }
                     }
                    break;
                 case finrepeter:
                     break;
                 default:
                     break;
                 }
        }
        file.clear();
        lance = false;
    }
    window->draw(rectangle);
    window->draw(rectangle1);
    window->draw(rectangle2);
    for (auto i : historique)
    {
        histo.setFont(style);
        histo.setString(i);
        histo.setCharacterSize(25);
        histo.setColor(sf::Color::Black);
        histo.setPosition(10,10+ j* 10);
        window->draw(histo);
        j+=2;

    }
    //sprite.setPosition(x, y);
    window->draw(bouton_lance);
    window->draw(texte_bt_lance);
    window->draw(bouton_nettoyer);
    window->draw(texte_bt_nettoyer);
    if (tortue_visible == true)
    {
        window->draw(sprite);
    }
    window->draw(Textbox);
    window->display();
}

void tortue::Avance(float i)
{
	ligne f(x, y, x , y-i , sf::Color::White);
    if (pen_down)
    {
        lignes.push_back(f);
    }
    y = y - i;
    dessiner_ligne(f);
}

void tortue::Recule(float i)
{
    ligne f(x, y, x, y + i, sf::Color::White);
    if (pen_down)
    {
        lignes.push_back(f);
    }
    y = y + i;
    dessiner_ligne(f);
}

void tortue::Gauche(float i)
{
    ligne f(x, y, x-i, y , sf::Color::White);
    if (pen_down)
    {
        lignes.push_back(f);
    }
    x = x - i;
    dessiner_ligne(f);
}

void tortue::Droite(float i)
{
    ligne f(x, y, x + i, y, sf::Color::White);
    if (pen_down)
    {
        lignes.push_back(f);
    }
    x = x + i;
    dessiner_ligne(f);
}

void tortue::poser_crayon()
{
    pen_down = true;
}

void tortue::lever_crayon()
{
    pen_down = false;
}

void tortue::Nettoyer()
{
        x = 900;
        y = 300;
        sprite.setPosition(x, y);
        historique.clear();
        lignes.clear();
        dessiner_toutes_les_lignes();
}

void tortue::dessiner_ligne(ligne l)
{
    dessiner_toutes_les_lignes();
    if (pen_down)
    {
        sf::Vertex line_vertices[2] = {
            sf::Vertex(sf::Vector2f(l.GetXi(),l.GetYi())),
            sf::Vertex(sf::Vector2f(l.GetXf(), l.GetYf()))
        };
        line_vertices[0].color = sf::Color::White;
        line_vertices[1].color = sf::Color::White;
        window->draw(line_vertices, 2, sf::Lines);
    }
}

void tortue::dessiner_toutes_les_lignes()
{

        window->clear(sf::Color::Black);
    for (auto line : lignes)
    {
        sf::Vertex line_vertices[2] = {
            sf::Vertex(sf::Vector2f( line.GetXi(), line.GetYi())),
            sf::Vertex(sf::Vector2f( line.GetXf(), line.GetYf()))
        };
        line_vertices[0].color = sf::Color::White;
        line_vertices[1].color = sf::Color::White;
        window->draw(line_vertices, 2, sf::Lines);
    }
}

void tortue::Exporte_Historique()
{
    string const monFichier("historique.txt");
    ofstream monFlux(monFichier.c_str());
    string exp;
    if (monFlux)
    {
        for (auto i : historique)
        {
            exp = i;
            monFlux << i << endl;
            cout << i << endl;
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}

void tortue::Importe_Historique()
{
    historique.clear();
    ifstream fichier("Importation.txt");

    if (fichier)
    {
        //L'ouverture s'est bien passée, on peut donc lire

        string entre; //Une variable pour stocker les lignes lues

        while (getline(fichier, entre)) //Tant qu'on n'est pas à la fin, on lit
        {
            historique.push_back(entre);
            file.push_back(entre);
            cout << entre << endl;
            //Et on l'affiche dans la console
            //Ou alors on fait quelque chose avec cette ligne
            //À vous de voir
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}