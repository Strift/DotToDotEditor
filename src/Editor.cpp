#include "Editor.h"

#include <iostream>

/**
 * Constructeur à partir d'une fenêtre
 */
Editor::Editor(sf::RenderWindow &window, sf::Texture &texture) : _window(window), _running(true), _sprite(), _dots(), _font()
{
    _sprite.setTexture(texture);
    _font.loadFromFile("arial.ttf");
}

/**
 * Destructeur
 */
Editor::~Editor()
{
}


/**
 * Boucle principale du Jeu
 * Renvoie à l'application le Application::State suivant
 */
Application::State Editor::run()
{
    render();
    // on fait tourner la boucle principale
    while (_running)
    {
        // on gère les évènements
        sf::Event event;
        while (_window.pollEvent(event))
        {
            handle_event(event);
        }
    }
    return Application::State::Exiting;
}

/**
 * Fonction qui gère les évènements
 */
void Editor::handle_event(const sf::Event& event)
{
    if(event.type == sf::Event::Closed)
    {
        _running = false;
    }
    if (event.type == sf::Event::KeyPressed)
    {
        // Press Return to exit the editor
        if (event.key.code == sf::Keyboard::Return)
        {
            _running = false;
        }
    }
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i pixel_pos = sf::Mouse::getPosition(_window); // récupération de la position de la souris dans la fenêtre
            sf::Vector2f world_pos = _window.mapPixelToCoords(pixel_pos); // conversion en coordonnées "monde"
            // code here
            Dot dot(world_pos);
            _dots.push_back(dot);
            std::cout << dot << std::endl;
            render();
        }
    }
}

void Editor::render()
{
    _window.draw(_sprite);
    for (auto it = _dots.begin(); it != _dots.end(); it++)
        draw(*it);
    _window.display();
}

void Editor::draw(const Dot &dot)
{
    // Cross
    sf::RectangleShape horizontal(sf::Vector2f(7, 3)), vertical(sf::Vector2f(3, 7));
    horizontal.setPosition(dot.pos().x-3, dot.pos().y-1);
    vertical.setPosition(dot.pos().x-1, dot.pos().y-3);
    // Text
    sf::Text text(std::to_string(dot.number()), _font);
    text.setCharacterSize(12);
    text.setPosition(dot.pos().x - 5, dot.pos().y - 18);
    // Colors
    horizontal.setFillColor(sf::Color::Red);
    vertical.setFillColor(sf::Color::Red);
    text.setColor(sf::Color::Black);
    // Draw
    _window.draw(horizontal);
    _window.draw(vertical);
    _window.draw(text);
}


