#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1440, 1080 }), "Software Runing!");
    sf::RectangleShape shape(sf::Vector2f(100.f,100.f));
    shape.setFillColor(sf::Color::Cyan);
   
    sf::Texture bgtexture("D:/WebDeve/SFML/SFML_Projects/SFML_GAME/SFML_GAME/assets/images/background.jpg");
    sf::Sprite bgsprite(bgtexture);
    

    sf::Vector2u windowsize = window.getSize();
    sf::Vector2u texturesize = bgtexture.getSize();

    float scalex = static_cast<float>(windowsize.x) / texturesize.y;
    float scaley = static_cast<float>(windowsize.y) / texturesize.y;

    bgsprite.setScale(sf::Vector2f(scalex, scaley));

    sf::Texture texture1;
    if (!texture1.loadFromFile("D:/WebDeve/SFML/SFML_Projects/SFML_GAME/SFML_GAME/SFML_GAME/football.jpg")) {
        std::cout<<"ERROR IN LOADING THE FILE!n\n";
    }

    sf::RectangleShape shape3(sf::Vector2f(120.f,120.f));
    shape3.setTexture(&texture1);
    shape3.setPosition(sf::Vector2f(500.f, 800.f));



    sf::Texture sqauretexture("../assets/images/redball.jpg");
    sf::Sprite sqauresprite(sqauretexture);
    sqauresprite.setScale(sf::Vector2f(0.5f, 0.5f));
    sqauresprite.setPosition(sf::Vector2f(500.f, 200.f));
    



  
    

    

   

   



    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }


        shape.move(sf::Vector2f(0.f, 0.1f));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sf::Vector2i mousepos= sf::Mouse::getPosition(window);
            shape.setPosition(sf::Vector2f(mousepos));
        }
        sqauresprite.move(sf::Vector2f(0.0f, 0.1f));
       

        window.clear();
        window.draw(bgsprite);
        window.draw(shape3);
       // window.draw(square);
        window.draw(sqauresprite);

        window.display();
    }
}
