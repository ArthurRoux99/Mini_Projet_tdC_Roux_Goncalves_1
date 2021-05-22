#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

int menu()
{
    RenderWindow window(VideoMode(800,800),"Interpreteur Logo!" , Style::Titlebar | Style::Close);
    window.setFramerateLimit(8);
    window.setVerticalSyncEnabled(true);
   
    int x=0,n=0,i=1;
    Texture t1, t2, t3, t4, t5, t6, t7;
    t1.loadFromFile("image_mini_proj/menu1.png");
    t2.loadFromFile("image_mini_proj/menu2.png");
    t3.loadFromFile("image_mini_proj/menu3.png");
    t4.loadFromFile("image_mini_proj/menu4.png");
    t5.loadFromFile("image_mini_proj/menu5.png");


    Sprite sMenu(t1), sNg(t2), sObj(t3), sHs(t4), sAbt(t5);

    SoundBuffer buff;
    buff.loadFromFile("audios/bg.ogg");
    Sound sound(buff);
    sound.setLoop(true);
    sound.setVolume(20);

    Font font;
    font.loadFromFile("image_mini_proj/tscope.ttf");
    

    while(window.isOpen())
    {
        Event e;
        while(window.pollEvent(e))
        {
            if(e.type == Event::Closed)
                window.close();
        }

        auto var = Mouse::getPosition(window);

        if((var.x > 67 && var.x < 311) && (var.y > 100 && var.y < 200)) x=1;
        if((var.x > 67 && var.x < 311) && (var.y > 220 && var.y < 320)) x=2;
        if((var.x > 67 && var.x < 311) && (var.y > 342 && var.y < 444)) x=3;
        if((var.x > 67 && var.x < 311) && (var.y > 462 && var.y < 560)) x=4;

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
        }
        if(x==3 && (Keyboard::isKeyPressed(Keyboard::Enter) || Mouse::isButtonPressed(Mouse::Left)) && (i<2))
        {
            i=3;
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
            if(x==0) window.draw(sMenu);
            if(x==1) window.draw(sNg);
            if(x==2) window.draw(sObj);
            if(x==3) window.draw(sHs);
            if(x==4) window.draw(sAbt);
       }
       else{
        if(x==2 && i==2) return 2;
        if(Keyboard::isKeyPressed(Keyboard::Escape)) i=0;
        if(x==3 && i==3) return 3;
        if(x==4 && i==4) return x;
       }
        window.display();
    }
    return 0;
}
