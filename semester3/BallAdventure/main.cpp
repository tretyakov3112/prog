#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>

int main()
{
    const int width = 800;
    const int height = 600;
    const int circleRadius = 20;

    sf::RenderWindow window(sf::VideoMode(width, height), "Ball Adventure");

    sf::Font font;
    if (!font.loadFromFile("/Users/tretyakov3112/Desktop/prog/semester3/BallAdventure/sansation.ttf"))
    {
        std::cerr << "Error loading font file" << std::endl;
        return 1;
    }

    sf::Text title("Ball Adventure", font, 50);
    title.setFillColor(sf::Color::White);
    title.setPosition(width / 2 - title.getGlobalBounds().width / 2, 100);

    sf::Text startButton("Start", font, 30);
    startButton.setFillColor(sf::Color::White);
    startButton.setPosition(width / 2 - startButton.getGlobalBounds().width / 2, 300);

    sf::Text winText("You win!", font, 50);
    winText.setFillColor(sf::Color::White);
    winText.setPosition(width / 2 - winText.getGlobalBounds().width / 2, 100);

    sf::Text playAgainButton("Play again", font, 30);
    playAgainButton.setFillColor(sf::Color::White);
    playAgainButton.setPosition(width / 2 - playAgainButton.getGlobalBounds().width / 2, 300);

    sf::CircleShape player(circleRadius);
    player.setFillColor(sf::Color::Red);
    player.setPosition(width / 2 , height / 2 - circleRadius);

    sf::VertexArray track(sf::LineStrip, 2);
    // track[0].position = sf::Vector2f(0, 200 );
    // track[0].color = sf::Color::Blue;
    // track[1].position = sf::Vector2f(width,  800 );
    // track[1].color = sf::Color::Blue;
    sf::VertexArray lines(sf::LinesStrip, 4);
    lines[0].position = sf::Vector2f(100, 0);
    lines[1].position = sf::Vector2f(200, 0);
    lines[2].position = sf::Vector2f(300, 500);
    lines[3].position = sf::Vector2f(400, 200);

    bool isPlaying = false;
    bool isWin = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && !isPlaying)
            {
                if (startButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                    isPlaying = true;
                }
                if (playAgainButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                    isPlaying = true;
                    isWin = false;
                    player.setPosition(width / 2 - circleRadius, height - 50);
                }
            }
        }

        if (isPlaying && !isWin)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                player.move(5, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                player.move(-5, 0);
            }
        }

        window.clear();

        if (!isPlaying)
        {
            window.draw(title);
            window.draw(startButton);
        }
        else
        {
            sf::View view(sf::FloatRect(0, 0, width, height));
            view.setCenter(player.getPosition());
            window.setView(view);

            window.draw(lines);
            window.draw(player);
        }

        if (isWin)
        {
            window.draw(winText);
            window.draw(playAgainButton);
        }

        window.display();
    }

    return 0;
}
