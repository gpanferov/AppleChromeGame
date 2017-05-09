#include "EnemyChar.h"


using namespace std;

EnemyChar::EnemyChar() {};

EnemyChar::EnemyChar(float x, float y, GLuint loadImg) {
	this->x = x;
	this->y = y;

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
			cout << "Main Char x: " << mc->getX() << "  " << (mc->getX() + mc->getH()) << endl;
			cout << "Main Char y: " << mc->getY() << "  " << (mc->getY() - mc->getH()) << endl;
			cout << "Enemy Char x: " << this->x << "  " << (this->x + this->h) << endl;
			cout << "Enemy Char Y: " << this->y << "  " << (this->y - this->h) << endl;
			return true;
		}
	}
		return false;
}
