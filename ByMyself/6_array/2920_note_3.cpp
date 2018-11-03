/* 1~8까지 차례로 연주하면 ascending, 8~1까지 차례면 descending, 둘 다 아니면 mixed */
#include <iostream>
using namespace std;

int main() {
	int num, note = 0;		// num: 입력받은 수, note: 저장변수

	for (int i = 0; i < 8; i++) {	// 숫자 8개 입력받기
		cin >> num;
		note = note * 10 + num;		// 하나의 숫자로 만들자
	}

	if (note == 12345678)
		cout << "ascending";
	else if (note == 87654321)
		cout << "descending";
	else
		cout << "mixed";
	
	return 0;
}