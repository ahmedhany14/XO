#include<iostream>
#include<string>
#include <windows.h>
using namespace std;
char position[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} }, choice;
bool statue = false;
int row, colms, sum = 0;
char player = 'X', choice2;
string p1, p2;
void display() {
	system("cls");
	cout << "      |      |      " << endl;
	cout << position[0][0] << "     | " << position[0][1] << "    | " << position[0][2] << endl;
	cout << "--------------------" << endl;
	cout << "      |      |      " << endl;
	cout << position[1][0] << "     | " << position[1][1] << "    | " << position[1][2] << endl;
	cout << "--------------------" << endl;
	cout << "      |      |      " << endl;
	cout << position[2][0] << "     | " << position[2][1] << "    | " << position[2][2] << endl;
}
void play() {
again:
	if (player == 'X')
		cout << p1 << " : has the turn [ X ] -->";
	if (player == 'O')
		cout << p2 << " : has the turn [ O ] -->";
	for (size_t i = 0;; i++) {
		try {
			cin >> choice;
			if (choice == '1' or choice == '2' or choice == '3' or choice == '4' or choice == '5' or choice == '6' or choice == '7' or choice == '8' or choice == '9')break;
			else throw choice;
		}
		catch (char x) {
			cout << x << " invaled choice try agin  " << endl;
			goto again;
		}
	}
	switch (choice)
	{
	case '1': row = 0; colms = 0; break;
	case '2': row = 0; colms = 1; break;
	case '3': row = 0; colms = 2; break;
	case '4': row = 1; colms = 0; break;
	case '5': row = 1; colms = 1; break;
	case '6': row = 1; colms = 2; break;
	case '7': row = 2; colms = 0; break;
	case '8': row = 2; colms = 1; break;
	case '9': row = 2; colms = 2; break;
	default:
		cout << "invaled choice" << endl;
	}
	if (player == 'X' and position[row][colms] != 'X' and position[row][colms] != 'O') {
		position[row][colms] = 'X';
		sum++;
		player = 'O';
	}
	else if (player == 'O' and position[row][colms] != 'X' and position[row][colms] != 'O') {
		position[row][colms] = 'O';
		sum++;
		player = 'X';
	}
	else {
		cout << "the place is not empty enter again : " << endl;
		play();
	}
}
bool gamestatue() {
	for (int i = 0; i < 3; i++) {
		if ((position[i][0] == position[i][1] and position[i][0] == position[i][2]) or (position[0][i] == position[1][i] and position[0][i] == position[2][i])) {
			return false;
		}
	}
	if (position[0][0] == position[1][1] and position[0][0] == position[2][2]) return false;
	statue = true;
	if (sum == 9) {
		statue = false;
		return false;
	}
	return true;
}
int main() {
	cout << "enter name  for player 1 : "; cin >> p1;
	cout << "enter name  for player 2 : "; cin >> p2;
	cout << p1 << " will start first " << endl;
	while (gamestatue() == true) {
		display();
		play();
		gamestatue();
	}
	if (player == 'O' and statue == true)cout << "Congratulation " << p1 << " win the game" << endl;
	else if (player == 'X' and statue == true)cout << "Congratulation " << p2 << " win the game" << endl;
	else cout << "No one win the game " << endl;
	Sleep(8000);
	system("pause");
}