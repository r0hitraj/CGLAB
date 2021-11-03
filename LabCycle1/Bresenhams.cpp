#include<GL/glut.h>
#include<iostream>

void Draw()
{
	GLfloat x1=120, y1=50, x2=300, y2=200;
	GLfloat M,p,dx,dy,x,y;
	glClear(GL_COLOR_BUFFER_BIT);
	M = (y2 - y1) / (x2 - x1);
	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dy - dx;
	x = x1;
	y = y1;
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

}
int main(int argC, char* argV[])
{
	glutInit(&argC, argV);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Bresenham's Line Drawing Algorithm");
	MyInit();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}