#include <iostream>
#include <fstream> //File input and output
#include <cstdlib> //Random method
#include <string>  //String class 

using namespace std;

void getDimensions(int rows, int columns);
void setDimensions(int& rows, int& columns);

void initializeBoard(int rows, int columns, double density, char** board);
void createBoard(string file, int *board);

void nextBoard(int j, int k, int *board);
void printBoard(int j, int k, int** board);#include <iostream>
#include <fstream> //File input and output
#include <cstdlib> //Random method
#include <string>  //String class 

using namespace std;

void getDimensions(int rows, int columns);
void setDimensions(int& rows, int& columns);

void initializeBoard(int rows, int columns, double density, char** board);
void createMappedBoard(string file, int& rows, int& columns);

void nextBoard(int j, int k, int** board);
void printBoard(int j, int k, int** board);
		
int main()
{
	int rowG, colG;
	string file;
	setDimensions(rowG, colG);
	char** GoL = new char*[rowG];
	for(int i = 0; i < rowG; ++i) GoL[i] = new int[colG];

	initializeBoard(rowG, colG, 0.5, GoL);
	printBoard(rowG, colG, GoL);

	return 0;
}

void getDimensions(int rows, int columns) //Returns the rows and columns for the board.
{
	cout << "Rows: " << rows << endl
		<< "Columns: " << columns << endl;	
}

void setDimensions(int& rows, int& columns) //Sets the rows and columns for the board.
{
	cout << "Enter the amount of rows: ";
	cin >> rows;

	cout << "Enter the amount of columns: ";
	cin >> columns;
}

void initializeBoard(int rows, int columns, double density, char** board) //Initializes the board with the set population density. 
{
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < columns; ++j)
		{
			double a = (double)rand()/(RAND_MAX);
			if(a <= density)
			{
				board[i][j] = 'x';
			}
			else
			{
				board[i][j] = '-';
			}
		}
	}
}

void createMappedBoard(string file, int& rows, int& columns)
{

	ifstream inputStream;
	inputStream.open(file.c_str());

	ifstream >> rows >> columns;
}

void initializeMappedBoard(string file, char** board)
{
	int x, y;
	char text;

	int row = 0;

	ifstream inputStream;
	inputStream.open(file.c_str());

	ifstream >> x >> y;

	while(ifstream >> text)
	{
		for(int i = 0; i < x; ++i)
		{
			board[row][i] = text[i];
		}

		row++;
	}
}

void printBoard(int rows, int columns, char** board){
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < columns; ++j)
		{
			cout << board[i][j];			
		}

		cout << endl;
	}
}
		
int main()
{
	int rowG, colG;
	string file;
	setDimensions(rowG, colG);
	char** GoL = new char*[rowG];
	for(int i = 0; i < rowG; ++i) GoL[i] = new int[colG];
		
	initializeBoard(rowG, colG, 0.5, GoL);
	printBoard(rowG, colG, GoL);

	return 0;
}

void getDimensions(int rows, int columns) //Returns the rows and columns for the board.
{
	cout << "Rows: " << rows << endl
		<< "Columns: " << columns << endl;	
}

void setDimensions(int& rows, int& columns) //Sets the rows and columns for the board.
{
	cout << "Enter the amount of rows: ";
	cin >> rows;

	cout << "Enter the amount of columns: ";
	cin >> columns;
}

void initializeBoard(int rows, int columns, double density, char** board) //Initializes the board with the set population density. 
{
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < columns; ++j)
		{
			double a = (double)rand()/(RAND_MAX);
			if(a <= density)
			{
				board[i][j] = 'x';
			}
			else
			{
				board[i][j] = ' ';
			}
		}
	}
}

void printBoard(int rows, int columns, char** board){
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < columns; ++j)
		{
			cout << board[i][j];			
		}

		cout << endl;
	}
}
