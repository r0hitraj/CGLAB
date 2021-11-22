#include<GL\glut.h>
#include<iostream>
#include<math.h>
void circle()
{
    int xCenter = 0, yCenter = 0, radius = 100;
    int x = 0;
    int y = radius;
    int p = 1 - radius;
    while (x < y)
    {  glBegin(GL_POINTS);
        x++;
        if (p < 0) p = p + 2 * x + 3;
        else{            y--;
            p = p + 2 * (x - y) + 5;
        }
        glVertex2i(xCenter + x, yCenter + y);
        glVertex2i(xCenter - x, yCenter + y);
        glVertex2i(xCenter + x, yCenter - y);
        glVertex2i(xCenter - x, yCenter - y);
        glVertex2i(xCenter + y, yCenter + x);
        glVertex2i(xCenter - y, yCenter + x);
        glVertex2i(xCenter + y, yCenter - x);
        glVertex2i(xCenter - y, yCenter - x);
        glEnd();
    }
    glFlush();
}
void fun()
{
    float i = 0;
    for (i = 0; i < 10000; i += 0.01)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINES);
        glVertex2f(0, 0);
        glVertex2f(100 * sin(i), 100 * cos(i));
        glVertex2f(90 * sin(i/60), 90 * cos(i/60));
        glVertex2f(0, 0);
        glVertex2f(70 * sin(i/360), 70 * cos(i/360));
        glVertex2f(0, 0);
        glEnd();
        circle();
    }
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutCreateWindow("Line Drawing Alogrithms");
	gluOrtho2D(-300,300,-300,300);
	glutDisplayFunc(fun);
	glutMainLoop();
}
