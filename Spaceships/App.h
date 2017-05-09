#ifndef App_hpp
#define App_hpp

#include <iostream> 
#include "GlutApp.h"
#include "TexRect.h"
#include <math.h>
#include <string>
#include <deque>
#include <chrono>
#include "MainChar.h"
#include "AndroidChar.h"

#define MAINCHAR_X -0.8
#define MAINCHAR_Y -0.13
#define JUMP_HEIGHT 0.4
#define RUN_HEIGHT -0.15

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;

class App : public GlutApp {
	// Maintain app state here


	bool move;
	bool jump = false;
	bool top_of_jump = false;
	int score;
	bool enemyMove = false;
	bool gameover = false;
	bool loop = true;

public:
	MainChar *mc;
	AndroidChar *ac;
	EnemyChar * ec;
	// Constructor, to initialize state
	App(const char* label, int x, int y, int w, int h); 
	void draw();
	void keyPress(unsigned char key);
	void idle();
	void enemyCreation();
	GLuint loadTexture(const char* filename);

	GLuint characterImg;
	GLuint enemycharacterImg;
	GLuint android[12];
	GLuint wall;

	TexRect* characterBack;
	TexRect* background;

	~App();
};

#endif