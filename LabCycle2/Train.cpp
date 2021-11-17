#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

void display();
void reshape(int, int);
void timer(int);
void init() {

    glClearColor(0.0, 0.0, 0.0, 1.0); //yellow
    //0-1 rgb
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GL_DOUBLE);//double buffer

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 1000);


    glutCreateWindow("Window 1");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
}
float x_position = -10.0;
int state = 1; //1 right,-1 left
   
void display()
{
    //clear window, default is black
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); //reset transformation matrix
    //GLDRAW
    //glPointSize(10.0);
    //glBegin(GL_POINTS);
    glBegin(GL_POLYGON); //primitive

    glVertex2f(x_position, 1.0);
    glVertex2f(x_position, -1.0);
    glVertex2f(x_position + 2.0, -1.0);
    glVertex2f(x_position + 2.0, 1.0);

    glEnd();

    glBegin(GL_LINES);
    glVertex2f(x_position +2.0,0.0);
    glVertex2f(x_position +3.0,0.0);
    glEnd();


    glBegin(GL_POLYGON); //primitive

    glVertex2f(x_position + 3.0, 1.0);
    glVertex2f(x_position+ 3.0, -1.0);
    glVertex2f(x_position +3.0 + 2.0, -1.0);
    glVertex2f(x_position +3.0 + 2.0, 1.0);

    glEnd();
   
    glBegin(GL_LINES); //for draing tracks
    glVertex2f(-10.0 , -2.0);
    glVertex2f(10.0 , -2.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-10.0, -3.0);
    glVertex2f(10.0, -3.0);
    glEnd();

    for (int i = -9; i < 10; i++) //for drawing tracks
    {
        glBegin(GL_LINES);
        glVertex2f(i, -2.0);
        glVertex2f(i, -3.0);
        glEnd();
    }




   
 

    //display frame buffer
    glutSwapBuffers();
    //glFlush();


}
void reshape(int w, int h) {
    //viewport
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}
void timer(int) {
    glutPostRedisplay();
    //60 frame are called per second
    glutTimerFunc(1000 / 60, timer, 0);//60fps

    switch (state) {
    case 1:
        if (x_position < 8)
            x_position += 0.05;
        else
            state = -1;
        break;
    case -1:
        if (x_position > -10)
            x_position -= 0.05;
        else
            state = 1;
        break;
    }
}
