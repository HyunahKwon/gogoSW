/* N개의 숫자 합 */

#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string temp;
	cin >> temp;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += temp[i] - 48;	// 0의 아스키는 십진수로 48이라네
	}
	cout << sum;

	return 0;
}