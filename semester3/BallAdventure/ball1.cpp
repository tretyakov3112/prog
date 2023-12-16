#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>

int main()
{
    const int width = 800;
    const int height = 600;
    const int circleRadius = 20;
    const int trackWidth = 10;

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
    player.setPosition(width / 2 - circleRadius, height - 50);

    std::vector<sf::RectangleShape> track;
    srand(time(0));
    int trackLength = 2000;
    int trackHeight = height / 2;
    for (int i = 0; i < trackLength; i += 50)
    {
        sf::RectangleShape segment(sf::Vector2f(50, trackHeight));
        segment.setFillColor(sf::Color::Blue);
        segment.setPosition(i, height / 4);
        track.push_back(segment);
    }

    bool isPlaying = false;
    bool isWin = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && isPlaying && !isWin)
            {
                if (event.key.code == sf::Keyboard::Right)
                {
                    player.move(5, 0);
                    for (auto &segment : track)
                    {
                        segment.move(-5, 0);
                    }
                }
                else if (event.key.code == sf::Keyboard::Left)
                {
                    player.move(-5, 0);
                    for (auto &segment : track)
                    {
                        segment.move(5, 0);
                    }
                }
            }
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
                    for (auto &segment : track)
                    {
                        segment.setPosition(segment.getPosition().x, height / 4);
                    }
                }
            }
        }

        if (isPlaying && !isWin)
        {
            for (auto &segment : track)
            {
                if (segment.getGlobalBounds().intersects(player.getGlobalBounds()))
                {
                    isWin = true;
                    isPlaying = false;
                }
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
            for (auto &segment : track)
            {
                window.draw(segment);
            }
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

