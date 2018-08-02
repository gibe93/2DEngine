#include <SFML/Graphics.hpp>

int main(int argc, char** argv[])
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "First window!");

	sf::Texture Texture;
	Texture.loadFromFile("Assets/test.png");
	sf::Sprite hero(Texture);
	sf::Vector2u size = Texture.getSize();
	hero.setOrigin(size.x / 2, size.y / 2);
	sf::Vector2f increment(0.4f, 0.4f);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				// Close window button clicked.      
				window.close();
			}
		}
		if ((hero.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0) || (hero.getPosition().x - (size.x / 2) < 0 && increment.x < 0))
		{
			// Reverse the direction on X axis.        
			increment.x = -increment.x;
		}
		if ((hero.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0) || (hero.getPosition().y - (size.y / 2) < 0 && increment.y < 0))
		{

			// Reverse the direction on Y axis.        
			increment.y = -increment.y;
		}
		hero.setPosition(hero.getPosition() + increment);
		window.clear(sf::Color::Black);
		window.draw(hero);
		window.display();
	}
	return 0;
}