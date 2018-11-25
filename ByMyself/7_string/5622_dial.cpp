/*숫자 1을 걸려면 총 2초가 필요, 전화번호는 각 숫자에 해당하는 문자로 입력 받음*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int sum = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		int cnt = str[i] - 65;
		if (cnt >= 0 && cnt < 3)		// A,B,C
			sum = sum + 2 + 1;
		else if (cnt >= 3 && cnt < 6)   // D,E,F
			sum = sum + 3 + 1;
		else if (cnt >= 6 && cnt < 9)	// G,H,I
			sum = sum + 4 + 1;
		else if (cnt >= 9 && cnt < 12)	// J,K,L
			sum = sum + 5 + 1;
		else if (cnt >= 12 && cnt < 15)	// M,N,O
			sum = sum + 6 + 1;
		else if (cnt >= 15 && cnt < 19)	// P,Q,R,S
			sum = sum + 7 + 1;
		else if (cnt >= 19 && cnt < 22)	// T,U,V
			sum = sum + 8 + 1;
		else if (cnt >= 22)				// W,X,Y,Z
			sum = sum + 9 + 1;
	}

	cout << sum;
	return 0;
}