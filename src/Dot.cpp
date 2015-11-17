#include "Dot.h"

unsigned int Dot::counter = 0;

Dot::Dot() : _number(counter++), _pos()
{
}

Dot::Dot(const sf::Vector2f &pos) : _number(counter++), _pos(pos)
{
}

Dot::~Dot()
{
}

std::ostream& operator<<(std::ostream& os, const Dot& dot)
{
    os << dot._number << " (" << dot._pos.x << ";" << dot._pos.y << ")";
}

unsigned int Dot::number() const
{
    return _number;
}

sf::Vector2f Dot::pos() const
{
    return _pos;
}
