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
#include"MainChar.h"

class  EnemyChar {
protected:
	float x = 0;
	float y = 0;
	float h = 0.15;
	float dec = 0.005;
	EnemyChar();
public:
	// Default constructor
	// TODO: Implement a default constructor (AndroidChar won't work without it)
	EnemyChar(float x, float y, GLuint loadImg);
	void draw();
	void incrementX();
	void decrementX();
	float getX();
	void setX(float x);
	float getH();
	void changeSpeed();
	
	bool contains(MainChar * mc);

	GLuint characterImg;
	TexRect *characterBack;
};

#endif
