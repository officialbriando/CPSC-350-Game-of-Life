#include <iostream>
#include <fstream> //File input and output
#include <cstdlib> //Random method
#include <string>  //String class 
#include <unistd.h> //Sleep function
#include "Board.h"

using namespace std;

int main()
{
	Board board;
	int row, col;
	string file;
	board.prepGame(file, row, col);

	return 0;
}
