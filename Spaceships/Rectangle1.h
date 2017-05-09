#ifndef Rectangle1_hpp
#define Rectangle1_hpp

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include<Shape.h>



	class Rectangle1 {
		// Position
		float x, y;

		// Size
		float w, h;

		float r, g, b;
	public:

		Rectangle1(){}

		// Default constructor
		Rectangle1(float xx = 0, float yy = 0, float ww = 0.1, float hh = 0.1, float rr = 1, float gg = 0, float bb = 0) :
			x(xx), y(yy), w(ww), h(hh) {}

		// Draw method
		void draw();

		bool contains(float x, float y, float h);

		void jump();

		// Getters and setters
		float getX() const { return x; }
		float getY() const { return y; }
		void setX(float xx) { x = xx; }
		void setY(float yy) { y = yy; }

		float getW() const { return w; }
		float getH() const { return h; }
		void setW(float ww) { w = ww; }
		void setH(float hh) { h = hh; }

	};

#endif
