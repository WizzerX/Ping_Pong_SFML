#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

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

	sf::Vector2f ballVelocity(0.f, 0.1f); // Ball starts moving down
	//ball setup
	sf::Texture balltexture;
	if (!balltexture.loadFromFile("../assets/images/orangeball.png")) {
		std::cout << "error in load the ball texture!\n";
	}
	sf::Sprite ballsprite(balltexture);
	ballsprite.setScale(sf::Vector2f(0.3f, 0.3f));
	ballsprite.setPosition(sf::Vector2f(150.f, 50.f));
	
	//upper wall
	sf::RectangleShape upperwall(sf::Vector2f(1100,5));
	//upperwall.setScale(sf::Vector2f(0.9, 0.3));
	upperwall.setFillColor(sf::Color::Red);
	upperwall.setPosition(sf::Vector2(00.f, 00.f));
	sf::Texture walltexture;
	upperwall.setTexture(&walltexture);
	sf::FloatRect upwallbound = upperwall.getGlobalBounds();

	//left wall
	sf::RectangleShape leftwall(sf::Vector2f(5.f, 1111.f));
	leftwall.setFillColor(sf::Color::Yellow);
	leftwall.setPosition(sf::Vector2(00.f, 00.f));
	sf::FloatRect leftwallbound = leftwall.getGlobalBounds();




	//right wall
	sf::RectangleShape rightwall(sf::Vector2f(5.f, 1150));
	rightwall.setFillColor(sf::Color::White);
	rightwall.setPosition(sf::Vector2(1075.f, 0.f));
	sf::FloatRect rightwallbound = rightwall.getGlobalBounds();


	//bottom wall
	sf::RectangleShape bottomwall(sf::Vector2f(1200.f, 5.f));
	bottomwall.setFillColor(sf::Color::White);
	bottomwall.setPosition(sf::Vector2(0.f, 715.f));
	sf::FloatRect bottomwallbound = bottomwall.getGlobalBounds();


	std::srand(std::time(0));

	while (Window.isOpen()) {
		
		
	

		while (std::optional event = Window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				Window.close();
			}
			sf::Vector2i pos = sf::Mouse::getPosition(Window);
			float  posx = static_cast<float>(pos.x);
			//float  posy = static_cast<float>(pos.y);
			if (posx >= 3 && posx <= 955) {
				pawsprite.setPosition(sf::Vector2f(posx, 510.f));
				
			}

		}
		sf::FloatRect boundingpaw = pawsprite.getGlobalBounds();
		sf::FloatRect boundingball = ballsprite.getGlobalBounds();
		if (boundingball.findIntersection(boundingpaw)) {
			int randomnumber = std::rand() % 10;
			float ballXaxis;

			if (randomnumber % 2 == 0) {

				ballXaxis = -0.1;
			}
			else {
				ballXaxis = 0.1;
			}
			ballVelocity.y *= -1;
			ballVelocity.x = ballXaxis;

			std::cout << randomnumber << "\n";
			
			//ballsprite.setRotation(sf::Angle(sf::degrees(180.f)));
			std::cout << "YES!\n";
		}
		else if (upwallbound.findIntersection(boundingball)) {
			std::cout << "ooo yesh!\n";
			ballVelocity.y *= -1;
			ballVelocity.x *= 1;
			
			//ballsprite.setRotation(sf::Angle(sf::degrees(10.f)));

		}
		else if (leftwallbound.findIntersection(boundingball)) {
			std::cout << "left wall hit!\n";
			ballVelocity.x *= -1;
			//ballsprite.setRotation(sf::Angle(sf::degrees(50.f)));
		}
		else if (rightwallbound.findIntersection(boundingball)) {
			std::cout << "right wall Hit!\n";
			ballVelocity.x *= -1;
		}
		
		

		ballsprite.move(sf::Vector2f(ballVelocity));
	

		Window.clear();
		Window.draw(backgroundsprite);
		Window.draw(pawsprite);
		Window.draw(ballsprite);
		Window.draw(upperwall);
		Window.draw(leftwall);
		Window.draw(rightwall);
		Window.draw(bottomwall);
		Window.display();


	}



};
