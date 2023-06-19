#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Header.hpp"

class Snake
{
private:
    /* data */
    int _x = 5;
    int _y = 5;
    int _movingDirection = RIGHT;

    // void moveLeft()
    // {
    //     _movingDirection = LEFT;
    // }
    // void moveRight()
    // {
    //     _movingDirection = LEFT;
    // }

public:
    Snake();
    Snake(int x, int y);
    
    int getX() const { return _x; }
    int getY() const { return _y; }
    int getMovingDirection() { return _movingDirection; }

    void move();
    void moveTo(int direction);
    ~Snake();
};

#endif