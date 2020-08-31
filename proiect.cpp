#include <gl/freeglut.h>
#include <cmath>
#include "Masina.h"
#include "Obiect.h"

#define PI 3.14159265

Masina masina(0, 1, 0, 0);



int refreshMills = 8;
int g = 0;

float angle = 0;
float lx = 0.0f, lz = -1.0f, ly = 0.0f;
float xc = 0.0f, zc = 10.0f, yc = 3.0f;
double xcOffset = 0, zcOffset = 0;


void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(refreshMills, timer, 0);
}

enum {
	IARNA, DESERT
};

int rendermode = DESERT;

void menu(int selection)
{
	rendermode = selection;
	glutPostRedisplay();
}

void changeSize(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}


void drawTree()
{

	//glColor3f(1, 1, 1);
	glColor3f(0.3, 0.2, 0.1);
	glTranslatef(0.0, 0.5, 0.0);
	glRotated(270, 1, 0, 0);
	glutSolidCone(1, 6, 10, 2);

	glEnable(GL_BLEND);
	glDepthMask(GL_FALSE);

	GLfloat diffuseCoeff2[] = { 0.2, 0.4, 0.15, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, diffuseCoeff2);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);

	glColor3f(1, 1, 1);
	//glColor3f(0.2, 0.4, 0.15);
	glTranslatef(0.0, 0.0, 2.0);
	glutSolidCone(1.5, 5, 10, 2);

	GLfloat diffuseCoeff3[] = { 0.2, 0.4, 0.1, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, diffuseCoeff3);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);

	glColor3f(1, 1, 1);
	//glColor3f(0.2, 0.4, 0.1);
	glTranslatef(0.0, 0.0, 2.1);
	glutSolidCone(1.8, 3, 10, 2);

	GLfloat diffuseCoeff4[] = { 0.2, 0.42, 0.15, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, diffuseCoeff4);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);

	glColor3f(1, 1, 1);
	//glColor3f(0.2, 0.42, 0.15);
	glTranslatef(0.0, 0.0, 2.2);
	glutSolidCone(1.8, 4, 10, 2);

	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);



}

void drawBrownDesertTree()
{

	glColor3f(0.3, 0.2, 0.1);
	glTranslatef(0.0, 0.5, 0.0);
	glRotated(270, 1, 0, 0);
	glutSolidCone(1, 5, 10, 2);

	glEnable(GL_BLEND);
	glDepthMask(GL_FALSE);

	GLfloat diffuseCoeff2[] = { 0.2, 0.4, 0.15, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, diffuseCoeff2);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);

	glColor3f(0.3, 0.2, 0.1);
	glTranslatef(0.0, 0.0, 2.0);
	glutSolidCone(1.5, 4, 10, 2);

	GLfloat diffuseCoeff3[] = { 0.2, 0.4, 0.1, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, diffuseCoeff3);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);

	glColor3f(0.3, 0.2, 0.1);
	glTranslatef(0.0, 0.0, 2.1);
	glutSolidCone(1.8, 2, 10, 2);

	GLfloat diffuseCoeff4[] = { 0.2, 0.42, 0.15, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, diffuseCoeff4);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);

	/*glColor3f(0.3, 0.2, 0.1);
	glTranslatef(0.0, 0.0, 2.2);
	glutSolidCone(1.8, 3, 10, 2);*/

	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);



}

void setRoadMatrices()
{
	glBegin(GL_POLYGON);
	glColor3f(0.184314, 0.309804, 0.309804);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0, 0.05, -100.0);
	glVertex3f(3.5, 0.05, -100.0);
	glVertex3f(3.5, 0.05, 100.0);
	glVertex3f(-1.0, 0.05, 100.0);
	glEnd();

}

//white lines on road 
void drawWhiteLines()
{



	for (float i = -70; i < 70; i = i + 15)
	{
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glVertex3f(0.8, 0.07, i);
		glVertex3f(1.15, 0.07, i);
		glVertex3f(1.15, 0.07, i + 5);
		glVertex3f(0.8, 0.07, i + 5);
		glEnd();
	}

}

void desert()
{


	// Draw ground
	glColor3f(0.623529, 0.623529, 0.372549);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();


	//display road 
	glPushMatrix();
	setRoadMatrices();
	glPopMatrix();

	//display white lines on road 
	glPushMatrix();
	drawWhiteLines();
	glPopMatrix();


	//drawing trees
	int i, j;
	for (i = -2; i < 3; i++)
		for (j = -2; j < 3; j++)
		{
			if (i != 0 && j != 0)
			{
				glPushMatrix();
				glTranslatef(i * 15.0, 0, j * 17.0);
				drawBrownDesertTree();
				glPopMatrix();
			}
		}





}

