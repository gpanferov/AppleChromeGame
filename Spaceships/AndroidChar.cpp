#include "AndroidChar.h"


AndroidChar::AndroidChar(float x, float y, GLuint loadImg [12]) {
	this->x = x;
	this->y = y;

#if defined WIN32
	for (int i = 0; i < 12; i++) {
		androidImg[i] = loadImg[i];
	}
#else
	for (int i = 0; i < 12; i++) {
		androidImg[i] = loadImg;
	}
#endif

	characterBack = new TexRect(x + 0.1, y + 0.1, 0.322, 0.480);
}

void AndroidChar::draw() {
	delete characterBack;
	characterBack = new TexRect(x + 0.1, y + 0.1, 0.322, 0.480);
	// Set Color
	glColor3f(1.0, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, androidImg[(animateCount++/50) % 12]);
	characterBack->draw();
}