#include <stdio.h>
#include <math.h>
#include <glut.h>
#define M_PI 3.14

float x1 = -30, y11 = -30;
float x2 = 0, y2 = 30;
float x3 = 30, y3 = -30;

float rotatedX1, rotatedY1;
float rotatedX2, rotatedY2;
float rotatedX3, rotatedY3;

float angle = 45.0;

void initGL() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200, 200,-200, 200);
}


void rotateLine() {

	float radians = angle * (M_PI / 180.0);


	rotatedX1 = x1 * cos(radians) - y11 * sin(radians);
	rotatedY1 = x1 * sin(radians) + y11 * cos(radians);

	rotatedX2 = x2 * cos(radians) - y2 * sin(radians);
	rotatedY2 = x2 * sin(radians) + y2 * cos(radians);

	rotatedX3 = x3 * cos(radians) - y3 * sin(radians);
	rotatedY3 = x3 * sin(radians) + y3 * cos(radians);
}


void display() {

	rotateLine();

	glClear(GL_COLOR_BUFFER_BIT);


	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y11);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();


	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(rotatedX1, rotatedY1);
	glVertex2f(rotatedX2, rotatedY2);
	glVertex2f(rotatedX3, rotatedY3);
	glEnd();
	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Rotate Line");

	initGL();

	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}