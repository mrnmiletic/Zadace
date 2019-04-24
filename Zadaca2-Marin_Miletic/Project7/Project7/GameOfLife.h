#pragma once
#include <array>
#define COLUMN 40
#define ROW 50

using namespace std;
class GameOfLife
{
private:
	void GenerateCells(float perc);
	array<array<int, COLUMN>, ROW> matrix;
	bool cellLifeStart(float probability);
public:
	void updateMatrix();
	void drawMatrix();
	GameOfLife();
	
	~GameOfLife();
};

