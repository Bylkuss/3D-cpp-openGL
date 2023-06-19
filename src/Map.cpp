#include "../inc/Map.hpp"

Map::Map()
{

    // Initialize the map
    for (int i = 0; i < _width; i++)
    {
        for (int j = 0; j < _height; j++)
        {
            if (i == 0 || i == _width - 1 || j == 0 || j == _height - 1)
                _map[i][j] = '#';
            else if ((j == 3 || j == 4 || j == 5) && (i == 2))
                _map[i][j] = 'S';
            else
                _map[i][j] = ' ';
        }
    }
    for (int i = 0; i < _width; i++)
    {

        for (int j = 0; j < _height; j++)
        {
            std::cout << static_cast<char>(_map[i][j]);
        }
        std::cout << std::endl;
    }
}

void Map::displayMap()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    // Set the color to red
    glColor3f(0.0, 0.0, 0.0);

    // Draw the square border
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    glFlush(); // Flush the rendering pipeline
}

int Map::getWidth()
{
    return this->_width;
}

int Map::getHeight()
{
    return this->_height;
}

Map::~Map()
{
}
