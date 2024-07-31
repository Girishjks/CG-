#include<iostream>
#include<glut.h>
using namespace std;

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glPointSize(10);

	glBegin(GL_POINTS);
	glVertex2i(100, 100);
	glEnd();

	glColor3f(1, 0, 0);
	int point1, point2;
	point1 = 100 + 50;
	point2 = 100 + 50;
	glPointSize(10);

	glBegin(GL_POINTS);
	glVertex2i(point1, point2);
	glEnd();

	glFlush();
}

void myinit()
{
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Translate Point");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}