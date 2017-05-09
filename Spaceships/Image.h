#ifndef Image_h
#define Image_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "TexRect.h"

class Image {
	float x = -0.472/2.0;
	float y = -0.255/2.0;
	float w = 0.472;
	float h = 0.255;
public:
	Image(float x, float y, float w, float h, GLuint loadImg);
	void draw();

	GLuint img;
	TexRect *back;
};

#endif
