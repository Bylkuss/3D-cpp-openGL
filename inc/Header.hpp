#ifndef HEADER_HPP
#define HEADER_HPP

#include <GL/glut.h>
#include <iostream>
#include <string>



#define MAP_HEIGHT 500
#define MAP_WIDTH 500 

#define ESC 27
#define DOWN 0
#define UP 1
#define LEFT 2
#define RIGHT 3


#define X 0
#define Y 1


void displaySq(GLfloat pos[2], GLfloat r, GLfloat g, GLfloat b);

#include "Snake.hpp"
#include "Map.hpp"

#endif