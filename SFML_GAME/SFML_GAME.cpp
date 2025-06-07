#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1440, 1080 }), "GAME RUNING!");
    sf::CircleShape shape(100.f);
    sf::Texture texture1;

    sf::RectangleShape paddle(sf::Vector2f(500.0f,500.f));
    paddle.setFillColor(sf::Color::Red);
    paddle.setPosition(sf::Vector2f(500.f, 900.f));

 
    sf::Texture BGTexture;
    BGTexture.setSmooth(false);
    if (!BGTexture.loadFromFile("../assets/images/background.jpg")) {

    }
    sf::Vector2u windowsize = window.getSize();
    sf::Vector2u BackgroundSize = BGTexture.getSize();

    float scaleX = static_cast <float>(windowsize.x) / BackgroundSize.x;
    float scaleY = static_cast<float>(windowsize.y) / BackgroundSize.y;
   

    sf::Sprite background(BGTexture);

    background.setScale(sf::Vector2f(scaleX, scaleY));
   

    if (!texture1.loadFromFile("D:/WebDeve/SFML/SFML_Projects/SFML_GAME/SFML_GAME/SFML_GAME/football.jpg")) {
        std::cout << "Failed to load!";
        
    }
    shape.setTexture(&texture1);



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
        

        window.clear();
        window.draw(background);
        window.draw(shape);
        window.draw(paddle);
        window.display();
    }
}
