#include "Masina.h"
#include "Obiect.h"
#include <gl/freeglut.h>
#include <cmath>

void draw3DTyre();

Masina::Masina(double a, double b, double c,  double rcar) : Obiect(a, b, c)
{

	rotireMasina = rcar;

}

Masina::Masina() :Obiect() {}



void Masina::setRotireMasina(double rcar)
{
	rotireMasina = rcar;
}


double Masina::getRotireMasina()
{
	return rotireMasina;
}

void set3DCarMatrices()
{
	draw3DTyre();

	float vertices[] = { 0.5,0.5,0.5,
						0.5,0.5,1.5,
						0.5,1.1,1.5,
						0.5,0.8,0.5,

						1.5,0.5,0.5,
						1.5,0.8,0.5,
						1.5,1.1,1.5,
						1.5,0.5,1.5
	};

	int indices[] = { 0,1,2,3,
					  5,6,7,4,
					  6,2,1,5,
					  7,3,0,4,
					  5,1,0,4,
					  7,6,2,3 };

	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColor3f(0.647059, 0.164706, 0.164706);
	glDrawElements(GL_POLYGON, 24, GL_UNSIGNED_INT, indices);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);


	float verticesInRec[] = { 0.5,0.5,1.5,
							 0.5,1.1,1.5,
							 0.5,1.1,3.0,
							 0.5,0.5,3.0,


							1.5,0.5,1.5,
							1.5,1.1,1.5,
							1.5,1.1,3.0,
							1.5,0.5,3.0 };

	int indicesInRec[] = { 0,1,2,3,
					3,7,6,2,
					2,6,7,3,
					6,2,3,7,
					2,1,5,6,
					6,7,4,5,
					5,1,0,4,
					4,7,3,0,
					6,7,3,2 };

	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, verticesInRec);

	glDrawElements(GL_POLYGON, 36, GL_UNSIGNED_INT, indicesInRec);


	glDisableClientState(GL_VERTEX_ARRAY);


	float verticesTop[] = { 0.5,1.1,1.5,
						  0.5,1.5,1.7,
						  0.5,1.5,2.7,
						  0.5,1.1,3.0,

						  1.5,1.1,1.5,
						  1.5,1.5,1.7,
						  1.5,1.5,2.7,
						  1.5,1.1,3.0 };

	int indicesTop[] = { 0,4,5,1,
						1,2,3,0,
						0,3,7,4,
						4,5,6,7,
						7,3,2,6,
						6,2,1,5
	};

	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, verticesTop);

	glDrawElements(GL_POLYGON, 24, GL_UNSIGNED_INT, indicesTop);


	glDisableClientState(GL_VERTEX_ARRAY);


	//Front wind shield 
	glBegin(GL_POLYGON);
	glColor3f(0.196078, 0.6, 0.8);
	glVertex3f(0.51, 1.1, 1.485);
	glVertex3f(0.51, 1.49, 1.685);
	glVertex3f(1.49, 1.49, 1.685);
	glVertex3f(1.49, 1.1, 1.485);
	glEnd();

	//rear window 
	glBegin(GL_POLYGON);
	glColor3f(0.196078, 0.6, 0.8);
	glVertex3f(0.51, 1.15, 3.0);
	glVertex3f(0.51, 1.49, 2.71);
	glVertex3f(1.49, 1.49, 2.71);
	glVertex3f(1.49, 1.15, 3.0);
	glEnd();

	//leftdoor windows 
	glBegin(GL_POLYGON);
	glColor3f(0.196078, 0.6, 0.8);
	glVertex3f(0.49, 1.15, 1.57);
	glVertex3f(0.49, 1.49, 1.72);
	glVertex3f(0.49, 1.49, 2.65);
	glVertex3f(0.49, 1.15, 2.90);
	glEnd();

	//rightdoor windows 
	glBegin(GL_POLYGON);
	glColor3f(0.196078, 0.6, 0.8);
	glVertex3f(1.51, 1.15, 1.57);
	glVertex3f(1.51, 1.49, 1.72);
	glVertex3f(1.51, 1.49, 2.65);
	glVertex3f(1.51, 1.15, 2.90);
	glEnd();


	//back left Light of Car 
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(0.5, 0.8, 3.01);
	glVertex3f(0.7, 0.8, 3.01);
	glVertex3f(0.7, 0.7, 3.01);
	glVertex3f(0.5, 0.7, 3.01);
	glEnd();

	//back right Light of Car 
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(1.3, 0.8, 3.01);
	glVertex3f(1.5, 0.8, 3.01);
	glVertex3f(1.5, 0.7, 3.01);
	glVertex3f(1.3, 0.7, 3.01);
	glEnd();


	//front left Light of Car 
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex3f(0.5, 0.8, 0.489);
	glVertex3f(0.7, 0.8, 0.489);
	glVertex3f(0.7, 0.7, 0.489);
	glVertex3f(0.5, 0.7, 0.489);
	glEnd();


	//front right Light of Car 
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex3f(1.3, 0.8, 0.489);
	glVertex3f(1.5, 0.8, 0.489);
	glVertex3f(1.5, 0.7, 0.489);
	glVertex3f(1.3, 0.7, 0.489);
	glEnd();




	//Boot of car 
	glBegin(GL_POLYGON);
	glColor3f(0.309804, 0.309804, 0.184314);
	glVertex3f(0.5, 0.5, 3.0);
	glVertex3f(1.5, 0.5, 3.0);
	glVertex3f(1.5, 1.1, 3.0);
	glVertex3f(0.5, 1.1, 3.0);
	glEnd();

	//front grill 
	glBegin(GL_POLYGON);
	glColor3f(0.309804, 0.309804, 0.184314);

	glVertex3f(0.5, 0.5, 0.49);
	glVertex3f(1.5, 0.5, 0.49);
	glVertex3f(1.5, 0.8, 0.49);
	glVertex3f(0.5, 0.8, 0.49);
	glEnd();



}

