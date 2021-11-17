#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;
int x, y;
float i, j;
void myInit(void)
{

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set window size in X- and Y- direction
    gluOrtho2D(-1000, 1000, -500, 500);
}

void display(void)
{
    // Outer loop to make figure moving
    // loop variable j iterated up to 10000,
    // indicating that figure will be in motion for large amount of time
    // around 10000/6.29 = 1590 time it will revolve
    // j is incremented by small value to make motion smoother
    for (j = 0; j < 10000; j += 0.01)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f);
        // Iterate i up to 2*pi, i.e., 360 degree
        // plot point with slight increment in angle,
        // so, it will look like a continuous figure

        // Loop is to draw outer circle
        for (i = 0; i < 6.29; i += 0.001)
        {
            x = 200 * cos(i);
            y = 200 * sin(i);
            glVertex2i(x, y);

            // For every loop, 2nd glVertex function is
            // to make smaller figure in motion
            
           
            glVertex2i(x / 4 - 600 * cos(j), y / 4 - 100 * sin(j));
           
        }
        glEnd();

        glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 1.0f);
        // Loop to make orbit of revolution
        for (i = 0; i < 6.29; i += 0.001)
        { 
            x = 600 * cos(i);
            y = 100 * sin(i);
            glVertex2i(x, y);
        }
        glEnd();
        glFlush();
    }
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1360, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Revolution");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}
