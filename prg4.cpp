//2D transformation using Built-in function
#include<stdlib.h>
#include<GL/glut.h>

float angle = 0.0;
float scale = 1.0;
float translateX = 0.0;
float translateY = 0.0;
const float xmin = -10.0, xmax = 10.0, ymin = -10.0, ymax = 10.0;

void init() 
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xmin,xmax,ymin,ymax);
	glMatrixMode(GL_MODELVIEW);
}

void reshapefunc(int w, int h) 
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h) 
	{
		gluOrtho2D(xmin * (float)w / (float)h, xmax * (float)w / (float)h, ymin, ymax);
	}
	else 
	{
		gluOrtho2D(xmin, xmax, ymin * (float)h / (float)w, ymax * (float)h / (float)w);
	}
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void display() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(translateX, translateY, 0.0);
	glScalef(scale, scale, 1.0);
	glRotatef(angle, 0.0, 0.0, 1.0);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-5.0, -5.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(5.0, -5.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.0, 5.0);
	glEnd();
	glFlush();

}
void keyboard(unsigned char key, int x, int y) 
{
	switch (key) {
	case 'a':
		angle += 5.0;
		break;
	case 'd':
		angle -= 5.0;
		break;
	case 'w':
		scale += 0.1;
		reshapefunc(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;
	case 's':
		if (scale > 0.1) 
		{
		scale -= 0.1;
		}
		reshapefunc(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;
	case 'i':
		translateY += 0.5;
		break;
	case 'k':
		translateY -= 0.5;
		break;
	case 'j':
		translateX -= 0.5;
		break;
	case 'l':
		translateX += 0.5;
		break;
	case 27:
		exit(0);
	}
	glutPostRedisplay();
}
int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Program 4");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshapefunc);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}