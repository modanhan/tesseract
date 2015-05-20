#pragma once

#include <glm\glm.hpp>

namespace aerobox {
	// will remove gx and gz
	extern float gx, gz;
	
	extern glm::vec3 ray_origin;
	extern glm::vec3 ray_dir;
	void mouse_func(int, int, int, int);
	void mouse_update();
	bool button_down(int);
	bool button_pressed(int);
	bool button_released(int);

}
