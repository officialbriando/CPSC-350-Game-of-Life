int nextGeneration(int rows, int columns, char**& board) //Creates a new board with adjustments for next generation, then copies it to the primary board.
{
	char** nextGen = new char*[rows]; //Creates a second board based on first board dimensions for copying later.
	for(int i = 0; i < rows; ++i) nextGen[i] = new char[columns];

	//Creating the next generation based on the previous.

	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < columns; ++j){
			int count = 0; //Keeps track of amount of neighbors.

			if(i == 0 && j == 0){ //All checks necessary to avoid IndexOutOfBounds error.
				if(board[i+1][j] == 'X') count++; //Only 3 possible neighbors for corner slots in classic mode.
				if(board[i][j+1] == 'X') count++;
				if(board[i+1][j+1] == 'X') count++;
			}
			else if(i == 0 && j == (columns - 1)){
				if(board[i+1][j] == 'X') count++;
				if(board[i][j-1] == 'X') count++;
				if(board[i+1][j-1] == 'X') count++;
			}
			else if(i == (rows - 1 ) && j == (columns - 1)){
				if(board[i-1][j] == 'X') count++;
				if(board[i][j-1] == 'X') count++;
				if(board[i-1][j-1] == 'X') count++;
			}
			else if(i == (rows - 1) && j == 0){
				if(board[i-1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
				if(board[i-1][j+1] == 'X') count++;
			}
			else if(j == 0){ //Only 5 possible neighbors for side slots in classic mode.
				if(board[i-1][j] == 'X') count++;
				if(board[i+1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
				if(board[i+1][j+1] == 'X') count++;
				if(board[i-1][j+1] == 'X') count++;
			}

			else if(i == 0){
				if(board[i+1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
				if(board[i+1][j+1] == 'X') count++;
				if(board[i][j-1] =='X') count++;
				if(board[i+1][j-1] == 'X') count++;
			}
			else if(j == (columns - 1)){
				if(board[i-1][j] == 'X') count++;
				if(board[i+1][j] == 'X') count++;
				if(board[i][j-1] == 'X') count++;
				if(board[i+1][j-1] == 'X') count++;
				if(board[i-1][j-1] == 'X') count++;
			}
			else if(i == (rows - 1)){
				if(board[i-1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
				if(board[i-1][j+1] == 'X') count++;
				if(board[i][j-1] =='X') count++;
				if(board[i-1][j-1] == 'X') count++;
			}
			else //Eight possible neighbors for any given middle slot.
			{
				if(board[i+1][j] == 'X') count++;
				if(board[i][j+1] == 'X') count++;
				if(board[i+1][j+1] == 'X') count++;
				if(board[i][j-1] =='X') count++;
				if(board[i-1][j] == 'X') count++;
				if(board[i-1][j-1] == 'X') count++;
				if(board[i+1][j-1] =='X') count++;
				if(board[i-1][j+1] == 'X') count++;
			}

			if(count < 2) nextGen[i][j] = '-';
			else if(count == 2) nextGen[i][j] = board[i][j];
			else if(count == 3) nextGen[i][j] = 'X';
			else if(count > 3) nextGen[i][j] = '-';
		}
	}

	//Checking to see if the next generation is the same as the previous, returns '1' if true, '0' if false.
	bool stabilized = true;

	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < columns; ++j){
			if(nextGen[i][j] != board[i][j]) stabilized = false;
		}
	}

	if(stabilized){
		cout << "The world has stabilized. There are no further changes to the population." << endl;
		return 1;
	}
	else{ //Copies the next generation over to the primary board.
		for(int i = 0; i < rows; ++i){
			for(int j = 0; j < columns; ++j)board[i][j] = nextGen[i][j];
		}
		return 0;
	}
}	
