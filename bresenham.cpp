#include<GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std;

void Draw()
{
	GLfloat M,p,dx,dy,x,y;
	glClear(GL_COLOR_BUFFER_BIT);
    int x1, y1, x2, y2;
    cout << "Enter starting point (x, y): ";
    cin >> x1 >> y1;
    cout << "Enter end point (x, y): ";
    cin >> x2 >> y2;
if (x2==x1){
cout << "SLOPE is infiniy . EXITTING \n";
exit(1);
}

	M = (y2 - y1) / (x2 - x1);

if (M>1){
cout << "SLOPE GREATER THAN 1 . EXITTING \n";
exit(1);
}



	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dy - dx;
	x = x1;
	y = y1;
glPointSize(5);
glColor3f(0.0f, 0.5f, 1.0f);
//glColor3f();
	glBegin(GL_POINTS);
	    while (x <= x2)
	    {
		glVertex2i(x, y);
		x = x + 1;
		if (p >= 1)
		{
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			y = y;
			p = p + 2 * dy;
		}
	    }
		glEnd();
	glFlush();
}

void MyInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
//int glPointSize(5000);

}
int main(int argC, char* argV[])
{
	glutInit(&argC, argV);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Bresenham's Line Drawing Algorithm");
	MyInit();
glViewport(0, 0, 500, 500);
//int glPointSize(5000000);
//glClearColor(1.0f, 0.0f, 0.0f);
glClearColor(0.7, 0, 0, 1);
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
