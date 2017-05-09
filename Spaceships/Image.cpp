#include "Image.h"

Image::Image(float x, float y, float w, float h, GLuint loadImg) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

#if defined WIN32
	img = loadImg;
#else
	img = loadImg;
#endif

	back = new TexRect(x + 0.1, y + 0.1, w, h);
}

void Image::draw() {
	delete back;
	back = new TexRect(x + 0.1, y + 0.1, w, h);
	// Set Color
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, img);
	back->draw();
}
