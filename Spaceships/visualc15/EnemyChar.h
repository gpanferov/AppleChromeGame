#ifndef EnemyChar_h
#define EnemyChar_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <iostream>
#include <chrono>
#include <thread>
#include "TexRect.h"
#include "RgbImage.h"

class  EnemyChar{
	float x = 0;
	float y = 0;

public:
	// Default constructor
	EnemyChar(float x, float y, GLuint loadImg);
	void draw();
	void incrementX();
	void decrementX();
	float getX();

	GLuint EnemyChar::loadTexture(const char *filename);

	GLuint characterImg;
	TexRect *characterBack;
};

#endif
