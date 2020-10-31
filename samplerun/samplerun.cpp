#include "main.h"

void setCamera(void) {
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, (GLdouble)WINDOW_WIDTH / (GLdouble)WINDOW_HEIGHT, 0.1f, 100.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.f, 4.f, 4.f, 0.f, 1.f, -2.f, 0.f, 1.f, 0.f);
}

void setUICamera(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, 1.f, 1.f, 1.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);
}

void setLight(void)
{
	GLfloat light_position[4] = { 0.f, 4.f, 1.f, 1.f };
	GLfloat light_ambient[4] = { 0.5f, 0.5f, 0.5f, 0.f };
	GLfloat light_diffuse[4] = { 1.f, 1.f, 1.f, 1.f };
	GLfloat light_specular[4] = { 1.f, 1.f, 1.f, 1.f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		if (player.state_v == 3) {
			player.state_v = 2;
			player.state_vi = 0;
		}
		break;
	case 's':
		if (player.state_v == 3) {
			player.state_v = 1;
			player.state_vi = 1;
		}
		break;
	case 'a':
		player.state_hi = 0; 
		break;
	case 'd':
		player.state_hi = 2;
		break;
	case ' ':
		switch (scene) {
			case 0:
			case 2:
				player = Player();
				lane = looplane();
				score = 0;
				scene = 1; break;
		}
		break;
	default:break;
	}
	glutPostRedisplay();
}

void keyboardup(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
	case 'd':
		player.state_hi = 1;
		break;
	}
	glutPostRedisplay();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	setCamera();
	setLight();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	lane.display();
 	player.display();

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);

	setUICamera();
	switch (scene) {
	case 0:
		msg.printtitle();
		msg.printtips();
		break;
	case 2:
		msg.printgameover();
		msg.printtips();
		num.printresult(score);
		break;
	default:
		num.print(score);
		break;
	}

	glutSwapBuffers();
}

void update(void){
	t = u;
	u = clock();
	dt = ((double)u - (double)t) / CLOCKS_PER_SEC;
	if (scene==1) {
		if (lane.isover(player.state_h, player.state_v)) {
			scene = 2;
		}
		score += (long)(dt * 1000);
		if (lane.getcoin(player.state_h, player.state_v)) {
			score += 10000;

		}
		player.update(dt);
		lane.update(dt);	
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("SAMPLE RUN");
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	player = Player();
	lane = looplane();
	num = number();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardup);
	glutIdleFunc(update);
	glutMainLoop();

	return 0;

}