/* 1~8까지 차례로 연주하면 ascending, 8~1까지 차례면 descending, 둘 다 아니면 mixed */
#include <iostream>
using namespace std;

int main() {
	int arr[8];
	int asc = 0, des = 0;
	for (int i = 0; i < 8; i++) {	// 숫자 8개 입력받기
		cin >> arr[i];
		if (arr[i] == i + 1)		// 입력받은 숫자가 오름차순?
			asc++;
		else if (arr[i] == 8 - i)	// 입력받은 숫자가 내림차순?
			des++;
	}

	if (asc == 8)
		cout << "ascending";
	else if (des == 8)
		cout << "descending";
	else
		cout << "mixed";
	
	return 0;
}