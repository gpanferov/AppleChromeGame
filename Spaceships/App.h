#ifndef App_h
#define App_h

#include <iostream>
#include "GlutApp.h"
#include "TexRect.h"
#include <math.h>
#include <string>
#include <vector>
#include <chrono>
#include "MainChar.h"
#include "AndroidChar.h"
#include <ctime>
#include "Image.h"
#include <Windows.h>
#include <mmsystem.h>

#define MAINCHAR_X -0.8
#define MAINCHAR_Y -0.13
#define JUMP_HEIGHT 0.4
#define RUN_HEIGHT -0.131

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;

class App : public GlutApp {
	// Maintain app state here


	bool move;
	bool jump = false;
	bool top_of_jump = false;
	int score = 0;
	bool enemyMove = false;
	bool gameplay = true;
	bool loop = false;
	bool crouch = false;
	bool isDown = false;
	bool godMode = false;


public:
	vector<EnemyChar*> enemies;
	MainChar *mc;
	Image *cd; // CrashDialog
	Image *ss;
	//Image *wb; // WindowsBack
	// Constructor, to initialize state
	App(const char* label, int x, int y, int w, int h);
	void draw();
	void keyPress(unsigned char key);
	void replay();
	void idle();

	float enemyCreation();
	void displayScoreInfo();
	void displayTitleInfo();
	void displayRulesInfo();
	void RenderString(GLdouble x, GLdouble y, const std::string &string);
	void increaseSpeed();
	//void replay();
	GLuint loadTexture(const char* filename);

	GLuint characterImg;
	GLuint enemycharacterImg;
	GLuint android[12];
	GLuint crashImg;
	GLuint startImg;
	//GLuint windowsImg;

	~App();
};

#endif
