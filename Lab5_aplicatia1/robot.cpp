/*
 *  Compunerea transformarilor geometrice pentru desenarea obiectelor animate ierarhice.
 *  Interactiune: sagetile
 */
#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"

static int shoulder = 0, elbow = 0, shouldermij=0, elbowmij=0;
static float lungimeBrat = 2,lungimeAntebrat = 1.5;

void CALLBACK elbowAdd()
{
	elbow = (elbow + 5) % 360;
}

void CALLBACK elbowSubtract()
{
	elbow = (elbow - 5) % 360;
}

void CALLBACK shoulderAdd()
{
	shoulder = (shoulder + 5) % 360;
}

void CALLBACK shoulderSubtract()
{
	shouldermij = (shouldermij - 5) % 360;
}

void CALLBACK elbowRot()
{
	elbowmij = (elbowmij + 5) % 360;
	
}

void CALLBACK shoulderRot()
{
	shoulder = (shoulder + 5) % 360;
	
}

void CALLBACK display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);

	glColor3f(1.0, 1.0, 1.0);

	
	glTranslatef(-lungimeBrat / 2, 0.0, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glTranslatef(lungimeBrat / 2, 0.0, 0.0);
	auxWireBox(lungimeBrat, 0.4, 1.0);

	glTranslatef(lungimeBrat / 2, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(lungimeAntebrat / 2, 0.0, 0.0);
	auxWireBox(lungimeAntebrat, 0.4, 1.0);

	glTranslatef(-lungimeBrat / 2, 0.0, 0.0);
	glRotatef((GLfloat)shouldermij, 1.0, 0.0, 0.0);
	glTranslatef(lungimeBrat / 2, 0.0, 0.0);
	auxWireBox(lungimeBrat, 0.4, 1.0);

	glTranslatef(lungimeBrat / 2, 0.0, 0.0);
	glRotatef((GLfloat)elbowmij, 1.0, 0.0, 0.0);
	glTranslatef(lungimeAntebrat / 2, 0.0, 0.0);
	auxWireBox(lungimeAntebrat, 0.4, 1.0);



	glFlush();
}

void myInit()
{
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
	auxInitPosition(0, 0, 800, 600);
	auxInitWindow("Composite Modeling Transformations");
	myInit();
	auxKeyFunc(AUX_LEFT, shoulderSubtract);
	auxKeyFunc(AUX_RIGHT, shoulderAdd);
	auxKeyFunc(AUX_UP, elbowAdd);
	auxKeyFunc(AUX_DOWN, elbowSubtract);
	auxKeyFunc(AUX_A, shoulderRot);
	auxKeyFunc(AUX_B, elbowRot);
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return 0;
}
