/*
 * Leg3DDrawWindow.cpp
 *
 *  Created on: 2 янв. 2018 г.
 *      Author: vadim
 */

#include "Leg3DDrawWindow.h"
#include "LegsMgr.h"
#include "core/Utils.h"
#include <cmath>
#include "GL/gl.h"
#include "GL/glu.h"
#include <GL/glut.h>

int Leg3DDrawWindow::buttonPressedType = -1;
int Leg3DDrawWindow::buttonPressedX = 0, Leg3DDrawWindow::buttonPressedY = 0;
int Leg3DDrawWindow::lastCursorX = 0, Leg3DDrawWindow::lastCursorY = 0;
bool Leg3DDrawWindow::buttonLeftPressed = false;

// координаты вектора направления движения камеры
float Leg3DDrawWindow::cameraFromX = 0.0f, Leg3DDrawWindow::cameraFromY = 0.0f, Leg3DDrawWindow::cameraFromZ = 0.0f;
float Leg3DDrawWindow::cameraToX = 0.0f, Leg3DDrawWindow::cameraToY = 0.0f, Leg3DDrawWindow::cameraToZ = 0.0f;
float Leg3DDrawWindow::deltaAngle = 1.0f;
int Leg3DDrawWindow::cameraAngleAroundY = 90;
int Leg3DDrawWindow::firstLegAngleZX = 0;

int Leg3DDrawWindow::solveForX = 0;
int Leg3DDrawWindow::solveForY = 0;
int Leg3DDrawWindow::solveForZ = 0;

Leg3DDrawWindow * Leg3DDrawWindow::lpThis = nullptr;

Leg3DDrawWindow::Leg3DDrawWindow()
{
	Leg3DDrawWindow::lpThis = this;
	m_mainLoop = std::thread( [this](){ this->run(); });
}

Leg3DDrawWindow::~Leg3DDrawWindow()
{
	glutDisplayFunc( emptyRenderScene );
	glutReshapeFunc( nullptr );
	glutIdleFunc( nullptr );
	glutDestroyWindow( m_windowId );
	m_drawLegs.clear();
	m_mainLoop.join();
}

void Leg3DDrawWindow::run()
{
	// инициализация GLUT и создание окна
	int argc = 0;
	char argv[256] = {"path" };
	glutInit( &argc, (char**)&argv );
	glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA );
	glutInitWindowPosition( 100, 100 );
	glutInitWindowSize( 300, 300 );
	m_windowId = glutCreateWindow("ManipulatorPlane");

	// регистрация
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(myGlutIdle);

	glutIgnoreKeyRepeat( 1 );
	glutKeyboardFunc( processNormalKeys );
	glutSpecialFunc( pressKey );
	glutSpecialUpFunc( releaseKey );

	// регистрируем две новые функции
	glutMouseFunc( mouseButton );
	glutMotionFunc( mouseMove );

	// OpenGL - инициализация функции теста
	glEnable( GL_DEPTH_TEST );

	init();

	// главный цикл
	glutMainLoop();
}

void Leg3DDrawWindow::myGlutIdle()
{
	glutPostRedisplay();
}

void Leg3DDrawWindow::changeSize(int w, int h)
{
	// предотвращение деления на ноль
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	// используем матрицу проекции
	glMatrixMode(GL_PROJECTION);
	// обнуляем матрицу
	glLoadIdentity();
	// установить параметры вьюпорта
	glViewport(0, 0, w, h);
	// установить корректную перспективу
	gluPerspective(45.0f, ratio, 0.1f, 2000.0f);
	// вернуться к матрице проекции
//	glMatrixMode(GL_MODELVIEW);
}

GLfloat n[6][3] = {  /* Normals for the 6 faces of a cube. */
  {-1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},
  {0.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, -1.0} };
GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
  {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
  {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} };
GLfloat v[8][3];  /* Will be filled in with X,Y,Z vertexes. */

int rotateAngles[3] = { 0, 45, 90 };

int rotateAngleZ = 0;

GLfloat light_diffuse_1[] = {1.0, 0.0, 0.0, 1.0};  /* Red diffuse light. */
GLfloat light_position_1[] = {1.0, 1.0, 1, 0.0};  /* Infinite light location. */

GLfloat light_diffuse_2[] = {1.0, 1.0, 1.0, 1.0};  /* Green diffuse light. */
GLfloat light_position_2[] = {-2.0, -2.0, -3.0, 0.0};  /* Infinite light location. */

GLfloat light_diffuse_3[] = { 0.0, 1.0, 0.0, 1.0 };  /* White diffuse light. */
GLfloat light_position_3[] = {-70.0, -2.0, -3.0, 0.0};  /* Infinite light location. */

void Leg3DDrawWindow::init(void)
{
  /* Setup cube vertex data. */
  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -1;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = 1;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -1;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = 1;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = 1;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = -1;

  //  /* Enable a single OpenGL light. */
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse_1);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position_1);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse_2);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position_2);

    glLightfv( GL_LIGHT2, GL_DIFFUSE, light_diffuse_3 );
    glLightfv( GL_LIGHT2, GL_POSITION, light_position_3 );

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHTING);

  /* Use depth buffering for hidden surface elimination. */
