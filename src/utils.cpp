#include "../inc/Header.hpp"

void displaySq(GLfloat pos[2], GLfloat r, GLfloat g, GLfloat b)
{
    GLfloat sqSize = 1.5;
    glBegin(GL_LINE_LOOP);
    glColor3f(r, g, b);
    glVertex2f(pos[X], pos[Y]);
    glVertex2f(pos[X] + sqSize, pos[Y]);
    glVertex2f(pos[X] + sqSize, pos[Y] + sqSize);
    glVertex2f(pos[X], pos[Y] + sqSize);
    glEnd();
}


void logKey(unsigned char key)
{

    std::string str = "*random*";
    if(key == KEY_DOWN)
        str = "*DOWN*";
    else if(key == KEY_LEFT)
        str = "*LEFT*";
    else if(key == KEY_RIGHT)
        str =  "*RIGHT*";
    else if (key  == KEY_UP)
        str = "*UP*";
    if(str != "*random*")
        std::cout << "key pressed: " + str << std::endl;
}