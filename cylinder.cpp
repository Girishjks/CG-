#include<glut.h>
#include<math.h>
void myinit()
{
	gluOrtho2D(-100, 100, -100, 100);
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	int i;
	double angle;
	glColor3f(0, 0, 1);
	int j;
	for (j = 0; j < 50; j++)
	{

		glBegin(GL_LINES);
		for (i = 0; i <= 12; i++)
		{
			angle = 3.14 / 6 * i;
			glVertex2f(10 * cos(angle), j + 10 * sin(angle));
		}
	}
	glEnd();
	glFlush();
}

void main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Displaying circle:");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
