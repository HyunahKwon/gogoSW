/* 1~8까지 차례로 연주하면 ascending, 8~1까지 차례면 descending, 둘 다 아니면 mixed */
#include <iostream>
using namespace std;

int arr[8], i;

void asc() {
	bool res = true;
	for (i = 0; i < 8; i++) {
		if (arr[i] != i + 1) {
			res = false;
			break;
		}
	}
	res == true ? cout << "ascending" : cout << "mixed";
}

void des() {
	bool res = true;
	for (i = 0; i < 8; i++) {
		if (arr[7 - i] != i + 1) {
			res = false;
			break;
		}
	}
	res == true ? cout << "descending" : cout << "mixed";
}

int main() {
	for (i = 0; i < 8; i++) {	// 숫자 8개 입력받기
		cin >> arr[i];
	}

	arr[0] == 1 ? asc() : des();
	
	return 0;
}10 <= 999) {	// 네 자리 수(1000 ~ 9999)
		n[i - 1] = n[i - 1] + 1;
		self(i + (i / 1000) + (i % 1000 / 100) + (i % 100 / 10) + (i % 10));
	}
	else if (i == 10000) {	// 다섯 자리 수(10000)
		n[i - 1] = n[i - 1] + 1;
	}
}
*/