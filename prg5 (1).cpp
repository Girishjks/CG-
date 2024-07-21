// 3D transformation using Built-in function
#include<iostream>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float tx = 0.0, ty = 0.0, tz = 0.0;
float scale = 1;
float angleX = 0.0, angleY = 0.0, angleZ = 0.0;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
}

void drawCube()
{
	glBegin(GL_QUADS);
	//Front Face
	glColor3f(1, 0, 0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	//Back Face
	glColor3f(0, 1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);

	//Left face
	glColor3f(0, 0, 1);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	//Right Face
	glColor3f(1, 1, 0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	//Top Face
	glColor3f(0, 1, 1);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);

	//Bottom Face
	glColor3f(1, 0, 1);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(tx, ty, tz);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0, 1.0, 0);
	glRotatef(angleZ, 0, 0, 1);
	glScalef(scale, scale, scale);
	drawCube();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'u': 
		ty += 0.1;
		break;
	case 'U':
		ty -= 0.1;
		break;
	case 'T': 
		tx -= 0.1;
		break;
	case 't':
		tx += 0.1;
		break;
	case 'v':
		tz += 0.1;
		break;
	case 'V':
		tz -= 0.1;
		break;
	case 's':scale += 0.1;
		if (scale > 2.0)
			scale = 2.0;
		break;
	case 'S':scale -= 0.1;
		if (scale < 0.1)
			scale = 0.1;
		break;
	case 'x':
		angleX += 5.0;
		break;
	case 'X':
		angleX -= 5.0;
		break;
	case 'y': 
		angleY += 5;
		break;
	case 'Y':
		angleY -= 5;
		break;
	case 'z':
		angleZ += 5;
		break;
	case 'Z':
		angleZ -= 5;
		break;
	case 27:
		exit(0);
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Scaling polygon");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}