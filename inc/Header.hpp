#ifndef HEADER_HPP
#define HEADER_HPP

#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#define MAP_HEIGHT 500
#define MAP_WIDTH 500

#define ESC 27
#define KEY_F GLUT_KEY_RIGHT
#define KEY_S GLUT_KEY_LEFT
#define KEY_E GLUT_KEY_UP
#define KEY_D GLUT_KEY_DOWN

#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

#define WIDTH 500
#define HEIGHT 500

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};


#define X 0
#define Y 1

void displaySq(GLfloat pos[2], GLfloat r, GLfloat g, GLfloat b);
void logKey(unsigned char key);

#include "Snake.hpp"
#include "Map.hpp"

#endif