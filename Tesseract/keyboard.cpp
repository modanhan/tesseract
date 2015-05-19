#include "keyboard.h"

#include <vector>

#include "glut.h"
#include <iostream>

namespace aerobox {
	std::vector<bool> kd(256, 0), lkd(256, 0);

	bool key_down(int c) {
		return kd[c];
	}

	bool key_pressed(int c) {
		return (!lkd[c]) && kd[c];
	}

	bool key_released(int c) {
		return lkd[c] && (!kd[c]);
	}

	void keyboard_update() {
		lkd = kd;
	}

	void keyboard_func(unsigned char key, int x, int y) {
		if (glutGetModifiers()&GLUT_ACTIVE_SHIFT){
			kd[key + 32] = 1;
		}
		else{
			kd[key] = 1;
		}
	}

	void keyboard_up_func(unsigned char key, int x, int y) {
		if (glutGetModifiers()&GLUT_ACTIVE_SHIFT){
			kd[key + 32] = 0;
		}
		else{
			kd[key] = 0;
		}
	}
}
