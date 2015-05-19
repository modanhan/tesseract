#pragma once

#include <glm\glm.hpp>

namespace aerobox {
	extern glm::vec3 viewport_position, viewport_lookat, viewport_up;
	extern int viewport_width, viewport_height;
	extern float fov, viewport_near, viewport_far;
}
