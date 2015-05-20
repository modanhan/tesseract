#include "mouse.h"

#include <iostream>
#include <vector>

#include "viewport.h"

#define PI 3.14159265358979323846

namespace aerobox {

	void calc_ray(int, int, int, int);

	float gx = 0, gz = 0;

	std::vector<bool> bd(3, 0), lbd(3, 0);

	glm::vec3 ray_origin(0, 0, 0);
	glm::vec3 ray_dir(0, 0, 0);

	void mouse_func(int key, int state, int x, int y) {
		bd[key] = 1 - state;
		calc_ray(key, state, x, y);
	}

	void mouse_update(){
		lbd = bd;
	}

	bool button_down(int b){
		return bd[b];
	}

	bool button_pressed(int b){
		return bd[b] && (!lbd[b]);
	}

	bool button_released(int b){
		return (!bd[b]) && lbd[b];
	}

	void calc_ray(int key, int state, int x, int y){
		glm::vec3 view = viewport_lookat - viewport_position;
		view = glm::normalize(view);
		glm::vec3 h = glm::cross(view, viewport_up);
		h = glm::normalize(h);
		glm::vec3 v = glm::cross(h, view);
		v = glm::normalize(v);

		float rad = fov * PI / 180;
		float vl = tan(rad / 2) * viewport_near;
		float hl = vl * (float)viewport_width / viewport_height;
		h *= hl;
		v *= vl;
		float fx = x, fy = -y;
		fx -= viewport_width / 2;
		fy += viewport_height / 2;
		fx /= viewport_width / 2;
		fy /= viewport_height / 2;

		ray_origin = viewport_position;
		ray_origin += view * viewport_near;
		h *= fx;
		ray_origin += h;
		v *= fy;
		ray_origin += v;

		ray_dir = ray_origin - viewport_position;

		gx = viewport_position[0] - ray_dir[0] * viewport_position[1] / ray_dir[1];
		gz = viewport_position[2] - ray_dir[2] * viewport_position[1] / ray_dir[1];
	}
}
