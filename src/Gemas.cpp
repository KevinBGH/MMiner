
#include "Gemas.h"
#include "Partida.h"
#include "Tablero.h"

#include <Windows.h>


void Gemas::drawGemas(float x, float y, int c)
{
	switch (c) 
	{
	case 0:
		Partida::mEngine.Render(King::Engine::TEXTURE_GREEN, x, y);
		break;
	case 1:
		Partida::mEngine.Render(King::Engine::TEXTURE_BLUE, x, y);
		break;
	case 2:
		Partida::mEngine.Render(King::Engine::TEXTURE_RED, x, y);
		break;
	case 3:
		Partida::mEngine.Render(King::Engine::TEXTURE_PURPLE, x, y);
		break;
	case 4:
		Partida::mEngine.Render(King::Engine::TEXTURE_YELLOW, x, y);
		break;
	}
}

//Funcion llamada en el update tan pronto salta la bandera moveFlag hasta que termina la animacion
void Gemas::moveGemas(int firstPosX, int firstPosY, int lastPosX, int lastPosY)
{
	//Condicionales para determinar en que direccion debe moverse cada gema
	if (firstPosX != lastPosX)
	{
		if (firstPosX < lastPosX)
		{
			advanceX1 = advanceX1--;
			advanceX2 = advanceX2++;
		}
		else
		{
			advanceX1 = advanceX1++;
			advanceX2 = advanceX2--;
		}
	}
	if (firstPosY != lastPosY)
	{
		if (firstPosY < lastPosY)
		{
			advanceY1 = advanceY1--;
			advanceY2 = advanceY2++;
		}
		else 
		{
			advanceY1 = advanceY1++;
			advanceY2 = advanceY2--;
		}
	}
	
	//Switch para mover la gema NO elegida hacia su nueva posicion
	switch (Tablero::boardC[firstPosY][firstPosX])
	{
	case 0:
		Partida::mEngine.Render(King::Engine::TEXTURE_GREEN, (lastPosX * 45 + 325 + advanceX1), (lastPosY * 45 + 100 + advanceY1));
		Sleep(10);
		break;
	case 1:
		Partida::mEngine.Render(King::Engine::TEXTURE_BLUE, (lastPosX * 45 + 325 + advanceX1), (lastPosY * 45 + 100 + advanceY1));
		Sleep(10);
		break;
	case 2:
		Partida::mEngine.Render(King::Engine::TEXTURE_RED, (lastPosX * 45 + 325 + advanceX1), (lastPosY * 45 + 100 + advanceY1));
		Sleep(10);
		break;
	case 3:
		Partida::mEngine.Render(King::Engine::TEXTURE_PURPLE, (lastPosX * 45 + 325 + advanceX1), (lastPosY * 45 + 100 + advanceY1));
		Sleep(10);
		break;
	case 4:
		Partida::mEngine.Render(King::Engine::TEXTURE_YELLOW, (lastPosX * 45 + 325 + advanceX1), (lastPosY * 45 + 100 + advanceY1));
		Sleep(10);
		break;
	}

	//Switch para mover la gema elegida hacia su nueva posicion
	switch (Tablero::boardC[lastPosY][lastPosX])
	{
	case 0:
		Partida::mEngine.Render(King::Engine::TEXTURE_GREEN, (firstPosX * 45 + 325 + advanceX2), (firstPosY * 45 + 100 + advanceY2));
		Sleep(10);
		break;
	case 1:
		Partida::mEngine.Render(King::Engine::TEXTURE_BLUE, (firstPosX * 45 + 325 + advanceX2), (firstPosY * 45 + 100 + advanceY2));
		Sleep(10);
		break;
	case 2:
		Partida::mEngine.Render(King::Engine::TEXTURE_RED, (firstPosX * 45 + 325 + advanceX2), (firstPosY * 45 + 100 + advanceY2));
		Sleep(10);
		break;
	case 3:
		Partida::mEngine.Render(King::Engine::TEXTURE_PURPLE, (firstPosX * 45 + 325 + advanceX2), (firstPosY * 45 + 100 + advanceY2));
		Sleep(10);
		break;
	case 4:
		Partida::mEngine.Render(King::Engine::TEXTURE_YELLOW, (firstPosX * 45 + 325 + advanceX2), (firstPosY * 45 + 100 + advanceY2));
		Sleep(10);
		break;
	}

	//Condicional para reiniciar el moveGema y moveBoard
	if (advanceX1 == 45.0 || advanceX2 == 45.0 || advanceY1 == 45.0 || advanceY2 == 45.0)
	{
		advanceX1 = 0.0;
		advanceY1 = 0.0;
		advanceX2 = 0.0;
		advanceY2 = 0.0;
		Tablero::moveFlag = false;
		Tablero::clickFlag = false;
	}

}
