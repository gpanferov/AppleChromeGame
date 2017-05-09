#include "EnemyChar.h"


using namespace std;

EnemyChar::EnemyChar(float x, float y, GLuint loadImg) {
	this->x = x;
	this->y = y;

#if defined WIN32
	characterImg = loadImg;
#else
	characterImg = loadImg;
#endif

	characterBack = new TexRect(x + 0.1, y + 0.1, 0.2, 0.2);
}

GLuint EnemyChar::loadTexture(const char *filename) {
	GLuint texture_id;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );


	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);





	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
		GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

	return texture_id;

}

float EnemyChar::getX() {
	return x;
}

void EnemyChar::incrementX() {
	x += 0.01;
}

void EnemyChar::decrementX() {
	x -= 0.01;
}

void EnemyChar::draw() {
	delete characterBack;
	characterBack = new TexRect(x + 0.1, y + 0.1, 0.2, 0.2);
	// Set Color
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, characterImg);
	characterBack->draw();
}