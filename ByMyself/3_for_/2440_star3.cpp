/*
왼쪽정렬 N~1까지 작아지는 별찍기
	예) 5일 경우
		*****
		****
		***
		**
		*
*/
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = N; i > 0; i--) {
		for (int j = 1; j <= i; j++)
			cout << "*";
		cout << endl;
	}

	return 0;
}