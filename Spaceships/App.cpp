#include "App.h"



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
    startImg = loadTexture("..\\startup_screen.bmp");
#else
    characterImg = loadTexture("apple.bmp");
    enemycharacterImg = loadTexture("windows.bmp");
    for (int i = 0; i < 12; i++) {
        string name = "flying_android_" + to_string(i);
        name += + ".bmp";
        const char *N = name.c_str();
        android[i] = loadTexture(N);
    }
    crashImg = loadTexture("crash_img.bmp");
    startImg = loadTexture("startup_screen.bmp");
#endif
    
    
    mc = new MainChar(MAINCHAR_X, MAINCHAR_Y, characterImg);
    enemies.push_back(new AndroidChar(4.5, 0.133, -1.0, android));
    enemies.push_back(new AndroidChar(8.5, 0.133, -1.0, android));
    enemies.push_back(new EnemyChar(2.5, -.19, -1.3, enemycharacterImg));
    enemies.push_back(new EnemyChar(6.5, -.19, -1.3, enemycharacterImg));
	enemies.push_back(new AndroidChar(10.5, 0.133, -1.0, android));
	enemies.push_back(new EnemyChar(12.5, -.19, -1.3, enemycharacterImg));
    srand(time(NULL));
    
    ss = new Image(-1 - 0.1, 1 - 0.1, 2, 2, startImg);
    cd = new Image(-0.472 * 1.75, 0.255 * 1.75 - 0.05, 0.472 * 3.0, 0.255 * 3.0, crashImg);
    
    enemyMove = true;
    
    PlaySound("..\\Mac_Startup.wav", NULL, SND_FILENAME);
}

//This function is to increase the speed as the score increases
void App::increaseSpeed() {
    if ((score + 1) % 10 == 0) {
        score++;
        for (int enemySize = 0; enemySize < enemies.size(); enemySize++) {
            enemies[enemySize]->changeSpeed();
        }
    }
}
//This function randomizes the locations for the enemy
float App::enemyCreation() {
    float num = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
    float final_num = 0.5 - num;
    return final_num;
}


//Displays the score
void App::displayScoreInfo() {
    string a = ("The score is: " + to_string(score));
    RenderString(-.3, .8, a);
}
//Displays the title
void App::displayTitleInfo() {
    string a = ("Apple Chrome Game");
    RenderString(-.4, .9, a);
}
//Displays the rules
void App::displayRulesInfo() {
    string a = ("Press Space To Jump: Press S To Crouch");
    RenderString(-.7, -.7, a);
}

void App::displayResetInfo() {
    string a = ("Press F to reset");
    RenderString(-.2, -.7, a);
}
//Renders the string and uses BitmapChar to display text
void App::RenderString(GLdouble x, GLdouble y, const std::string &string)
{
    glColor3d(0.0, 0.0, 0.0);
    glRasterPos2d(x, y);
    for (int n = 0; n<string.size(); ++n) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[n]);
    }
}


//Texture function
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
    
    if (!gameplay) {
        cd->draw();
		displayResetInfo();
    }
    if (!loop && gameplay) {
        ss->draw();
    }
	
    
    //Draws our main character and our enemies
    mc->draw();
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->draw();
    }
    //Displays the text
    displayScoreInfo();
    if (score == 0 && gameplay) {
        displayTitleInfo();
        displayRulesInfo();
    }
    
    //This is the main draw
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
        if (crouch) {
            mc->crouch();
            crouch = !crouch;
        }
        jump = true;
    }
    //13 is for the enter key "press enter if you would like to start the game"
    else if (key == 13) {
        loop = true;
        
    }
    
    
    //right key
    else if (key == 'd') {
        godMode = !godMode;
    }
    
    //up key
    else if (key == 'w') {
        move = !move;
    }
    
    //down key
    else if (key == 's') {
        if (loop) {
            crouch = !crouch;
            if (!jump)
                mc->crouch();
        }
    }
    
    else if (key == 'f') {
        replay();
    }
    
}

void App::replay() {
    mc->reset(MAINCHAR_X, MAINCHAR_Y);
    enemies[0]->reset(4.5, 0.133);
    enemies[1]->reset(8.5, 0.133);
    enemies[2]->reset(2.5, -.19);
    enemies[3]->reset(6.5, -.19);
	enemies[4]->reset(10.5, 0.133);
	enemies[5]->reset(12.5, -.19);
    srand(time(NULL));
    gameplay = true;
    loop = true;
    score = 0;
}

void App::idle() {
    if (loop) {
        if (!godMode) {
            if (enemies[0]->contains(mc) || enemies[1]->contains(mc) || enemies[2]->contains(mc) || enemies[3]->contains(mc) || enemies[4]->contains(mc) || enemies[5]->contains(mc)) {
                gameplay = !gameplay;
                cout << score << endl;
                loop = !loop;
            }
        }
        if (enemyMove) {
            enemies[0]->decrementX();
            enemies[1]->decrementX();
            enemies[2]->decrementX();
            enemies[3]->decrementX();
			enemies[4]->decrementX();
			enemies[5]->decrementX();

            increaseSpeed();
            float num = enemyCreation() + 10.0;
            for (int i = 0; i < enemies.size(); i++){
                if ((enemies[i]->getX() + enemies[i]->getH()) < enemies[i]->getBoundry()) {
                    enemies[i]->setX(num);
                    enemies[i]->is_increment = false;
                 
                }
            }
            for (int i = 0; i < enemies.size(); i++){
                if ((enemies[i]->getX() + enemies[i]->getH()) < -.8 && (enemies[i]->getX() + enemies[i]->getH()) >= enemies[i]->getBoundry()) {
                    if (!(enemies[i]->is_increment)) {
                        score++;
                        enemies[i]->is_increment = true;
                    }
                }
            } 
        }
        if (jump && !mc->get_is_crouch()) {
            float tmp_y = mc->getY();
            if (tmp_y >= JUMP_HEIGHT) {
                top_of_jump = true;
                mc->setY(JUMP_HEIGHT);
            } else if (tmp_y <= RUN_HEIGHT) {
                top_of_jump = false;
                jump = false;
                mc->setY(RUN_HEIGHT);
            }
            if (!top_of_jump && tmp_y <= JUMP_HEIGHT) {
                mc->incrementY();
            }
            if (top_of_jump && tmp_y >= RUN_HEIGHT) {
                mc->decrementY();
            }
        }
        
        
        // Redraw the scene after all modifications have been made
        sleep_for(nanoseconds(100));
        redraw();
    }
}

App::~App() {
    enemies.clear();
    delete mc;
    delete cd;
    delete ss;
}
