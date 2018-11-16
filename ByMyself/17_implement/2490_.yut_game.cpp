/* 배(0), 등(1) 윷짝의 결과는?
 도(배 한 개, 등 세 개), 개(배 두 개, 등 두 개), 걸(배 세 개, 등 한 개), 윷(배 네 개), 모(등 네 개) */
#include <iostream>
using namespace std;

int main() {
	int a;

	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			cin >> a;
			if (a == 0)
				cnt++;
		}
		switch (cnt) {
		case 1:
			cout << "A" << endl;	// 도
			break;
		case 2:
			cout << "B" << endl;	// 개
			break;
		case 3:
			cout << "C" << endl;	// 걸
			break;
		case 4:
			cout << "D" << endl;	// 윷
			break;
		default:
			cout << "E" << endl;	// 모 
			break;
		}
	}
	return 0;
}