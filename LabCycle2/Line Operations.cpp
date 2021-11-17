#include<GL/glut.h> //compulsory header
#include <iostream>
#include<cmath>
#include <stdlib.h>
using namespace std;
int xa, xb, ya, yb, tx, ty, dx, dy, steps, k, txd, tyd, Shx, Shy, axis,op; // txd,txy is translation distance, Shx,Shy is the Shearing Factor , axis is for the line Reflection
float xInc, yInc, x, y, theta, angle, Sx, Sy ; //Sx,Sy are the Scaling Factors
void rotate() {
	glColor3f(1, 0, 0);
	glPointSize(2.0);

	int x1, y1, y2, x2;
	
	if (op == 1) //Translation
	{
		x1 = xa + txd;
		y1 = ya + tyd;
		x2 = xb + txd;
		y2 = yb + tyd;
	}
	else if (op == 2) //Rotation
	{
		angle = (theta * 3.14) / 180;
		x1 = (int)(((float)(xa)*cos(angle)) + ((float)(ya)*sin(angle)));
		y1 = (int)(((float)(ya)*cos(angle)) + ((float)(xa)*sin(angle)));
		x2 = (int)(((float)(xb)*cos(angle)) + ((float)(yb)*sin(angle)));
		y2 = (int)(((float)(yb)*cos(angle)) + ((float)(xb)*sin(angle)));

	}
	else if (op == 3) //Scaling
	{

		x1 = (int)(Sx * xa);
		y1 = (int)(Sy * ya);
		x2 = (int)(Sx * xb);
		y2 = (int)(Sy * yb);

	}
	else if (op == 4) //Shear
	{
		x1 = xa ;
		y1 = ya;

		x2 = xb + yb * Shx;
		y2 = xb * Shy + yb;


	}
	else if (op == 5) //Refection
	{
		if (axis == 1) //x axis reflection
		{
			x1 = xa;
			y1 = -ya;
			x2 = xb;
			y2 = -yb;
		}
		else if (axis == 2) //y axis reflection
		{

			x1 = -xa;
			y1 = ya;
			x2 = -xb;
			y2 = yb;
		}
		else if (axis == 3) //perpendicular reflection
		{

			x1 = -xa;
			y1 = -ya;
			x2 = -xb;
			y2 = -yb;
		}
		else if (axis == 4)  //x=y reflection
		{

			x1 = ya;
			y1 = xa;
			x2 = yb;
			y2 = xb;
		}

	}
	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) > abs(dy))steps = abs(dx);
	else steps = abs(dy);

	xInc = (float)dx / (float)steps;
	yInc = (float)dy / (float)steps;

	x = x1;
	y = y1;
	glBegin(GL_POINTS);

	for (int i = 0; i < steps; i++)
	{
		glVertex2i(round(x), round(y));
		x += xInc;
		y += yInc;
	}
	glEnd();


}
void Draw()
{
	glColor3f(0, 0, 0);
	glPointSize(3.0);

	dx = xb - xa;
	dy = yb - ya;

	if (abs(dx) > abs(dy))steps = abs(dx);
	else steps = abs(dy);

	xInc = (float)dx / (float)steps;
	yInc = (float)dy / (float)steps;

	x = xa;
	y = ya;
	glBegin(GL_POINTS);

	for (int i = 0; i < steps; i++)
	{
		glVertex2i(round(x), round(y));
		x += xInc;
		y += yInc;
	}
	glEnd();
	rotate();
	glFlush();
}



int main(int argc, char** argv)
{

	cout << "Enter the points\n";
	cout << "Enter Starting Points" << endl;
	cout << "Enter X1: ";
	cin >> xa;
	cout << "Enter Y1: ";
	cin >> ya;
	cout << "Enter X2: ";
	cin >> xb;
	cout << "Enter Y2: ";
	cin >> yb;
	cout << endl;
	cout << "Choose The Operations Wants To Perform On Line" << endl;
	cout << "1.Translation the Line" << endl;
	cout << "2.Rotation the Line" << endl;
	cout << "3.Scaling the Line" << endl;
	cout << "4.Shear the Line" << endl;
	cout << "5.Reflection the Line" << endl;
	cout << "Enter options in [1,5] : ";
	cin >> op;
	if (op == 1)
	{
		cout << "Translation the Line" << endl;
		cout << "Enter the Translation Distance" << endl;
		cout << "Enter Tx: ";
		cin >> txd;
		cout << "Enter Ty: ";
		cin >> tyd;
	}
	else if (op == 2) 
	{
		cout << "Rotation the Line" << endl;
		cout << "Enter the rotating angle in Degree: ";
		cin >> theta;
		
	}
	else if (op == 3)
	{
		cout << "Scaling the Line" << endl;
		cout << "Enter the Scaling Factor" << endl;
		cout << "Enter Sx: ";
		cin >> Sx;
		cout << "Enter Sy: ";
		cin >> Sy;

	}
	else if (op == 4)
	{
		cout << "Shear the Line" << endl;
		cout << "Enter the Shearing  Factor" << endl;
		cout << "Enter Shx: ";
		cin >> Shx;
		cout << "Enter Shy: ";
		cin >> Shy;


	}
	else if (op == 5)
	{
		cout << "Reflection the Line" << endl;
		cout << "Choose The Reflection Axis" << endl;
		cout << "1.Reflection About X axis" << endl;
		cout << "2.Reflection About Y axis" << endl;
		cout << "3.Reflection About Axis prependicular to XY plane" << endl;
		cout << "4.Reflection About X=Y Line" << endl;
		cout << "Enter options in [1,4] :";
		cin >> axis;
		if (axis <= 0 || axis > 4) {
			cout << "Wrong Option" << endl;
			exit(3);
		}

	}
	else {
		cout << "Wrong Option" << endl;
		exit(3);
	}
	

	
	//this is dry code needed in every lab
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(50, 50);
	//
	// 

	//this line gives the name of the window
	glutCreateWindow("2D TransFormation Operation On Lines");
	//
	glClear(GL_COLOR_BUFFER_BIT);
	//Again Dry code Starts
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-1000, 1000, -1000, 1000);
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, 1000, 1000);
	//
	glutDisplayFunc(Draw); // the parameter inside this fn will call he the name of the function in which our 
							//logic for drawing is written

	glutMainLoop();

	return 0;
}
