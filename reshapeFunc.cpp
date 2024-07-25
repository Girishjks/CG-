#include<stdlib.h>
#include<glut.h>
#include<stdio.h>
#include<string.h>

int xmin = 0, xmax = 200, ymin = 0, ymax = 200;

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xmin, xmax, ymin, ymax);
	glMatrixMode(GL_MODELVIEW);
}
void reshapefunc(int w, int h)
{
	glViewport(0, 0, w, h);
	if (w > h)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xmin * w / h, xmax * w / h, ymin, ymax);
		glMatrixMode(GL_MODELVIEW);
	}
	else
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xmin, xmax, ymin * h / w, ymax * h / w);
		glMatrixMode(GL_MODELVIEW);
	}
	glutPostRedisplay();
}

void display()
{

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(20, 20);
	glVertex2f(20, 40);
	glVertex2f(40, 40);
	glVertex2f(40, 20);
	glEnd();
	glFlush();

}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Reshape function");

	myinit();
	glutDisplayFunc(display);
	glutReshapeFunc(reshapefunc);
	glutMainLoop();

}