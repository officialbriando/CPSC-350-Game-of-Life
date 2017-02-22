#include <string>

using namespace std;

class Board
{
	private:

	public:
		Board();
		~Board();

		void setDimensions(int& rows, int& columns, double& density);
		void setDimensions(string file, int& rows, int& columns);

		void initializeBoard(int rows, int columns, double density, char**& board);
		void initializeBoard(string file, char**& board);

		int nextBoardClassic(int rows, int columns, char**& board);
		int nextBoardTorus(int rows, int columns, char**& board);
		void printBoard(int rows, int columns, char** board);

		void prepGame(string& file, int& rows, int& columns);
		void startGame(int& rows, int& columns, char**& board);
};
