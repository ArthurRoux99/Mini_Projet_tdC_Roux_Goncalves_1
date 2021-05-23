#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;


//fonction de menu affichant une image en fonction de la position de la souris
//retourne 1,2,3,4 correspondant à un élément du menu
int menu()
{
    RenderWindow window(VideoMode(800,800),"Interpreteur Logo!" , Style::Titlebar | Style::Close);
    window.setFramerateLimit(8);
    window.setVerticalSyncEnabled(true);
   
    int x=0,n=0,i=1;
    Texture t1, t2, t3, t4, t5;
    t1.loadFromFile("image_mini_proj/menu1.png");
    t2.loadFromFile("image_mini_proj/menu2.png");
    t3.loadFromFile("image_mini_proj/menu3.png");
    t4.loadFromFile("image_mini_proj/menu4.png");
    t5.loadFromFile("image_mini_proj/menu5.png");


    Sprite Menu(t1), Dessiner(t2), Importer(t3), Exporter(t4), Quitter(t5);

    SoundBuffer buff;
    buff.loadFromFile("audios/son.ogg");
    Sound sound(buff);
    sound.setLoop(true);
    sound.setVolume(10);

    Font font;
    font.loadFromFile("image_mini_proj/tscope.ttf");
    
    //tant que la fenêtre est ouverte
    while(window.isOpen())
    {
        Event ev;
        while(window.pollEvent(ev))
        {
            if(ev.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
                return 4;
            }
                
        }
        //on recupere la position sf::vecteur2f
        auto var = Mouse::getPosition(window);
        //cout << "Mouse x: " << sf::Mouse::getPosition().x << ", y: " << sf::Mouse::getPosition().y << endl;

        if((var.x > 67 && var.x < 311) && (var.y > 100 && var.y < 200)) x=1;
        //on vérifie si cela correspond au bouton 1 du menu
        if((var.x > 67 && var.x < 311) && (var.y > 220 && var.y < 320)) x=2;
        //on vérifie si cela correspond au bouton 2 du menu
        if((var.x > 67 && var.x < 311) && (var.y > 342 && var.y < 444)) x=3;
        //on vérifie si cela correspond au bouton 3 du menu
        if((var.x > 67 && var.x < 311) && (var.y > 462 && var.y < 560)) x=4;
        //on vérifie si cela correspond au bouton 4 du menu
        if(n==0) sound.play();
        n++;

        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            x--;
        }

        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            x++;
        }

        if(x==1 && (Keyboard::isKeyPressed(Keyboard::Enter) || Mouse::isButtonPressed(Mouse::Left)) && i<2) return 1;
        if(x==2 && (Keyboard::isKeyPressed(Keyboard::Enter) || Mouse::isButtonPressed(Mouse::Left)) && (i<2))
        {
            i=2;
            return 2;
        }
        if(x==3 && (Keyboard::isKeyPressed(Keyboard::Enter) || Mouse::isButtonPressed(Mouse::Left)) && (i<2))
        {
            i=3;
            return 3;
        }
        if(x==4 && (Keyboard::isKeyPressed(Keyboard::Enter) || Mouse::isButtonPressed(Mouse::Left)) && (i<2))
        {
            i=4;
        }

        if(x>4)
            x=1;
        if(x<0)
            x=4;

       if(i<2)
       {
            if(x==0) window.draw(Menu);
            if(x==1) window.draw(Dessiner);
            if(x==2) window.draw(Importer);
            if(x==3) window.draw(Exporter);
            if(x==4) window.draw(Quitter);
       }
       else{
        if(x==2 && i==2) return 2;
        if(Keyboard::isKeyPressed(Keyboard::Escape)) return 4;
        if(x==3 && i==3) return 3;
        if(x==4 && i==4) return 4;
       }
        window.display();
    }
    return 0;
}
