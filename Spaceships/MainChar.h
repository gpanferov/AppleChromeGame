#ifndef MainChar_h
#define MainChar_h

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

class MainChar {
	float x = 0;
	float y = 0;
	float h = 0.2;
	float c = 0.0;
 
public:
	// Default constructor
	MainChar(float x, float y, GLuint loadImg);
	void draw();
	void incrementY();
	void decrementY();
	float getY();
	float getX();
	float getH();

	void crouch();



	void setY(float y);
	

	GLuint characterImg;
	TexRect *characterBack;
};

#endif
