#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
private:
	sf::RenderWindow window;
	sf::CircleShape shape;
	sf::RectangleShape rect;
public:
	Game() {
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		window.create(sf::VideoMode::getDesktopMode(), "SFML Works!", sf::Style::Fullscreen,settings);
		shape.setRadius(100.f);
		shape.setFillColor(sf::Color::White);
		shape.setOutlineColor(sf::Color::Red);
		shape.setOutlineThickness(20.f);
		shape.setPosition(100.f, 100.f);
		rect.setSize(sf::Vector2f(250.f, 75.f));
		rect.setFillColor(sf::Color::Blue);
		// set pos and origin of rect to the center of the shape
		rect.setPosition(shape.getPosition().x + shape.getRadius() - rect.getSize().x / 2, shape.getPosition().y + shape.getRadius() - rect.getSize().y / 2);
	}

	void run() {
		while (window.isOpen()) {

			// animate the circle shape with radius with time elapsed
			/*if (shape.getRadius() > 200.f) {
				shape.setRadius(100.f);
			}
			shape.setRadius(shape.getRadius() + 0.1);*/


			sf::Event e;

			while (window.pollEvent(e)) {
				if (e.type == sf::Event::Closed) {
					window.close();
				}
			}

			window.clear();
			window.draw(shape);
			window.draw(rect);
			window.display();
		}
	}
};


int main() {

	Game game;
	game.run();
	/*sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen()) {
		sf::Event e;

		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/


	return 0;
}