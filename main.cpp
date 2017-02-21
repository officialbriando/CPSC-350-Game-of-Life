#include <iostream>
#include <fstream> //File input and output
#include <cstdlib> //Random method
#include <string>  //String class 

using namespace std;

void getDimensions(int rows, int columns);
void setDimensions(int& rows, int& columns);

void initializeBoard(int rows, int columns, double density, char**& board);
void createMappedBoard(string file, int& rows, int& columns);

int nextGeneration(int rows, int columns, char**& board);
void printBoard(int rows, int columns, char** board);
		
int main()
{
	int row, col;
	int next;
	string file;
	int stabilized = 0;

	setDimensions(row, col);

	char** currentGen = new char*[row];
	for(int i = 0; i < row; ++i) 
	{
		currentGen[i] = new char[col];
	}

	initializeBoard(row, col, 0.5, currentGen);
	printBoard(row, col, currentGen);

	cout << "Press enter to start the simulation: " << endl;

	while(stabilized == 0)
	{
		stabilized  = nextGeneration(row, col, currentGen);
		printBoard(row, col, currentGen);

		if(stabilized == 1)
		{
			break;
		}

		cout << "Press enter to see the next generation: " << endl;
		cin.ignore();
	}

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

void initializeBoard(int rows, int columns, double density, char**& board) //Initializes the board with the set population density. 
{
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < columns; ++j)
		{
			double a = (double)rand()/(RAND_MAX);
			if(a <= density)
			{
				board[i][j] = 'X';
			}
			else
			{
				board[i][j] = '-';
			}
		}
	}
}

void createMappedBoard(string file, int& rows, int& columns) //Reads in the first two ints of the mapfile and sets them.
{

	ifstream inputStream;
	inputStream.open(file.c_str());

	inputStream >> rows >> columns;

	inputStream.close();
}

void initializeMappedBoard(string file, char**& board) //Iterates through each line of text and sets each row accordingly.
{
	int x, y;
	string text;

	int row = 0;

	ifstream inputStream;
	inputStream.open(file.c_str());

	inputStream >> x >> y;

	while(inputStream >> text)
	{
		for(int i = 0; i < x; ++i)
		{
			board[row][i] = text[i];
		}

		row++;
	}

	inputStream.close();
}

int nextGeneration(int rows, int columns, char**& board) //Creates a new board with adjustments for next generation, then copies it to the primary board.
{
	char** nextGen = new char*[rows]; //Creates a second board based on first board dimensions for copying later.
	for(int i = 0; i < rows; ++i)
	{
		nextGen[i] = new char[columns];
	}

	//Creating the next generation based on the previous.

	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < columns; ++j)
		{
			int count = 0; //Keeps track of amount of neighbors.

			if(i == 0 && j == 0) //All checks necessary to avoid IndexOutOfBounds error.
			{
				if(board[i+1][j] == 'X') //Only 3 possible neighbors for corner slots in classic mode.
				{
					count++;
				}
				if(board[i][j+1] == 'X')
				{
					count++;
				}
				if(board[i+1][j+1] == 'X')
				{
					count++;
				}
			}
			else if(i == 0 && j == (columns - 1))
			{
				if(board[i+1][j] == 'X')
				{
					count++;
				}
				if(board[i][j-1] == 'X')
				{
					count++;
				}
				if(board[i+1][j-1] == 'X')
				{
					count++;
				}
			}
			else if(i == (rows - 1 ) && j == (columns - 1))
			{
				if(board[i-1][j] == 'X')
				{
					count++;
				}
				if(board[i][j-1] == 'X')
				{
					count++;
				}
				if(board[i-1][j-1] == 'X')
				{
					count++;
				}
			}
			else if(i == (rows - 1) && j == 0)
			{
				if(board[i-1][j] == 'X')
				{
					count++;
				}
				if(board[i][j+1] == 'X')
				{
					count++;
				}
				if(board[i-1][j+1] == 'X')
				{
					count++;
				}
			}
			else if(j == 0) //Only 5 possible neighbors for side slots in classic mode.
			{
				if(board[i-1][j] == 'X')
				{
					count++;
				}
				if(board[i+1][j] == 'X')
				{
					count++;
				}
				if(board[i][j+1] == 'X')
				{
					count++;
				}
				if(board[i+1][j+1] == 'X')
				{
					count++;
				}
				if(board[i-1][j+1] == 'X')
				{
					count++;
				}
			}

			else if(i == 0)
			{
				if(board[i+1][j] == 'X')
				{
					count++;
				}
				if(board[i][j+1] == 'X')
				{
					count++;
				}
				if(board[i+1][j+1] == 'X')
				{
					count++;
				}
				if(board[i][j-1] =='X')
				{
					count++;
				}
				if(board[i+1][j-1] == 'X')
				{
					count++;
				}
			}
			else if(j == (columns - 1))
			{
				if(board[i-1][j] == 'X')
				{
					count++;
				}
				if(board[i+1][j] == 'X')
				{
					count++;
				}
				if(board[i][j-1] == 'X')
				{
					count++;
				}
				if(board[i+1][j-1] == 'X')
				{
					count++;
				}
				if(board[i-1][j-1] == 'X')
				{
					count++;
				}
			}
			else if(i == (rows - 1))
			{
				if(board[i-1][j] == 'X')
				{
					count++;
				}
				if(board[i][j+1] == 'X')
				{
					count++;
				}
				if(board[i-1][j+1] == 'X')
				{
					count++;
				}
				if(board[i][j-1] =='X')
				{
					count++;
				}
				if(board[i-1][j-1] == 'X')
				{
					count++;
				}
			}
			else //Eight possible neighbors for any given middle slot.
			{
				if(board[i+1][j] == 'X')
				{
					count++;
				}
				if(board[i][j+1] == 'X')
				{
					count++;
				}
				if(board[i+1][j+1] == 'X')
				{
					count++;
				}
				if(board[i][j-1] =='X')
				{
					count++;
				}
				if(board[i-1][j] == 'X')
				{
					count++;
				}
				if(board[i-1][j-1] == 'X')
				{
					count++;
				}
				if(board[i+1][j-1] =='X')
				{
					count++;
				}
				if(board[i-1][j+1] == 'X')
				{
					count++;
				}
			}

			if(count < 2) nextGen[i][j] = '-';
			else if(count == 2) nextGen[i][j] = board[i][j];
			else if(count == 3) nextGen[i][j] = 'X';
			else if(count > 3) nextGen[i][j] = '-';
		}
	}

	//Checking to see if the next generation is the same as the previous, returns '1' if true, '0' if false.
	bool stabilized = true;

	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < columns; ++j)
		{
			if(nextGen[i][j] != board[i][j])
			{
				stabilized = false;
			}
		}
	}

	if(stabilized)
	{
		cout << "The world has stabilized. There are no further changes to the population." << endl;
		return 1;
	}
	else //Copies the next generation over to the primary board.
	{
		for(int i = 0; i < rows; ++i)
		{
			for(int j = 0; j < columns; ++j)
			{
				board[i][j] = nextGen[i][j];
			}
		}
		return 0;
	}
}	

void printBoard(int rows, int columns, char** board)
{
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < columns; ++j)
		{
			cout << board[i][j];			
		}

		cout << endl;
	}
}
