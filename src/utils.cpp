#include "../inc/Header.hpp"

void displaySq(GLfloat pos[2], GLfloat r, GLfloat g, GLfloat b)
{
    GLfloat sqSize = 1.0;
    glBegin(GL_LINE_LOOP);
    glColor3f(r, g, b);
    glVertex2f(pos[X], pos[Y]);
    glVertex2f(pos[X] + sqSize, pos[Y]);
    glVertex2f(pos[X] + sqSize, pos[Y] + sqSize);
    glVertex2f(pos[X], pos[Y] + sqSize);
    glEnd();
}
