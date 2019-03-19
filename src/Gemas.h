#pragma once


class Gemas 
{

public:
	void drawGemas(float x, float y, int c);
	void moveGemas(int firstPosX, int firstPosY, int lastPosX, int lastPosY);	//pasar las 4 posiciones (firstPos y lastPos), los colores podes sacarlos del boardC con esas direcciones

	float advanceX1 = 0.0;
	float advanceY1 = 0.0;
	float advanceX2 = 0.0;
	float advanceY2 = 0.0;

};
