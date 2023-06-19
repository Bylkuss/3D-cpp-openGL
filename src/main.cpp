#include "../inc/Header.hpp"
#include <GL/glut.h>

int windowId; // Global variable to store the window ID

Map map;
Snake snake(5, 5);
Head head(50, 50);

void displaySnake(GLfloat x, GLfloat y)
{
    map.displayMap();
  
    // Set up the orthographic projection

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);
    // Switch back to the modelview matrix
    glMatrixMode(GL_MODELVIEW);
     glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_QUADS);
    glVertex2f(x * 10, y * 10);
    glVertex2f((x + 1) * 10, y * 10);
    glVertex2f((x + 1) * 10, (y + 1) * 10);
    glVertex2f(x * 10, (y + 1) * 10);

    glFlush();
    glEnd();
}

void displayMapCallback(void)
{
    int snakeX;
    int snakeY;

    map.displayMap();
    // Draw the snake
    snakeX = snake.getX();
    snakeY = snake.getY();
    // Set up the orthographic projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);
    // Switch back to the modelview matrix

    // glLoadIdentity();
    // GLfloat pos[2] = {(GLfloat)snakeX, (GLfloat)snakeY};
    map.updateSnakePosition(snakeX, snakeY);
    // std::cout << " (x: " << snakeX << ", y: " << snakeY << ")" << std::endl;
    // std::cout << "snakeY" << snakeY<< std::endl;
    // Set the color to green for the snake
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(snakeX * 10, snakeY * 10);
    glVertex2f((snakeX + 1) * 10, snakeY * 10);
    glVertex2f((snakeX + 1) * 10, (snakeY + 1) * 10);
    glVertex2f(snakeX * 10, (snakeY + 1) * 10);
    
    // glVertex2f(-1.0f / 250, -1.0f / 250);
    // glVertex2f(1.0f / 250, -1.0f / 250);
    // glVertex2f(1.0f / 250, 1.0f / 250);
    // glVertex2f(-1.0f / 250, 1.0f / 250);
    // glEnd();
    // glFlush(); // Flush the rendering pipeline


    // displaySnake(snakeX, snakeY);
}
void keyboardHandler(unsigned char key, int, int)
{
    // std::cout << "key pressed: " << key << std::endl;
    // logKey(key);
    
    if (key == ESC) // Check if the key is ESC (ASCII code 27)
    {
        glutDestroyWindow(windowId); // Close the window
        exit(0);                     // Exit the program
    }
    if (key == KEY_DOWN) // Check if the key is 'r' for moving to the right
    {
        snake.moveTo(DOWN);
        snake.move();        // Move the snake
        // glutPostRedisplay(); // Trigger a redraw of the window
    }
    if (key == KEY_UP) // Check if the key is 'r' for moving to the right
    {
        snake.moveTo(UP);
        snake.move();        // Move the snake
        // glutPostRedisplay(); // Trigger a redraw of the window
    }
    if (key == KEY_LEFT) // Check if the key is 'r' for moving to the right
    {
        snake.moveTo(LEFT);
        snake.move();        // Move the snake
        // glutPostRedisplay(); // Trigger a redraw of the window
    }
    if (key == KEY_RIGHT)
    // Check if the key is 'r' for moving to the right
    {
        snake.moveTo(RIGHT);
        snake.move();        // Move the snake
        // glutPostRedisplay(); // Trigger a redraw of the window
    }
    
}



void gameLoop(int)
{

    if (head.checkCollision(snake.getX(), snake.getY())) {
        // Handle collision logic here
        std::cout << "Collision detected" << std::endl;
        head.setPosition();
        GLfloat x = head.getX();
        GLfloat y = head.getY();
        displaySnake(x, y);

    }
    int delay = 100; // Delay in milliseconds
    // Move the snake continuously based on the current direction
    snake.moveTo(snake.getMovingDirection());
    snake.move();        // Move the snake
    glutPostRedisplay(); // Trigger a redraw of the window
    glutTimerFunc(delay, gameLoop, 0);
    

    // Set the game loop function to be called again after a delay
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(600, 100);
    glutCreateWindow("SnakeGame");
     // Start the game logic thread
    head.setPosition();
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // gray  background
    glutDisplayFunc(displayMapCallback);
    glutKeyboardFunc(keyboardHandler);
    glutTimerFunc(1000, gameLoop, 0);

    // Start the main loop

    // Register the keyboard callback function
    glutMainLoop();
    return (0);
}
