#ifndef CrashDialog_h
#define CrashDialog_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "TexRect.h"

class CrashDialog {
	float x = -0.472/2.0;
	float y = -0.255/2.0;
	float w = 0.472;
	float h = 0.255;
public:
	CrashDialog(GLuint loadImg);
	void draw();

	GLuint crashImg;
	TexRect *crashBack;
};

#endif