#include <GL/glut.h>
#include<iostream>
using namespace std;
int xCenter, yCenter, radius;
void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void circleMidPoint()
{
   

    int x = 0;
    int y = radius;
    int p = 1 - radius;//5/4 is rounded to 1 for integer radius

    while (x < y)
    {// iterates to draw the first sector
        x++;
        if (p < 0)// if mid point is inside the circle
            p = p + 2 * x + 3;
        else //p >= 0
        {// the mid point is outside or at the circle
            y--;
            p = p + 2 * (x - y) + 5;

        }
        glBegin(GL_POINTS);
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
    // OPTIONAL:-> center of the circle
    //glBegin(GL_POINTS);
     //   glVertex2i(xCenter,yCenter);
    //glEnd();
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
    glColor3f(1.0, 0.0, 0.0);          // red foreground
    glPointSize(3.0);               // size of points to be drawin (in pixel)

    //establish a coordinate system for the image

    circleMidPoint();
    glFlush(); // send all output to the display
}

int main(int argc, char** argv)
{
    cout << "Enter Radius Of Circle:";
    cin >> radius;
    cout << "Enter xCentre of Circle:";
    cin >> xCenter;
    cout << "Enter yCentre of Circle:";
    cin >> yCenter;

    glutInit(&argc, argv);
    glutInitWindowSize(640, 480); // set the size of the window
    glutInitWindowPosition(10, 10); // the position of the top-left of window
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Midpoint Circle Drawing Algorithm");
    myinit();
    glutDisplayFunc(display); // set the gl display callback function
    glutMainLoop(); // enter the GL event loop

}
