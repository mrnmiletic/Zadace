#include <iostream>
#include "GameOfLife.h"
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
	srand((unsigned)time(0));
	GameOfLife life;
	life.updateMatrix();


	while(true)
	{
		cout << endl << "run life iteration? 1/0 (10 for loop): " << endl;
		int input;
		cin >> input;
		switch (input)
		{
		case 1: life.updateMatrix(); life.drawMatrix(); break;
		case 0: return 0;
		case 10: while (true) { life.updateMatrix(); life.drawMatrix(); Sleep(100); }
		}
	} 
		return 0;
	}
