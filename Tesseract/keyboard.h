#pragma once

namespace aerobox {
	bool key_down(int c);
	bool key_pressed(int c);
	bool key_released(int c);
	void keyboard_update();
	void keyboard_func(unsigned char key, int x, int y);
	void keyboard_up_func(unsigned char key, int x, int y);
	void calc_ray();
}