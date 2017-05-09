#include "CrashDialog.h"

CrashDialog::CrashDialog(GLuint loadImg) {
#if defined WIN32
	crashImg = loadImg;
#else
	crashImg = loadImg;
#endif

	crashBack = new TexRect(x + 0.1, y + 0.1, h, h);
}

void CrashDialog::draw() {
	delete crashBack;
	crashBack = new TexRect(-0.7, -0.5, 0.8, 0.5);
	// Set Color
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, crashImg);
	crashBack->draw();
}