#include "MainChar.h"


using namespace std;

MainChar::MainChar(float x, float y, GLuint loadImg) {
	this->x = x;
	this->y = y;

#if defined WIN32
	characterImg = loadImg;
#else
	characterImg = loadImg;
#endif

	characterBack = new TexRect(x + 0.1, y + 0.1, h, h);
}

float MainChar::getY() {
	return y;
}
float MainChar::getX() {
	return x;
}
float MainChar::getH() {
	return h;
}

void MainChar::crouch() {
	is_crouch = !is_crouch;
	if (is_crouch) {
		c = .1;
		y -= .1;
	}
	else {
		c = 0;
		y += .1;
	}
}
void MainChar::setY(float y) {
	this->y = y;
}

void MainChar::incrementY() {
	y += 0.0007;
}

void MainChar::decrementY() {
	y -= 0.0007;
}

bool MainChar::get_is_crouch() {
	return is_crouch;
}

void MainChar::draw() {
	delete characterBack;
	characterBack = new TexRect(x + 0.1, y + 0.1, h, (h-c));
	// Set Color
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, characterImg);
	characterBack->draw();
}

void MainChar::reset(float x, float y) {
	this->x = x;
	this->y = y;
}

MainChar::~MainChar() {
	delete characterBack;
}