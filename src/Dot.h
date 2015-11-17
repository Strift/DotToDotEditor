#ifndef DOT_H
#define DOT_H

#pragma GCC diagnostic ignored "-Weffc++" // disable Weffc++ warnings for SFML
#include <SFML/Graphics.hpp>
#pragma GCC diagnostic pop // turn the warnings back on

class Dot
{
    static unsigned int counter;

    public:
        Dot();
        Dot(const sf::Vector2f&);
        virtual ~Dot();

        friend std::ostream& operator<<(std::ostream& os, const Dot& dot);

        unsigned int number() const;
        sf::Vector2f pos() const;

    protected:
        unsigned int _number;
        sf::Vector2f _pos;

    private:
};

#endif // DOT_H
