#include "../inc/Head.hpp"
#include "../inc/Header.hpp"

Head::Head()
{
    std::cout << "Head constructor called" << std::endl;
}

Head::Head(int x, int y): _x(x), _y(y)
{
    std::cout << "Head constructor called" << std::endl;
}
Head::~Head()
{
    std::cout << "Head deconstructor called" << std::endl;
}

int Head::getX()
{
    return this->_x;
}
int Head::getY()
{
    return this->_y;
}
void Head::setX(int x)
{
    _x = x;
}
void Head::setY(int y)
{
    _y = y;
}


bool Head::checkCollision(int x, int y) const {
        return (_x == x && _y == y);
    }

void Head::draw() const{
    glColor3f(1.0f, 0.0f, 0.0f);  // Set color to red
    glRectf(_x, _y, _x + _sqSize, _y + _sqSize);  // Draw a square
}


void Head::setPosition() {
     srand(time(nullptr));

        // Set position randomly between 5 and 48
        _x = rand() % 4 + 5; // Generates a random number between 5 and 48
        _y = rand() % 4 + 5;
        std::cout << "collectible position: x = " << _x << ", y = " << _y << std::endl;
    }