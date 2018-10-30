/* 셀프넘버 출력(생성자가 없는 숫자) (10000보다 작거나 같은) */
#include <iostream>
using namespace std;

#define MAX 10000
int n[10000];
int creator;	// creator: 생성자

void self(int i);
int main() {
	int i = 1;
	// 배열 -1로 초기화
	for (int j = 0; j < 10000; j++)
		n[j] = -1;

	while (i <= 10000) {
		self(i);
		if (n[i - 1] == 0) {
			cout << i << endl;
		}
		i++;
	}
	return 0;
}

void self(int i) {
	if (i / 10 == 0) {		// 한 자리 수(1 ~ 9)
		n[i - 1] = n[i - 1] + 1;	// 생성자 개수++
		self(i + i);
	}
	else if (i / 10 >= 1 && i / 10 <= 9) {	// 두 자리 수(10 ~ 99)
		n[i - 1] = n[i - 1] + 1;
		self(i + (i / 10) + (i % 10));
	}
	else if (i / 10 >= 10 && i / 10 <= 99) {	// 세 자리 수(100 ~ 999)
		n[i - 1] = n[i - 1] + 1;
		self(i + (i / 100) + (i % 100 / 10) + (i % 10));
	}
	else if (i / 10 >= 100 && i / 10 <= 999) {	// 네 자리 수(1000 ~ 9999)
		n[i - 1] = n[i - 1] + 1;
		self(i + (i / 1000) + (i % 1000 / 100) + (i % 100 / 10) + (i % 10));
	}
	else if (i == 10000) {	// 다섯 자리 수(10000)
		n[i - 1] = n[i - 1] + 1;
	}
}