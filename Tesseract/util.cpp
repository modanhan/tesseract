#include "util.h"

#include "aerobox.h"

namespace aerobox{
	void draw_y_grid(float size, float density){
		glBegin(GL_LINES);
		for (float f = -size ; f <= size; f += density){
			glVertex3f(f, 0, size);
			glVertex3f(f, 0, -size);
			glVertex3f(size, 0, f);
			glVertex3f(-size, 0, f);
		}
		glEnd();
	}
}