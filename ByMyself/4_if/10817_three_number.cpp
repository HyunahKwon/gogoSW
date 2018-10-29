/* 세 정수 중 중간 수 출력 */
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if ((b >= a && a >= c) || (c >= a && a >= b))	    // a가 중간
		cout << a << endl;
	else if ((a >= b && b >= c) || (c >= b && b >= a))	// b가 중간
		cout << b << endl;
	else if ((a >= c && c >= b) || (b >= c && c >= a))	// c가 중간
		cout << c << endl;

	return 0;
}