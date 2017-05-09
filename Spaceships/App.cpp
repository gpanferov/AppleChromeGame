#include "App.h"

int timer = 1;
int enemyRate = 5;
int a = 1;

void App::enemyCreation() {
	timer++;

	if (timer % (3000*enemyRate) == 0) {
		a++;
		
	}
	if (a % 4 == 0) {
		//ec->changeSpeed();
		//cout << "speed changed" << endl;
	}
}



App::App(const char* label, int x, int y, int w, int h) : GlutApp(label, x, y, w, h) {

#if defined WIN32
	characterImg = loadTexture("..\\apple.bmp");
	enemycharacterImg = loadTexture("..\\windows.bmp");
	for (int i = 0; i < 12; i++) {
		string name = "..\\flying_android_" + to_string(i);
		name += + ".bmp";
		const char *N = name.c_str();
		android[i] = loadTexture(N);
	}
	crashImg = loadTexture("..\\crash_img.bmp");
#else
	characterImg = loadTexture("apple.bmp");
	for (int i = 0; i < 12; i++) {
		string name = "flying_android_" + i;
		name += +".bmp";
		android[i] = loadTexture(name.c_str);
	}
	crashImg = loadTexture("crash_img.bmp");
#endif
	mc = new MainChar(MAINCHAR_X, MAINCHAR_Y, characterImg);
	ac = new AndroidChar(1.0, 0.55, android);
	ec = new EnemyChar(1.0, -.19, enemycharacterImg);
	cd = new CrashDialog(crashImg);
	enemyMove = true;
	//characterBack = new TexRect(MAINCHAR_X + 0.1, MAINCHAR_Y + 0.1, 0.2, 0.2);
}

GLuint App::loadTexture(const char *filename) {
	GLuint texture_id;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	//    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );


	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);





	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
		GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());

	return texture_id;

}



void App::draw() {

	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to white
	glClearColor(1.0, 1.0, 1.0, 1.0);
	
	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (!loop) {
		cd->draw();
	}

	//draws the beginning piece

	mc->draw();
	ac->draw();
	ec->draw();
		
	/*for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->draw();
	}
	*/
	
	//glColor3f(1.0, 1.0, 1.0);
	//glBindTexture(GL_TEXTURE_2D, characterImg);
	//characterBack->draw();


	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(-1.0, .5);
	glVertex2f(1.0, .5);

	glVertex2f(-1.0, -.25);
	glVertex2f(1.0, -.25);
	glEnd();

	



	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

void App::keyPress(unsigned char key) {
	if (key == 27) {
		// Exit the app when Esc key is pressed
		delete this;
		exit(0);
	}
	else if (key == ' ') {
		// Uncomment below to enable user to stop moving
		jump = true;
	}
	//13 is for the enter key "press enter if you would like to start the game"
	else if (key == 13) {
		//	main_char->draw()
		//gameStart = !gameStart
		
	}

	//left key
	else if (key == 37) {

	}

	//right key
	else if (key == 39) {

	}

	//up key
	else if (key == 38) {
		move = !move;
	}

	//down key
	else if (key == 40) {

	}

	else if (key == 'f') {
		ec->setX(1.1);
		ac->setX(1.1);
		loop = true;
	}
}

void App::idle() {
	// loop should always be true, unless it's game over
	if (loop) {
		enemyCreation();
		if (ec->contains(mc)) {
			cout << "end game" << endl;
			loop = false;
		}
		if (enemyMove) {//this is to make the enemy move from right to left
			ac->decrementX();
			ec->decrementX();
			if ((ec->getX() + ec->getH()) < -1.5) {
				ec->setX(1.1);
			}

			if ((ac->getX() + ec->getH()) < -1.5) {
				ac->setX(1.1);
			}
		}
		if (jump) {
			float tmp_y = mc->getY();
			//cout << tmp_y << ", " << top_of_jump << endl;
			if (tmp_y >= JUMP_HEIGHT) {
				top_of_jump = true;
				mc->setY(JUMP_HEIGHT);
				//cout << "TOP" << endl;
			} else if (tmp_y <= RUN_HEIGHT) {
				top_of_jump = false;
				jump = false;
				mc->setY(RUN_HEIGHT);
				//cout << "BOTTOM" << endl;
			}
			if (!top_of_jump && tmp_y <= JUMP_HEIGHT) {
				mc->incrementY();
				//cout << "UP" << endl;
			}
			if (top_of_jump && tmp_y >= RUN_HEIGHT) {
				mc->decrementY();
				//cout << "DOWN" << endl;
			}

		}

		if (gameover) {
			// Stop looping, otherwise final message will be displayed many times
			loop = false;
		}

		// Redraw the scene after all modifications have been made
		//sleep_for(nanoseconds(1000));
		redraw();
	}
}

App::~App() {

}
