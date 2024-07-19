// 3D Operation without built in
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

double rot = 0, rot2 = 0,rot3 = 0, tx = 0, ty = 0, tz = 0;
float s = 0.1;

void init() 
{
	gluOrtho2D(0, 100, 0, 100);
	glEnable(GL_DEPTH_TEST);
}

void face(float P[8][3], int a, int b, int c, int d) 
{
	glBegin(GL_QUADS);
	glVertex3fv(P[a]);
	glVertex3fv(P[b]);
	glVertex3fv(P[c]);
	glVertex3fv(P[d]);
	glEnd();
}
void cube( float rx, float ry, float rz, float scale, float c) 
{
	float P[8][3] = {
		{-1,-1,-1},//0
		{-1,-1,+1},//1
		{+1,-1,+1},//2
		{+1,-1,-1},//3
		{-1,+1,-1},//4
		{-1,+1,+1},//5
		{+1,+1,+1},//6
		{+1,+1,-1}//7
	};
	rx += rot2;
	ry += rot;
	rz += rot3;
	rx = rx * 3.1415 / 180;
	ry = ry * 3.1415 / 180;
	rz = rz * 3.1415 / 180;
	for (int i = 0; i < 8; i++) {
		float x = P[i][0], y = P[i][1], z = P[i][2], t;
		x = x * scale ;
		y = y * scale ;
		z = z * scale;
		t = y * cos(rx) - z * sin(rx);
		z = y * sin(rx) + z * cos(rx);
		y = t;

		t = z * cos(ry) - x * sin(ry);
		x = z * sin(ry) + x * cos(ry);
		z = t;

		t = x * cos(rz) - y * sin(rz);
		y = x * sin(rz) + y * cos(rz);
		x = t;

		P[i][0] = x + tx;
		P[i][1] = y + ty;
		P[i][2] = z + tz;
	}
	glColor3f(c, 0, 0);
	face(P, 0, 1, 2, 3);//bottom
	glColor3f(c, c, 0);
	face(P, 0, 1, 5, 4);//left
	glColor3f(0, c, 0);
	face(P, 1, 2, 6, 5);//front
	glColor3f(0, c, c);
	face(P, 2, 3, 7, 6);//right
	glColor3f(0, 0, c);
	face(P, 3, 0, 4, 7);//back
	glColor3f(c, 0, c);
	face(P, 4, 5, 6, 7);//top
}

void disp()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	cube( 0, 0, 0, s, 1.0);
	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y) 
{
	switch (key) {
	case 'w':
		ty += 0.05;
		break;
	case 'a':
		tx -= 0.05; 
		break;
	case 's':
		ty -= 0.05;
		break;
	case 'd':
		tx += 0.05; 
		break;
	case '.':
		rot2++; 
		break;
	case ',':
		rot++;
		break;
	case '/':
		rot3++;
		break;
	case '[':
		rot--;
		break;
	case ']':
		rot2--; 
		break;
	case '\\':
		rot3--;
		break;
	case 'r':
		tx = tz = rot = rot2 =rot3 = 0; 
		break;
	case '+':
		s += 0.1; 
		break;
	case '-':
		s -= 0.1; 
		break;
	case 27 : 
		exit(0);
	}
	glutPostRedisplay();
}
int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 300);

	glutCreateWindow("Program 3");
	init();
	glutDisplayFunc(disp);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}