//  glEnable(GL_DEPTH_TEST);

  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION);
//  gluPerspective( /* field of view in degree */ 40.0,
//    /* aspect ratio */ 1.0,
//    /* Z near */ 1.0, /* Z far */ 10.0);
  glMatrixMode(GL_MODELVIEW);
  // обнулить трансформацию
  glLoadIdentity();
  // установить камеру
//  gluLookAt(1.0, 0.0, 5.0,  /* eye is at (0,0,5) */
//    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
//    0.0, 1.0, 0.0);      /* up is in positive Y direction */

  glDepthRange( -200, 200 );

//  /* Adjust cube position to be asthetic angle. */
//  glTranslatef(0.0, 0.0, -1.0);
//  glRotatef(60, 1.0, 0.0, 0.0);
//  glRotatef(-20, 0.0, 0.0, 1.0);
}
void Leg3DDrawWindow::emptyRenderScene(void){}
void Leg3DDrawWindow::renderScene(void)
{
	TypePrecision initialPosX, initialPosY, initialPosZ;
	lpThis->m_drawLegs[0]->getLeg()->getInitialPosition( initialPosX, initialPosY, initialPosZ );

	//очистить буфер цвета и глубины
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// обнулить трансформацию
//	glLoadIdentity();
	glPushMatrix();
	// установить камеру
	gluLookAt( initialPosX + std::cos( Utils::deg2Rad( cameraAngleAroundY ) ) * ( 200.0 + cameraToX ), 450.0 + cameraToY, std::sin( Utils::deg2Rad( cameraAngleAroundY ) ) * ( 100.0 ),  /* eye is at (0,0,5) */
			initialPosX + 1.0 + cameraFromX, 5.0 + cameraFromY, 0.0 + cameraFromZ,      /* center is at (0,0,0) */
	    0.0, 1.0, 0.0);      /* up is in positive Y direction */

  /* Use depth buffering for hidden surface elimination. */
  glEnable(GL_DEPTH_TEST);

	// нарисуем "землю"
	glColor3f(0.9f, 0.9f, 0.9f);
	// полигон (plaine)
	glBegin(GL_QUADS);
		glVertex3f( initialPosX + -50.0f, 0.0f, -50.0f);
		glVertex3f( initialPosX + -50.0f, 0.0f,  50.0f);
		glVertex3f( initialPosX +  50.0f, 0.0f,  50.0f);
		glVertex3f( initialPosX +  50.0f, 0.0f, -50.0f);
	glEnd();

	for( const auto & drawLeg : lpThis->m_drawLegs )
	{
//		glColor3f( 0.1, 0.4, 0.9 );
		drawLeg->render();
	}
		glPushMatrix();
		glColor3f(0.2f, 0.2f, 0.9f);
			glTranslatef( solveForX, solveForY, solveForZ );
			glutSolidSphere( 20, 32, 32 );
		glPopMatrix();
	glPopMatrix();

	glutPostRedisplay();

	glutSwapBuffers();
}

void Leg3DDrawWindow::processNormalKeys(unsigned char key, int xx, int yy)
{
	if (key == 27)
		  exit(0);
}

void Leg3DDrawWindow::pressKey(int key, int xx, int yy)
{

}

void Leg3DDrawWindow::releaseKey(int key, int x, int y)
{
//	switch( key )
//	{
//		case GLUT_KEY_UP :
//		case GLUT_KEY_DOWN : deltaMove = 0;break;
//	}			glutPostRedisplay();
}

void Leg3DDrawWindow::mouseMove( int x, int y )
{
	if( false == buttonLeftPressed )
	{
		return;
	}
	if( GLUT_LEFT_BUTTON == buttonPressedType )
	{
		cameraFromX += ( lastCursorX - x ) * 0.3;
		cameraFromY += ( y - lastCursorY ) * 0.3;
	}
	else if( GLUT_RIGHT_BUTTON == buttonPressedType )
	{
		cameraToX += ( lastCursorX - x ) * 0.3;
		cameraToY += ( y - lastCursorY ) * 0.3;
	}
	else if( GLUT_MIDDLE_BUTTON == buttonPressedType )
	{
		cameraFromZ += ( lastCursorY - y ) * 0.3;
		cameraAngleAroundY += ( lastCursorX - x ) * 1.0;
	}

	lastCursorX = x;
	lastCursorY = y;

	glutPostRedisplay();
}

void Leg3DDrawWindow::mouseButton(int button, int state, int x, int y)
{
	buttonPressedType = button;
	// only start motion if the left button is pressed
	// when the button is released
	if (state == GLUT_UP)
	{
		buttonLeftPressed = false;
	}
	else
	{// state = GLUT_DOWN
		buttonLeftPressed = true;
		buttonPressedX = x;
		buttonPressedY = y;
		lastCursorX = x;
		lastCursorY = y;
	}
}

void Leg3DDrawWindow::updateDrawLegs( Legs legs )
{
	m_drawLegs.clear();
	for( const auto & leg : legs )
	{
		m_drawLegs.emplace_back( std::make_shared<DrawGL3DLeg>( leg ) );
	}
}
