#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>

int main()
{
    const int width = 800;
    const int height = 600;
    const int gridSize = 20;

    sf::RenderWindow window(sf::VideoMode(width, height), "Ball Adventure");

    sf::RectangleShape food(sf::Vector2f(gridSize, gridSize));
    food.setFillColor(sf::Color::Red);

    std::deque<sf::RectangleShape> snake;
    snake.push_front(sf::RectangleShape(sf::Vector2f(gridSize, gridSize)));
    snake.front().setFillColor(sf::Color::Green);
    snake.front().setPosition(width / 2, height / 2);

    sf::Clock clock;
    float timer = 0;
    float delay = 0.1;

    sf::Vector2i direction(1, 0);

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        timer += dt.asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up && direction.y != 1)
                    direction = sf::Vector2i(0, -1);
                else if (event.key.code == sf::Keyboard::Down && direction.y != -1)
                    direction = sf::Vector2i(0, 1);
                else if (event.key.code == sf::Keyboard::Left && direction.x != 1)
                    direction = sf::Vector2i(-1, 0);
                else if (event.key.code == sf::Keyboard::Right && direction.x != -1)
                    direction = sf::Vector2i(1, 0);
            }
        }

        if (timer > delay)
        {
            timer = 0;

            sf::Vector2f prevPos = snake.front().getPosition();
            sf::Vector2f newPos = prevPos + sf::Vector2f(direction.x * gridSize, direction.y * gridSize);

            if (newPos.x < 0 || newPos.x >= width || newPos.y < 0 || newPos.y >= height)
            {
                window.close();
                std::cout << "Game Over!" << std::endl;
            }

            snake.push_front(sf::RectangleShape(sf::Vector2f(gridSize, gridSize)));
            snake.front().setFillColor(sf::Color::Green);
            snake.front().setPosition(newPos);

            if (newPos == food.getPosition())
            {
                food.setPosition(rand() % (width / gridSize) * gridSize, rand() % (height / gridSize) * gridSize);
            }
            else
            {
                snake.pop_back();
            }
        }

        window.clear();

        window.draw(food);

        for (auto &s : snake)
        {
            window.draw(s);
        }

        window.display();
    }

    return 0;
}