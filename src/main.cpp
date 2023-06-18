#include "../inc/Header.hpp"
#include <GL/glut.h>

int windowId; // Global variable to store the window ID

Map map;
void displayMapCallback()
{
   
    map.displayMap();
}
void keyboardHandler(unsigned char key, int, int)
{
    if (key == ESC) // Check if the key is ESC (ASCII code 27)
    {
        glutDestroyWindow(windowId); // Close the window
        exit(0); // Exit the program
    }
}


int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1080, 1920);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("SnakeGame");
    glClearColor(0.5f, 0.5f, 0.5f, 0.5f); // gray  background
    glutDisplayFunc(displayMapCallback);
    glutKeyboardFunc(keyboardHandler); // Register the keyboard callback function
    glutMainLoop();
    return 0;
}
