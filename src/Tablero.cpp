
#include "Partida.h"
#include "Tablero.h"
//#include "Gemas.h"

#include <cstdlib>
#include <ctime>

#include <iostream>

int Tablero::boardC[8][8];
bool Tablero::clickFlag = false;
bool Tablero::moveFlag = false;

void Tablero::createBoard() 
{
	//Creacion de tablero aleatorio
	srand(time(0));
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			boardC[j][i] = (0 + (rand() % 4));
		}
	}

	//Chequeo y modificacion
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if ((boardC[j][i] == boardC[j][i + 1]) && (boardC[j][i] == boardC[j][i + 2]))
			{
				boardC[j][i+1] = (0 + (rand() % 4));
			}
		}
	}
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if ((boardC[j][i] == boardC[j + 1][i]) && (boardC[j][i] == boardC[j + 2][i]))
			{
				boardC[j+1][i] = (0 + (rand() % 4));
			}
		}
	}
}

//Llamado a Gemas para dibujar el tablero
void Tablero::drawBoard() 
{
	for (int j = 0; j < 8; j++) 
	{
		for (int i = 0; i < 8; i++)
		{
			//Condicional para no dibujar la gema que movemos al moverla dentro de su area
			if (Partida::mEngine.GetMouseButtonDown())
			{
				int posX = (Partida::mEngine.GetMouseX() - 325.0f) / 45.0f;
				int posY = (Partida::mEngine.GetMouseY() - 100.0f) / 45.0f;

				if (i != posX || j != posY)
				{
					gemas.drawGemas(boardX[i], boardY[j], boardC[j][i]);
				}
			}
			else
			{
				//Condicional para dibujar si no hay click ni animacion
				if (moveFlag == false)
				{
					gemas.drawGemas(boardX[i], boardY[j], boardC[j][i]);
				}
				//Condicional para no dibujar las gemas que se estan animando
				else
				{
					if (i != firstPosX || j != firstPosY)
					{
						if (i != lastPosX || j != lastPosY)
						{
							gemas.drawGemas(boardX[i], boardY[j], boardC[j][i]);
						}
					}
				}
			}
		}
	}
}

//Chequeo sin modificacion
bool Tablero::checkBoard()
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if ((boardC[j][i] == boardC[j][i+1]) && (boardC[j][i] == boardC[j][i+2])) 
			{
				return true;
			}
		}
	}
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if ((boardC[j][i] == boardC[j+1][i]) && (boardC[j][i] == boardC[j+2][i]))
			{
				return true;
			}
		}
	}
	return false;
}

//Cambio de color de gemas
void Tablero::moveBoard(float x, float y)
{
	int posX = (x - 325.0f) / 45.0f;
	int posY = (y - 100.0f) / 45.0f;

	//Juego con 2 banderas para valuar firstPos y lastPos, y llamar a la animacion
	if (clickFlag == false && moveFlag == false)
	{
		firstPosX = posX;
		firstPosY = posY;
		
		std::cout << "entro" << std::endl;
		clickFlag = true;
	}
	if ((firstPosX != posX || firstPosY != posY) && clickFlag == true && moveFlag == false)
	{
		std::cout << posX << posY << firstPosX << firstPosY << std::endl;

		lastPosX = posX;
		lastPosY = posY;

		valC = boardC[lastPosY][lastPosX];
		boardC[posY][posX] = boardC[firstPosY][firstPosX];
		boardC[firstPosY][firstPosX] = valC;
		
		std::cout << "cambio " << boardC[lastPosY][lastPosX] << " por "<< boardC[firstPosY][firstPosX] << std::endl;
		moveFlag = true;
		gemas.advanceX1 = 0.0;
		gemas.advanceY1 = 0.0;
		gemas.advanceX2 = 0.0;
		gemas.advanceY2 = 0.0;
	}
}

