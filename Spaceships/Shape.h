#ifndef Shape_hpp
#define Shape_hpp

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class Shape {
	
	// Color
	float r, g, b;

public:
	// Default constructor
	Shape() {};

	// Draw method
	virtual void draw() {};

	virtual bool contains() = 0;

	
	float getR() const { return r; }
	float getG() const { return g; }
	float getB() const { return b; }
	void setColor(float rr, float gg, float bb) { r = rr; g = gg; b = bb; }
};

#endif
