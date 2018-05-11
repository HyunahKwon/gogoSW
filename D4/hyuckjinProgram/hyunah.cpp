#include <iostream>
#include <string>
using namespace std;

/* ★미완성ㅠㅠ 디버깅하다가 시간없어서... 떠납니댜... ★ */

char arr[21][21], current_char;
int x = 0, y = 1;
int r, c, num, next = 1;  // r:row, c:column, num: the only integer(0 to 15)

void left(){
	if (y == 0)
		y = c - 1;
	else
		y--;
	return;
}

void right(){
	if (y == c - 1)
		y = 0;
	else
		y++;
	return;
}

void up(){
	if (x == 0)
		x = r - 1;
	else
		x--;
	return;
}

void down(){
	if (x == r - 1)
		x = 0;
	else
		x++;
	return;
}

int execution(char current_char, int num)
{
	switch (current_char){
	case '<':
		current_char = 0; // left();
		break;
	case '>':
		current_char = 1; // right();
		break;
	case '^':
		current_char = 2; // up();
		break;
	case 'v':
		current_char = 3; // down();
		break;
	case '_':
		if (num != 0)
			current_char = 0; // left();
		else
			current_char = 1; // right();
		break;
	case '|':
		if (num != 0)
			current_char = 2; // up();
		else
			current_char = 3; // down();
		break;
	case '?':        ////////////////////////////how to...?
		break;
	case '.':
		return 1;  //nothing to do
	case '@':
		return 0;  //exit --> result = 10
	case '+':
		if (num == 15)
			num = 0;
		else
			num++;
		break;
	case '-':
		if (num == 0)
			num = 15;
		else
			num--;
		break;
	}
	return 1;
}

int main(){
	string str;
	int tc, i, j;
	int result;

	cin >> r >> c;
	for (i = 0; i < r; i++){
		cin >> str;
		for (j = 0; j < str.length(); j++)
			arr[i][j] = str.at(j);
	}
	num = arr[0][0] - '0';

	for (i = 0; i < 100; i++){
		result = execution(arr[x][y], num);
		if (result == 0){
			cout << "YES" << endl;
		}
		else
		{
			switch (current_char){
			case 0:
				left();
				break;
			case 1:
				right();
				break;
			case 2:
				up();
				break;
			case 3:
				down();
				break;
			}
		}
	}

	return 0;
}
