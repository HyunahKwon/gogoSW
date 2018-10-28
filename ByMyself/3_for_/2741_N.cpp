#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		//cout << i << endl; --> 시간초과
		printf("%d\n", i);
	}

	return 0;
}