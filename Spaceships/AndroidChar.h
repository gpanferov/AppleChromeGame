#ifndef AndroidChar_h
#define AndroidChar_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "EnemyChar.h"

class AndroidChar : public EnemyChar {
	int animateCount = 0;
public:
	AndroidChar(float x, float y, GLuint loadImg []);
	void draw();

	GLuint androidImg[12];
};

#endif