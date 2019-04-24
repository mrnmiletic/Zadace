#include "GameOfLife.h"
#include <iostream>

using namespace std;


GameOfLife::GameOfLife()
{
	GenerateCells(0.25); //randomly generates cells
}


bool GameOfLife::cellLifeStart(float probability)
{
		return rand() % 100 < (probability * 100);				//Returns true by entered probability
}

void GameOfLife::updateMatrix()  //checks for current status of each cell and performs cell life decision
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			int count = 0;

			//checks for top left corner
			if (i == 0 && j == 0)
			{
				if (matrix[i + 1][j])
				{
					count++;
				}
				if (matrix[i + 1][j+1])
				{
					count++;
				}
				if (matrix[i][j+1])
				{
					count++;
				}
			}
			//checks for top right corner
			if (i == ROW && j == 0)
			{
				if (matrix[i - 1][j])
				{
					count++;
				}
				if (matrix[i - 1][j + 1])
				{
					count++;
				}
				if (matrix[i][j + 1])
				{
					count++;
				}
			}
			//checks for bottom right corner
			if (i == ROW && j == COLUMN)
			{
				if (matrix[i -1][j])
				{
					count++;
				}
				if (matrix[i - 1][j - 1])
				{
					count++;
				}
				if (matrix[i][j - 1])
				{
					count++;
				}
			}

			//checks for bottom left corner
			if (i == 0 && j == COLUMN)
			{
				if (matrix[i + 1][j])
				{
					count++;
				}
				if (matrix[i + 1][j - 1])
				{
					count++;
				}
				if (matrix[i][j - 1])
				{
					count++;
				}
			}


			//Checks for top cells
			if (i >= 1 && j == 0 && i < ROW-1)
			{
				if (matrix[i + 1][j])
				{
					count++;
				}
				if (matrix[i + 1][j + 1])
				{
					count++;
				}
				if (matrix[i - 1][j])
				{
					count++;
				}
				if (matrix[i - 1][j + 1])
				{
					count++;
				}
				if (matrix[i][j + 1])
				{
					count++;
				}
			}

			//Checks for bottom cells
			if (j == COLUMN && i >= 1 && i < ROW - 1)
			{
				if(matrix[i+1][j])
				{
					count++;
				}
				if (matrix[i+1][j-1])
				{
					count++;
				}
				if (matrix[i-1][j])
				{
					count++;
				}
				if (matrix[i-1][j-1])
				{
					count++;
				}
				if (matrix[i][j-1])
				{
					count++;
				}
			}
			
			//checks for far right
			if (i == ROW && j >= 1 && j < COLUMN - 1)
			{
				if (matrix[i-1][j])
				{
					count++;
				}
				if (matrix[i-1][j-1])
				{
					count++;
				}
				if (matrix[i-1][j+1])
				{
					count++;
				}
				if (matrix[i][j-1])
				{
					count++;
				}
				if (matrix[i][j+1])
				{
					count++;
				}
			}

			//check for far left
			if (i == 0 && j >= 1 && j < COLUMN - 1)
			{
				if (matrix[i+1][j]) {
					count++;
				}
				if (matrix[i+1][j-1]) {
					count++;
				}
				if (matrix[i+1][j+1]) {
					count++;
				}
				if (matrix[i][j-1]) {
					count++;
				}
				if (matrix[i][j+1]) {
					count++;
				}
			}

			//Check for center cells [8 cells around]
		if(i >= 1 && j >= 1 && i < ROW - 1 && j < COLUMN - 1){ 
				if (matrix[i + 1][j])
				{
					count++;
				}
				if (matrix[i + 1][j - 1])
				{
					count++;
				}
				if (matrix[i + 1][j + 1])
				{
					count++;
				}
				if (matrix[i - 1][j])
				{
					count++;
				}
				if (matrix[i - 1][j - 1])
				{
					count++;
				}
				if (matrix[i + 1][j + 1])
				{
					count++;
				}
				if (matrix[i][j - 1])
				{
					count++;
				}
				if (matrix[i][j + 1])
				{
					count++;
				}


				//checks if the cell dies or stays alive
				if (matrix[i][j] && (count < 2 || count > 3))  
				{
					matrix[i][j] = 0;
					break;
				}		

				if (!matrix[i][j] && count == 3)
				{
					matrix[i][j] = 1;
				}
			}
		}
	}
}

void GameOfLife::drawMatrix()
{
	system("cls");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (matrix[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}																//Draws Matrix status
}


void GameOfLife::GenerateCells(float perc)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (cellLifeStart(perc))
			{
				matrix[i][j] = 1;										//Goes trough the matrix and generates live cells based on the probability
			}
			else
			{
				matrix[i][j] = 0;
			}
		}
	}
}


GameOfLife::~GameOfLife()
{
}
