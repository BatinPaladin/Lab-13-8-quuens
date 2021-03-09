#include <iostream>
using namespace std;
int board[8][8];
void PrintBoard(int board[8][8]) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (board[i][j] == -1) {
				cout << "[Q]";
			}
			else if (board[i][j] > 0) {
				cout << "[*]";
			}
			else {
				cout << "[ ]";
			}
		}
		cout << endl;
	}
}
void SetQueen(int i, int j) {
	for (int x = 0; x < 8; ++x) {
		++board[x][j]; //вертикаль  
		++board[i][x]; //горизонталь
		int y;
		//по диагоналям 
		y = j - i + x;	
		if ((y >= 0) && (y < 8)) {
			++board[x][y];
		}
		y = j + i - x;
		if ((y >= 0) && (y < 8)) {
			++board[x][y];
		}
		board[i][j] = -1; //ставим ферзя
	}
}
void RemoveQueen(int i, int j) {
	for (int x = 0; x < 8; ++x){
		--board[x][j]; // вертикаль
		--board[i][x]; // горизонталь 
		int y; 
		//по диагоналям 
		y = j - i + x;
		if (y >= 0 && y < 8)
			--board[x][y];
		y = j + i - x;
		if (y >= 0 && y < 8)
			--board[x][y];
		board[i][j] = 0; // //ставим ферзя 
	}
}
bool TryQueen(int i) {
	PrintBoard(board);
	cout << endl;
	bool result = false;
	for (int j = 0; j < 8; ++j) {
		if (board[i][j] == 0){
			SetQueen(i, j);
			if (i == 7)
				result = true;
			else if (!(result = TryQueen(i + 1))) {
				RemoveQueen(i, j);
			}
		}
	}
	return result;
}
int main()
{
	system("chcp 1251");
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			board[i][j] = 0;
		}
	}
	cout << endl;
	TryQueen(0);
	PrintBoard(board);
	cout << endl;
	system("pause");
}
