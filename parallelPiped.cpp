#include <GL/glut.h>
#include <cmath>

void init() {
    gluOrtho2D(0, 400, 0, 400);
}

void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glPointSize(5);

    
    for (int i = 0; i < 50; i++) {
        glBegin(GL_LINE_LOOP);
        glVertex2i(50 + i, 50 + i);
        glVertex2i(150 + i, 50 + i);
        glVertex2i(150 + i, 150 + i);
        glVertex2i(50 + i, 150 + i);
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Parallel Piped");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
