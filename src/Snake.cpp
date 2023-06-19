#include "../inc/Snake.hpp"

Snake::Snake()
{
    std::cout << "Snake constructor called" << std::endl;
}
Snake::Snake(int x, int y): _x(x), _y(y), _movingDirection(RIGHT)
{
    std::cout << "Snake constructor called" << std::endl;
}

void Snake::move()
{
    if (_movingDirection == LEFT)
        _x--;
    else if (_movingDirection == RIGHT)
        _x++;
    else if (_movingDirection == UP)
        _y--;
    else if (_movingDirection == DOWN)
        _y++;
}

void Snake::moveTo(int direction)
{
    _movingDirection = direction;
}


Snake::~Snake()
{
    std::cout << "Snake deconstructor called" << std::endl;
}
