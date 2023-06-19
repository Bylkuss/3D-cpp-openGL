#ifndef MAP_HPP
#define MAP_HPP

#include "Header.hpp"
#include "Snake.hpp"


class Map
{
private:
    /* data */
    int _width = 10;
    int _height = 20;
    int _map[500][500];
    GLfloat _bg[3] = {0.0, 0.0, 0.0};

public:
    Map(/* args */);
    void displayMap();
    /*getters an setters*/
    int getWidth();
    int getHeight();
    void updateSnakePosition(int x, int y)
    {
        _map[x][y] = 'S';
    }
    ~Map();
};

#endif