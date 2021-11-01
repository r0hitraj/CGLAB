
#include <GL/glut.h>
 
void myInit (void)
 
{
 
     glClearColor(0.0,0.0,0.0,0.0); // sets background color to white
 
     // sets a point to be 4x4 pixels
 
     glMatrixMode(GL_PROJECTION);
 
     glLoadIdentity();
 
     gluOrtho2D(0.0, 500.0, 0.0, 400.0); // the display area in world coordinates.
 
}
 
 
void myDisplay(void)
 
{
 
     glClear(GL_COLOR_BUFFER_BIT); // clears the screen
    glColor3f(0.5f,0.5f,0.5f) ;// setsthe drawing colour
 
     glPointSize(4.0);
 
     glBegin(GL_POLYGON);
//bottom
 
          glVertex2i (20, 20);
          glVertex2i (320, 20);
 
          //top
          glVertex2i (20, 200);
          glVertex2i (320, 200);
        //left
          glVertex2i (20, 200);
          glVertex2i (20, 20);
        //right
          glVertex2i (320, 200);
          glVertex2i (320, 20);
 
          //glVertex2i (10, -50);
 
    glEnd();
 
 
//Left Window
 
 glColor3f(1.0f,0.0f,0.0f) ;
glPointSize(4.0);
 glRectf(30,30,100,100);
 
 //Right Window
 glColor3f(1.0f,0.0f,0.0f) ;
glBegin(GL_POLYGON);
//bottom
 
        glVertex2i (200,30);
          glVertex2i (200, 100);
 
//top
          glVertex2i (200, 100);
          glVertex2i (300, 100);
 
//left
          glVertex2i (300, 100);
          glVertex2i (300, 30);
 //right
         glVertex2i (300, 30);
          glVertex2i (200, 30);
 
          //glVertex2i (10, -50);
 
    glEnd();
 
 
//door
glColor3f(0.0f,0.0f,1.0f) ;
glBegin(GL_POLYGON);
//left
 
        glVertex2i (120,30);
          glVertex2i (120, 100);
 
//top
          glVertex2i (120, 100);
          glVertex2i (170, 100);
 
//right
          glVertex2i (170, 100);
          glVertex2i (170, 30);
 
 //bottom
         glVertex2i (120, 30);
          glVertex2i (170, 30);
 
          //glVertex2i (10, -50);
 
    glEnd();
 
    //Triangle
 
    glColor3f(0.0f,1.0f,0.0f) ;
    glBegin(GL_POLYGON);
//bottom
 
          glVertex2i (20, 200);
          glVertex2i (320, 200);
 
          //top
          glVertex2i (200, 310);
          glVertex2i (320, 200);
 
        //left
          glVertex2i (20, 200);
          glVertex2i (200, 310);
 
 
          //glVertex2i (10, -50);
 
    glEnd();
/*
glColor3f(0.0f, 1.0f, 0.0f);//Green
        glBegin(GL_TRIANGLES);

        //glVertex2i(500, 200);

        glVertex2i(350, 330);

        glVertex2i(400, 300);
glVertex2i(300,300);

        glEnd();
*/
glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
        glBegin(GL_POLYGON);

        glVertex2i(450, 200);

        glVertex2i(450, 0);

        glVertex2i(430, 200);
glVertex2i(430,0);

        glEnd();
 
 
glColor3f(0.1f, 0.0f, 0.1f);//Dark Purple;//Green
        glBegin(GL_POLYGON);

        glVertex2i(370, 250);

        glVertex2i(390, 200);

        glVertex2i(370, 250);
glVertex2i(390,200);

        glEnd();





 
     glFlush(); // sends all output to display;
 
}
int main (int argc, char **argv)
{
 
     glutInit (&argc, argv); // to initialize the toolkit;
 
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // sets the display mode
 
     glutInitWindowSize (640, 480); // sets the window size
 
     glutInitWindowPosition (10, 10); // sets the starting position for the window
 
     glutCreateWindow ("My first OpenGL program!"); // creates the window and sets the title
 
     glutDisplayFunc (myDisplay);
     myInit(); // additional initializations as necessary
     glutMainLoop(); // go into a loop until event occurs
     return 0;
}
