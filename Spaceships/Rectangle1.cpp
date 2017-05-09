#include "Rectangle1.h"



void Rectangle1::draw(){
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
    
    glVertex2f(x, y);
    glVertex2f(x+w, y);
    glVertex2f(x+w, y-h);
    glVertex2f(x, y-h);
    
    glEnd();
}


bool Rectangle1::contains(float x, float y, float h) {
	if ((this->x + this->h == x) && ((this->y - this->h) > (y - h) && (this->y - this->h) < y)) {
		return true;
	}
	else return false;
}

void jump() {
	//y +.1
	

}