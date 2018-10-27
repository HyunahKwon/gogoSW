#include <iostream>
using namespace std;

int main() {
	int a, b;
	double answer;

	cin >> a >> b;
	answer = (double)a / (double)b;
	cout << fixed;	// 소수점 고정
	cout.precision(9);	// fixed 안하면 총 9자리... fixed하면 소숫점 아래 9자리
	cout << answer << endl;

	return 0;
}