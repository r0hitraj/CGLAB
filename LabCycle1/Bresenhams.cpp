#include<GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std;

void Draw()
{
	GLfloat M, p, dx, dy, x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	int x1, y1, x2, y2;
	cout << "ENTER X1 and Y1: ";
	cin >> x1 >> y1;
	cout << "ENTER X2 and Y2: ";
	cin >> x2 >> y2;
	if (x2 == x1) {
		cout << " infiniy slp . EXITTING \n";
		exit(1);
	}

	M = (y2 - y1) / (x2 - x1);

	if (M >=1 ) {
		cout << "slp>= 1 . EXITTING \n";
		exit(1);
	}
	if (M < 0) {
		cout << "slp -ve . EXITTING \n";
		exit(1);
	}



	dx = x2 - x1;
	dy = y2 - y1;
	p = 2 * dy - dx;
	x = x1;
	y = y1;
	glPointSize(5);
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
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Bresenham's Line Drawing Algorithm");
	MyInit();
	glClearColor(1.0f, 0.0f, 0.0f);
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
