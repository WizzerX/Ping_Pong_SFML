#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
	sf::RenderWindow Window(sf::VideoMode({ 1080,720 }), "GameRuning!");
	//paw setup
	sf::Texture PawTexture;
	if (!PawTexture.loadFromFile("../assets/images/paw.png")) {
		std::cout << "error in loading the pawtexture!\n";
	}
	sf::Sprite pawsprite(PawTexture);
	pawsprite.setScale(sf::Vector2f(0.5f, 0.5f));
	pawsprite.setPosition(sf::Vector2f(500.f, 1200.f));


	Window.setMouseCursorVisible(false);
	
	sf::Texture backgroundtexture;
	if (!backgroundtexture.loadFromFile("D:/WebDeve/SFML/SFML_Projects/SFML_GAME/SFML_GAME/assets/images/background.jpg")) {
		std::cout << "Error in loading the background!\n";
	}

	///background setup
	sf::Sprite backgroundsprite(backgroundtexture);

	sf::Vector2u backgroundsize = Window.getSize();
	sf::Vector2u texturesize = backgroundtexture.getSize();

	float scalex = static_cast<float>(backgroundsize.x) / texturesize.x;
	float scaley = static_cast<float>(backgroundsize.y) / texturesize.y;

	backgroundsprite.setScale(sf::Vector2f(scalex, scaley));

	sf::Vector2f ballVelocity(0.f, 0.5f); // Ball starts moving down
	//ball setup
	sf::Texture balltexture;
	if (!balltexture.loadFromFile("../assets/images/orangeball.png")) {
		std::cout << "error in load the ball texture!\n";
	}
	sf::Sprite ballsprite(balltexture);
	ballsprite.setScale(sf::Vector2f(0.5f, 0.5f));
	






	while (Window.isOpen()) {


		while (std::optional event = Window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				Window.close();
			}
			sf::Vector2i pos = sf::Mouse::getPosition(Window);
			float  posx = static_cast<float>(pos.x);
			//float  posy = static_cast<float>(pos.y);

			pawsprite.setPosition(sf::Vector2f(posx,510.f));


		}
		sf::FloatRect boundingpaw = pawsprite.getGlobalBounds();
		sf::FloatRect boundingball = ballsprite.getGlobalBounds();
		if (boundingball.findIntersection(boundingpaw)) {
			ballsprite.move(sf::Vector2f(0.0f, -0.5f));
			std::cout << "YES!\n";
		}else
		ballsprite.move(sf::Vector2f(0.f, 0.2f));
	

		Window.clear();
		Window.draw(backgroundsprite);
		Window.draw(pawsprite);
		Window.draw(ballsprite);
		Window.display();
	}



};
