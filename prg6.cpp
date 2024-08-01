// Program to demonstrate Idle function
#include <math.h>
#include <GL/glut.h>

float theta = 0;
float x, y, r = 50;
bool rotationEnabled = false;  

void init()
{
    gluOrtho2D(-100, 100, -100, 100);
}

void idle()
{
    if (rotationEnabled) 
    {
        theta += 0.01;
        if (theta >= 360)
            theta = 0;
    }
    glutPostRedisplay();
}

void disp()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);

    x = r * cos(theta * 3.142 / 180);
    y = r * sin(theta * 3.142 / 180);

    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(-y, x);
    glVertex2f(-x, -y);
    glVertex2f(y, -x);
    glEnd();

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        rotationEnabled = true;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        rotationEnabled = false;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 150);
    glutCreateWindow("Program 6");
    init();
    glutDisplayFunc(disp);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}