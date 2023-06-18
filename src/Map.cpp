#include "../inc/Map.hpp"
#include <stdio.h>

Map::Map(): _width(15), _height(10)
    {

        // Initialize the map
        for (int i = 0; i < _width; i++)
        {
            for (int j = 0; j < _height; j++)
            {
                if(i == 0 || i == _width - 1 || j == 0 || j == _height - 1)
                    _map[i][j] = '#';
                else if((j == 3 || j == 4  || j == 5) && (i==2))
                    _map[i][j] = 'S';
                else
                    _map[i][j] = ' ';

            }
        }
        for (int i = 0; i < _width; i++)
        {
            for (int j = 0; j < _height; j++)
            {
                printf("%c ", _map[i][j]);
                // std::cout << _map[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

void Map::displayMap()
{
    const int gridSize = 20;
    const float squareSize = 1.0 / gridSize;
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer

    // Set the color to red
    glColor3f(1.0, 0.0, 0.0);

    // Draw the grid of squares
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            // Calculate the coordinates of the current square
            float x = j * squareSize - 0.5;
            float y = i * squareSize - 0.5;

            // Draw the square border
            glBegin(GL_LINE_LOOP);
            glVertex2f(x, y);
            glVertex2f(x + squareSize, y);
            glVertex2f(x + squareSize, y + squareSize);
            glVertex2f(x, y + squareSize);
            glEnd();
        }
    }

    glFlush();  // Flush the rendering pipeline
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
