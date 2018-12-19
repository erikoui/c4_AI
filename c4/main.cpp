#include <iostream>

using namespace std;
int board[7][6];

#define yellow 1
#define blue 2

// 00 10 20 30 40 50 60
// 01 11 21 31 41 51 61
// 02 12 22 32 42 52 62
// 03 13 23 33 43 53 63
// 04 14 24 34 44 54 64
// 05 15 25 35 45 55 65

//eriks globals
bool isEmpty = false;

//test

//andreas globals
bool isNigga = true;


void assert(bool cond, const char* message) {
	if (!cond) {
		cout << message;
		system("pause");
		exit(1);
	}
}

void initBoard() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 6; j++) {
			board[i][j] = 0;
		}
	}
}

void printBoard() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			cout << board[j][i] << " ";
		}
		cout << endl;
	}
	cout << "-----------------------------------------" << endl;
}

int someoneWon() {
	int rowCount = 1;
	int colCount = 1;
	int diagCount = 0;

	for (int i = 0; i < 7; i++) {
		for (int j = 1; j < 6; j++) {
			if (board[i][j] != 0) {
				if (board[i][j] == board[i][j - 1]) {
					colCount++;
				}
				else {
					colCount = 1;
				}
				if (colCount == 4) {
					return board[i][j];
				}
			}
			else {
				colCount = 1;
			}
		}
	}

	for (int j = 1; j < 6; j++) {
		for (int i = 0; i < 7; i++) {
			if (board[i][j] != 0) {
				if (board[i][j] == board[i-1][j]) {
					rowCount++;
				}
				else {
					rowCount = 1;
				}
				if (rowCount == 4) {
					return board[i][j];
				}
			}
			else {
				colCount = 1;
			}
		}
	}

	//TODO: Diagonal
	return 0;
}

void placeColor(int colorCode, int columnNo) {
	assert(board[columnNo][0] == 0, "Attempt to drop thing into full column");
	for (int j = 5; j >= 0; j--) {
		if ((board[columnNo][j]) == 0) {
			board[columnNo][j] = colorCode;
			break;
		} 
	}
}

void eriksFunc(int colorCode) {
	//do stuff
	if (isEmpty) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] != 0) {
					isEmpty = false;
					break;
				}
			}
		}
		if (isEmpty) {
			placeColor(colorCode, 3);//put in middle
		}
	}
}

int main() {
	initBoard();
	printBoard();
	placeColor(1, 3);
	placeColor(2, 3);
	placeColor(1, 4);
	placeColor(1, 5);
	placeColor(2, 6);
	placeColor(2, 6);
	placeColor(2, 6);
	placeColor(2, 6);
	printBoard();
	cout << someoneWon();
	system("pause");
}