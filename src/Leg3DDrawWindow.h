/*
 * Leg3DDrawWindow.h
 *
 *  Created on: 2 янв. 2018 г.
 *      Author: vadim
 */

#ifndef LEG3DDRAWWINDOW_H_
#define LEG3DDRAWWINDOW_H_

#include "DrawGL3DLeg.h"
#include <thread>
#include <mutex>

class Leg3DDrawWindow {
public:
	Leg3DDrawWindow();
	virtual ~Leg3DDrawWindow();

	void run();
	void stop();

	void updateDrawLegs( Legs legs );

	static int solveForX;
	static int solveForY;
	static int solveForZ;
private:
	static void changeSize(int w, int h);
	static void renderScene(void);
	static void emptyRenderScene(void);
	static void processNormalKeys(unsigned char key, int xx, int yy);
	static void pressKey(int key, int xx, int yy);
	static void releaseKey(int key, int x, int y);
	static void mouseMove(int x, int y);
	static void mouseButton(int button, int state, int x, int y);
	static void init(void);
	static void myGlutIdle();
	static void initLegs();

	static int buttonPressedType;
	static int buttonPressedX, buttonPressedY;
	static int lastCursorX, lastCursorY;
	static bool buttonLeftPressed;

	// координаты вектора направления движения камеры
	static float cameraFromX, cameraFromY, cameraFromZ;
	static float cameraToX, cameraToY, cameraToZ;
	static float deltaAngle;
	static int cameraAngleAroundY;
	static int firstLegAngleZX;

	std::thread m_mainLoop;

	DrawGL3DLegs m_drawLegs;

	static Leg3DDrawWindow * lpThis;
	int m_windowId{0};

	std::mutex mContextMutex;
};

#endif /* LEG3DDRAWWINDOW_H_ */