void drawSnowMan()
{
	glColor3f(1.0f, 1.0f, 1.0f);

	// Draw Body
	glTranslatef(0.0f, 0.75f, 0.0f);
	glutSolidSphere(0.75f, 20, 20);

	// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f, 20, 20);

	// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f, 10, 10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 10, 10);
	glPopMatrix();

	// Draw Nose
	glColor3f(1.0f, 0.5f, 0.5f);
	glutSolidCone(0.08f, 0.5f, 10, 2);
}

void iarna()
{

	// Draw ground
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);

	//glNormal3i(0, -1, 0);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();

	//display road
	glPushMatrix();
	setRoadMatrices();
	glPopMatrix();

	//display white lines on road 
	glPushMatrix();
	drawWhiteLines();
	glPopMatrix();


	// Draw SnowMen
	int i, j;
	for (i = -2; i < 3; i++)
		for (j = -2; j < 3; j++)
		{
			if (i != 0 && j != 0)
			{
				glPushMatrix();
				glTranslatef(i*10.0, 0, j * 10.0);
				drawSnowMan();
				glPopMatrix();
			}
		}


	for (i = -2; i < 3; i++)
		for (j = -2; j < 3; j++)
		{
			if (i != 0 && j != 0)
			{
				glPushMatrix();
				glTranslatef(i*15.0, 0, j * 17.0);
				drawTree();
				glPopMatrix();
			}
		}
}


void deseneazaObiecte()
{

	masina.Draw();

}


void lumina()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat pozitial0[] = { 10.0, 5.0, 10.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pozitial0);

	glColor3f(1.000, 0.843, 0.000);
	glPushMatrix();
	glTranslatef(10.0, 12.0, -25.0);
	glutSolidSphere(2.0f, 30, 30);
	glPopMatrix();



}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	lumina();

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glLoadIdentity();
	glClearColor(0.0, 0.8, 1.0, 0.0);


	gluLookAt(xc + xcOffset, yc + ly, zc + zcOffset, masina.getx(), masina.gety(), masina.getz(), 0, 1, 0);


	deseneazaObiecte();

	switch (rendermode) {
	case IARNA:
		iarna();
		break;
	case DESERT:
		desert();
		break;
	};

	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		masina.setz(masina.getz() - sin((masina.getRotireMasina() + 90) * PI / 180));
		masina.setx(masina.getx() + cos((masina.getRotireMasina() + 90) * PI / 180));
		zcOffset -= sin((masina.getRotireMasina() + 90) * PI / 180);
		xcOffset += cos((masina.getRotireMasina() + 90) * PI / 180);
		break;
	case 'p':
		masina.setz(masina.getz() - 1.5*sin((masina.getRotireMasina() + 90) * PI / 180));
		masina.setx(masina.getx() + 1.5*cos((masina.getRotireMasina() + 90) * PI / 180));
		zcOffset = zcOffset - 1.5*sin((masina.getRotireMasina() + 90) * PI / 180);
		xcOffset = xcOffset + 1.5*cos((masina.getRotireMasina() + 90) * PI / 180);
		break;
	case 's':

		masina.setz(masina.getz() + sin((masina.getRotireMasina() + 90) * PI / 180));
		masina.setx(masina.getx() - cos((masina.getRotireMasina() + 90) * PI / 180));
		zcOffset += sin((masina.getRotireMasina() + 90) * PI / 180);
		xcOffset -= cos((masina.getRotireMasina() + 90) * PI / 180);


		break;
	case 'a':
		angle += 0.0175f;
		masina.setRotireMasina(masina.getRotireMasina() + 1);
		break;
	case 'd':
		angle -= 0.0175f;
		masina.setRotireMasina(masina.getRotireMasina() - 1);

		xc = 10 * sin(angle);
		zc = 10 * cos(angle);
		break;



		break;


	}

	if (key == 27)
		exit(0);

}

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {

	case GLUT_KEY_UP:
		yc -= 0.1;
		break;
	case GLUT_KEY_DOWN:
		yc += 0.1;
		break;
	case GLUT_KEY_LEFT:
		angle -= 0.02f;
		xc = 10 * sin(angle);
		zc = 10 * cos(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.02f;
		xc = 10 * sin(angle);
		zc = 10 * cos(angle);
		break;

	}
}

int main(int argc, char **argv) {
	int ok = 0;
	if (ok == 0)
	{

		ok = 1;
	}
	// init GLUT and create window
	glutInit(&argc, argv);
	glColor3f(0.3f, 0.7f, 0.9f);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Proiect 3D");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	// OpenGL init
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);

	//Right Click Menu
	glutCreateMenu(menu);
	glutAddMenuEntry("Desert", DESERT);
	glutAddMenuEntry("Iarna", IARNA);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// enter GLUT event processing cycle
	glutTimerFunc(0, timer, 0);

	glutMainLoop();

	return 1;
}