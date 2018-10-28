/* 2007년 1월 1일: 월요일
   2007년 x월 y일: 무슨 요일일까
*/

#include <iostream>
using namespace std;

void outdate(int date) {
	switch (date) {
	case 0:
		cout << "MON";
		break;
	case 1:
		cout << "TUE";
		break;
	case 2:
		cout << "WED";
		break;
	case 3:
		cout << "THU";
		break;
	case 4:
		cout << "FRI";
		break;
	case 5:
		cout << "SAT";
		break;
	case 6:
		cout << "SUN";
		break;
	}
}

int main() {
	int x, y;	// x: month, y:day
	cin >> x >> y;
	int date = y - 1;	// y일 - 초기 1일

	x - 1;	// 다음 달로 계산하기
	for (int i = 1; i < x; i++) {
		if (i == 2) {
			date = date + 28;
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11) {
			date = date + 30;
		}
		else {	//  1, 3, 5, 7, 8, 10, 12월은 31일
			date = date + 31;
		}
	}
	outdate(date % 7);

	return 0;
}