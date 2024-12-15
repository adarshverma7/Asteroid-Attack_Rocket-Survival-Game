#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

// Helper function to load textures
sf::Texture loadTexture(const std::string& path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        throw std::runtime_error("Failed to load " + path);
    }
    return texture;
}

int main() {
    // Initialize window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Rocket Game");
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    int posX = (desktop.width - WINDOW_WIDTH) / 2; // Center X
    int posY = (desktop.height - WINDOW_HEIGHT) / 2; // Center Y
    window.setPosition(sf::Vector2i(posX, posY));
    window.setFramerateLimit(60);


    // Load assets
    sf::Texture rocketTexture = loadTexture("assets/rocket_frame1.png");
    sf::Texture asteroidTexture = loadTexture("assets/asteroids.png");

    // Rocket
    sf::Sprite rocket(rocketTexture);
    rocket.setPosition(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT - rocket.getGlobalBounds().height - 10);

    // Projectile
    std::vector<sf::RectangleShape> projectiles;
    sf::Clock projectileClock;

    // Asteroids
    std::vector<sf::Sprite> asteroids;
    sf::Clock asteroidSpawnClock;

    // Game state
    int score = 0;
    bool gameOver = false;

    // Use the default font provided by SFML
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        throw std::runtime_error("Failed to load default font");
    }
    sf::Text scoreText("Score: 0", font, 24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (!gameOver) {
            // Rocket movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && rocket.getPosition().x > 0) {
                rocket.move(-5.f, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
                rocket.getPosition().x + rocket.getGlobalBounds().width < WINDOW_WIDTH) {
                rocket.move(5.f, 0.f);
            }

            // Firing projectiles
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && projectileClock.getElapsedTime().asSeconds() > 0.2f) {
                sf::RectangleShape projectile(sf::Vector2f(5.f, 10.f));
                projectile.setFillColor(sf::Color::White);
                projectile.setPosition(rocket.getPosition().x + rocket.getGlobalBounds().width / 2.f - 2.5f,
                                       rocket.getPosition().y);
                projectiles.push_back(projectile);
                projectileClock.restart();
            }

            // Move projectiles
            for (auto& projectile : projectiles) {
                projectile.move(0.f, -8.f);
            }
            projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
                                             [](const sf::RectangleShape& p) {
                                                 return p.getPosition().y < 0;
                                             }),
                              projectiles.end());

            // Spawn asteroids
            if (asteroidSpawnClock.getElapsedTime().asSeconds() > 1.f) {
                sf::Sprite asteroid(asteroidTexture);
                asteroid.setPosition(rand() % (WINDOW_WIDTH - static_cast<int>(asteroid.getGlobalBounds().width)), 0);
                asteroids.push_back(asteroid);
                asteroidSpawnClock.restart();
            }

            // Move asteroids
            for (auto& asteroid : asteroids) {
                asteroid.move(0.f, 3.f + score * 0.1f);
            }
            asteroids.erase(std::remove_if(asteroids.begin(), asteroids.end(),
                                           [](const sf::Sprite& a) {
                                               return a.getPosition().y > WINDOW_HEIGHT;
                                           }),
                            asteroids.end());

            // Collision detection
            for (auto it = asteroids.begin(); it != asteroids.end();) {
                bool asteroidDestroyed = false;
                for (auto jt = projectiles.begin(); jt != projectiles.end();) {
                    if (it->getGlobalBounds().intersects(jt->getGlobalBounds())) {
                        jt = projectiles.erase(jt);
                        it = asteroids.erase(it);
                        score++;
                        asteroidDestroyed = true;
                        break;
                    } else {
                        ++jt;
                    }
                }
                if (!asteroidDestroyed) {
                    ++it;
                }
            }

            // Check for collision with rocket
            for (const auto& asteroid : asteroids) {
                if (asteroid.getGlobalBounds().intersects(rocket.getGlobalBounds())) {
                    gameOver = true;
                }
            }

            // Update score
            std::stringstream ss;
            ss << "Score: " << score;
            scoreText.setString(ss.str());
        }

        // Rendering
        window.clear(sf::Color::Red);
        window.draw(rocket);
        for (const auto& projectile : projectiles) {
            window.draw(projectile);
        }
        for (const auto& asteroid : asteroids) {
            window.draw(asteroid);
        }
        window.draw(scoreText);

        if (gameOver) {
            sf::Text gameOverText("Game Over! Press R to Restart", font, 32);
            gameOverText.setFillColor(sf::Color::White);
            gameOverText.setPosition(WINDOW_WIDTH / 2.f - gameOverText.getGlobalBounds().width / 2.f,
                                     WINDOW_HEIGHT / 2.f - gameOverText.getGlobalBounds().height / 2.f);
            window.draw(gameOverText);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                score = 0;
                gameOver = false;
                asteroids.clear();
                projectiles.clear();
                rocket.setPosition(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT - rocket.getGlobalBounds().height - 10);
            }
        }

        window.display();
    }

    return 0;
}
