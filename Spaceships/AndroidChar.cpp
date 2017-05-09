#include "AndroidChar.h"
#include<iostream>
using namespace std;


AndroidChar::AndroidChar(float x, float y, GLuint loadImg [12]) {
	this->x = x;
	this->y = y;
	w = .322;
	h = .480;

#if defined WIN32
	for (int i = 0; i < 12; i++) {
		androidImg[i] = loadImg[i];
	}
#else
	for (int i = 0; i < 12; i++) {
		androidImg[i] = loadImg[i];
	}
#endif

	characterBack = new TexRect(x + 0.1, y + 0.1, w, h);
}

void AndroidChar::draw() {
	delete characterBack;
	characterBack = new TexRect(x + 0.1, y + 0.1, w, h);
	// Set Color
	glColor3f(1.0, 1.0, 1.0);

	glBindTexture(GL_TEXTURE_2D, androidImg[(animateCount++/50) % 12]);
	characterBack->draw();
<<<<<<< HEAD
=======
	//cout << "draw called" << endl;
}

bool AndroidChar::contains(MainChar * mc) {
	if (((mc->getX() >= this->x) && (mc->getX() <= (this->x + this->w))) || (((mc->getX() + mc->getH()) >= this->x) && ((mc->getX() + mc->getH()) <= (this->x + this->w)))) {
		if (((mc->getY() - mc->getH()) >= (this->y - this->h)) && ((mc->getY() - mc->getH()) <= (this->y))) {
			//cout << "Main Char x: " << mc->getX() << "  " << (mc->getX() + mc->getH()) << endl;
			//cout << "Main Char y: " << mc->getY() << "  " << (mc->getY() - mc->getH()) << endl;
			//cout << "Enemy Char x: " << this->x << "  " << (this->x + this->h) << endl;
			//cout << "Enemy Char Y: " << this->y << "  " << (this->y - this->h) << endl;
			return true;
		}
	}
	return false;
>>>>>>> 116049798de4029f7586066e947a9444131b0b6e
}
