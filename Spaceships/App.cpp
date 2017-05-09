#include "App.h"







float App::enemyCreation() {
	
	float num = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
	float final_num = 0.5 - num;
	return final_num;
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
	//windowsImg = loadTexture("..\\windows_xp.bmp");
#else
	characterImg = loadTexture("apple.bmp");
	for (int i = 0; i < 12; i++) {
		string name = "flying_android_" + i;
		name += +".bmp";
		android[i] = loadTexture(name.c_str);
	}
	crashImg = loadTexture("crash_img.bmp");
	windowsImg = loadTexture("windows_xp.bmp");
#endif
	
	mc = new MainChar(MAINCHAR_X, MAINCHAR_Y, characterImg);
	enemies.push_back(new AndroidChar(4.5, 0.55, android));
	enemies.push_back(new AndroidChar(8.5, 0.55, android));
	enemies.push_back(new EnemyChar(2.5, -.19, enemycharacterImg));
	enemies.push_back(new EnemyChar(6.5, -.19, enemycharacterImg));
	srand(time(NULL));
	
	ac = new AndroidChar(1.0, 0.55, android);
	ec = new EnemyChar(1.0, -.19, enemycharacterImg);
	cd = new Image(0.472, 0.255, 0.472/2.0, 0.255/2.0, crashImg);
	//wb = new Image(-1, -1, 1, 0.1354, windowsImg);

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
	//wb->draw();

	//draws the beginning piece

	mc->draw();
	for (int i = 0; i < 4; i++) {
		enemies[i]->draw();
	}
	
		
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
	else if (key == 'd') {

	}

	//up key
	else if (key == 'w') {
		move = !move;
	}

	//down key
	else if (key == 's') {
		mc->crouch();
	}

	else if (key == 'f') {
		
		//ec->setX(1.1);
		//ac->setX(1.1);
		//loop = true;
	}
}

void App::idle() {
	// loop should always be true, unless it's game over
	if (loop) {
		
		if (enemies[2]->contains(mc) || enemies[3]->contains(mc)) {
			cout << "end game" << endl;
			loop = false;
		}
		if (enemyMove) {//this is to make the enemy move from right to left
			enemies[0]->decrementX();
			enemies[1]->decrementX();
			enemies[2]->decrementX();
			enemies[3]->decrementX();
			float num = enemyCreation() + 6.5;
			
			if ((enemies[0]->getX() + enemies[0]->getH()) < -1.5) {
				enemies[0]->setX(num);
				cout << num << endl;
			}
			if ((enemies[1]->getX() + enemies[1]->getH()) < -1.5) {
				enemies[1]->setX(num);
				cout << num << endl;
			}
		
			if ((enemies[2]->getX() + enemies[2]->getH()) < -1.5) {
				enemies[2]->setX(num);
				cout << num << endl;
			}
			if ((enemies[3]->getX() + enemies[3]->getH()) < -1.5) {
				enemies[3]->setX(num);
				cout << num << endl;
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
