#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include<vector>
#include "Background.h"
 
using namespace std;
using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game", Style::Titlebar | Style::Close);
    
    sf::Texture backgroundTexture[3];
    backgroundTexture[0].loadFromFile("./backgrounds/background8.jpg");
    backgroundTexture[1].loadFromFile("./backgrounds/background8.jpg");
    backgroundTexture[2].loadFromFile("./backgrounds/background8.jpg");

    std::vector<Background> backgrounds;
    backgrounds.push_back(Background(&backgroundTexture[0], -60.f));
    backgrounds.push_back(Background(&backgroundTexture[1], -80.f));
    backgrounds.push_back(Background(&backgroundTexture[2], -60.f));

    float deltaTime = 0;
    Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
                    window.close();
                break;
                cout << char(event.text.unicode) << endl;
                break;
            default:
                break;
            }
        }

        for (Background& background : backgrounds)
            background.Update(deltaTime);
       
        window.clear();
        
        for (Background& background : backgrounds)
            background.Draw(window);

        window.display();
    }

    return 0;
}
