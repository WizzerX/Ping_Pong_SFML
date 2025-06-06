#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1440, 1080 }), "GAME RUNING!");
    sf::CircleShape shape(100.f);
    sf::Texture texture1;

    if (!texture1.loadFromFile("download (1).jpg")) {
        printf("error in loading the file \n");
        return 0;

    }
    shape.setTexture(&texture1);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sf::Vector2i mousepos= sf::Mouse::getPosition(window);
            shape.setPosition(sf::Vector2f(mousepos));
       }
        

        window.clear();
        window.draw(shape);
        window.display();
    }
}
