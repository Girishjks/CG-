#include <GL/glut.h>
#include <cmath>

int x = 100, y = 200, size = 50;
float r = 1, g = 1, b = 1;

void init() {
    gluOrtho2D(0, 500, 0, 500);
}

void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(r, g, b);

    glBegin(GL_QUADS);
    glVertex2f(x + size, y + size);
    glVertex2f(x - size, y + size);
    glVertex2f(x - size, y - size);
    glVertex2f(x + size, y - size);
    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'r':
        r = 1; g = b = 0;
        break;
    case 'g':
        g = 1; b = r = 0;
        break;
    case 'b':
        b = 1; g = r = 0;
        break;
    case 'q':
        exit(0);
        break;
    case 'w':
        ::y += 10;
        break;
    case 'a':
        ::x -= 10;
        break;
    case 's':
        ::y -= 10;
        break;
    case 'd':
        ::x += 10;
        break;
    case '+':
        ::size += 10;
        break;
    case '-':
        size -= 10;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Activity 1");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
