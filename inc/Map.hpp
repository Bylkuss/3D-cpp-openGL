#ifndef MAP_HPP
#define MAP_HPP


#include "Header.hpp"
#include "Snake.hpp"


#define UP 1
#define LEFT 2
#define RIGHT 3

class Map
{
private:
    /* data */
    int _width = 15;
    int _height = 10;
    int _map[500][500];
    GLfloat _bg[3] = {0.0, 0.0, 0.0};

public:
    Map(/* args */);
    void displayMap();
    /*getters an setters*/
    int getWidth();
    int getHeight();
    ~Map();
};



#endif