void draw3DTyre()
{

	const auto tire_y_offset = 0.5;
	const auto tire_z_offset_front = 1.2;
	const auto tire_z_offset_back = 2.5;
	const auto tire_x_offset_right = 0.45;
	const auto tire_x_offset_left = 1.5;
	const auto tire_radius = 0.2;
	const auto tire_width = 0.07;
	const auto slices = 20;
	const auto stacks = 20;


	//left tyre 
	glPushMatrix();
	glColor3f(0.5, 0.5, 0);
	glTranslatef(tire_x_offset_left, tire_y_offset, tire_z_offset_front);
	glRotated(90, 0, 1, 0.0);
	glutSolidCylinder(0.2, 0.07, 20, 20);
	glPopMatrix();


	//right tyre
	glPushMatrix();
	glColor3f(0.5, 0.5, 0);
	glTranslatef(tire_x_offset_right, tire_y_offset, tire_z_offset_front);
	glRotated(90, 0, 1, 0.0);
	glutSolidCylinder(0.2, 0.07, 20, 20);
	glPopMatrix();


	// Draw back left tire
	glPushMatrix();
	glColor3f(0.5, 0.5, 0);
	glTranslatef(tire_x_offset_left, tire_y_offset, tire_z_offset_back);
	glRotated(90, 0, 1, 0.0);
	glutSolidCylinder(tire_radius, tire_width, slices, stacks);
	glPopMatrix();

	// Draw back right tire
	glPushMatrix();
	glColor3f(0.5, 0.5, 0);
	glTranslatef(tire_x_offset_right, tire_y_offset, tire_z_offset_back);
	glRotated(90, 0, 1, 0.0);
	glutSolidCylinder(tire_radius, tire_width, slices, stacks);
	glPopMatrix();


}






void Masina::Draw()
{

	glPushMatrix();
	glTranslated(getx(), gety(), getz());


	glColor3f(0.647059, 0.164706, 0.164706);
	glPushMatrix();
	glTranslated(-0.6, -1.2, 0);
	glRotated(rotireMasina, 0, 1, 0);
	set3DCarMatrices();
	glPopMatrix();


	glPopMatrix();

}

