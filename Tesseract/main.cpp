#include <iostream>

#include <Windows.h>

#include "glut.h"

#include "keyboard.h"

using namespace std;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display() {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor4f(1, 1, 1, 1);
	glutWireCube(1.0);

	for (int i = 0; i < 256; i++) {
		if (aerobox::key_pressed(i)) {
			cout << (char)i << " pressed\n";
		}
		if (aerobox::key_released(i)) {
			cout << (char)i << " released\n";
		}
	}

	aerobox::keyboard_update();
	glutPostRedisplay();
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 0.1, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(4.0, 3.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	glutInitWindowSize(720, 480);
	glutInitWindowPosition(500, 500);
	glutInit(&argc, argv);

	glutCreateWindow(argv[0]);

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutIgnoreKeyRepeat(1);

	glutKeyboardFunc(aerobox::keyboard_func);
	glutKeyboardUpFunc(aerobox::keyboard_up_func);
	glutMainLoop();
}