#include "EnemyChar.h"


using namespace std;

EnemyChar::EnemyChar() {};

EnemyChar::EnemyChar(float x, float y, float boundry, GLuint loadImg) {
	this->x = x;
	this->y = y;
    this->boundry = boundry;
#if defined WIN32
	characterImg = loadImg;
#else
	characterImg = loadImg;
#endif

	characterBack = new TexRect(x + 0.1, y + 0.1, h, h);
}

float EnemyChar::getX() {
	return x;
}

void EnemyChar::setX(float x) {
	this->x = x;
}

float EnemyChar::getH() {
	return h;
}

void EnemyChar::incrementX() {
	x += 0.01;
}

void EnemyChar::decrementX() {
	x -= dec;
}

void EnemyChar::changeSpeed() {
	dec += .0002;

}



void EnemyChar::draw() {
	delete characterBack;
	characterBack = new TexRect(x + 0.1, y + 0.1, h, h);
	// Set Color
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, characterImg);
	characterBack->draw();
}

bool EnemyChar::contains(MainChar * mc) {
	if (((mc->getX() >= this->x) && (mc->getX() <= (this->x + this->h))) || (((mc->getX() + mc->getH()) >= this->x) && ((mc->getX() + mc->getH()) <= (this->x + this->h)))) {
		if (mc->get_is_crouch()) {
			return true;
		}
		if (((mc->getY() - mc->getH()) >= (this->y - this->h - .02)) && ((mc->getY() - mc->getH()) <= (this->y) - .02)) {
			return true;
		}
	}
		return false;
}

float EnemyChar::getBoundry() {
    return boundry;
}

void EnemyChar::reset(float x, float y) {
	this->x = x;
	this->y = y;
}

EnemyChar::~EnemyChar() {
	delete characterBack;
}
