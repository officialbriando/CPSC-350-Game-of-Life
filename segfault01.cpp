#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void setDimensions(int& rows, int& columns);
void createBoard(int rows, int columns, float density, int** board);
void createBoard(string file, int *board);
void nextBoard(int j, int k, int** board);
void printBoard(int j, int k, int** board);
		
int main(){
	int rowG, colG, asdf;
	string file;
	setDimensions(rowG, colG);
	int** GoL = new int*[rowG];
	for(int i = 0; i < rowG; ++i) GoL[i] = new int[colG];
	createBoard(rowG, colG, 0.5, GoL);
	printBoard(rowG, colG, GoL);
	cout << "1";
	nextBoard(rowG, colG, GoL);
	printBoard(rowG, colG, GoL);
}

void setDimensions(int& rows, int& columns){
	cout << "Rows: ";	cin >> rows;
	cout << "Columns: ";	cin >> columns;	
}

void createBoard(int rows, int columns, float density, int** board){
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < columns; ++j){
			float a = (double)rand()/(RAND_MAX);
			if(a <= density) board[i][j] = 1;
			else board[i][j] = 0;
		}
	}
}

void nextBoard(int j, int k, int** board){
	cout << "1";
	int** nextPhase = new int*[j];
	for(int c = 0; c < j; ++c) nextPhase[c] = new int[k];
	for(int row = 0; row < j; ++row){
		for(int col = 0; col < k; ++col){
			int count = 0;
			for(int a = -1; a <= 1; ++a){
				for(int b = -1; b <=1; ++b){
					if(board[row+a][col+b]==1) count++;
				}
			}
			if(count < 2) nextPhase[row][col] = 0;
			else if (count == 2) nextPhase[row][col] = board[row][col];
			else if (count == 3) nextPhase[row][col] = 1;
			else if (count < 3) nextPhase[row][col] = 0;
		}
	}
	
	for(int y = 0; y < j; ++y){
		for(int x = 0; x < k; ++x){
			board[y][x] = nextPhase[y][x];
		}
	}
}

void printBoard(int j, int k, int** board){
	for(int n = 0; n < j; ++n){
		for(int m = 0; m < k; ++m){
			if(board[n][m] == 1) cout << "X";
			else cout << "-";
		}
		cout << endl;
	}
}
