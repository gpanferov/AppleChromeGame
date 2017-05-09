#ifndef Texture_h
#define Texture_h
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include "RgbImage.h"

class Texture {
public:
	Texture() {};
	~Texture() {};

	GLuint loadTexture(const char* filename);
	virtual void draw() = 0;
};

#endif
