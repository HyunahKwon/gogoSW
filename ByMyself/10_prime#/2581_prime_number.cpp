/* m과 n 사이 소수는 몇 개? */
#include <iostream>
using namespace std;

int main() {
	int m, n, sum = 0, min = 10001;
	cin >> m >> n;
	int ans = n - m + 1;

	while (m <= n) {
		bool prime = true;
		if (m == 1) {
			ans--;							// 1은 소수 아님
			prime = false;
		}
		for (int i = 2; i < m; i++) {		// 소수: 약수로 1과 n만 가짐
			if (m % i == 0) {
				ans--;
				prime = false;
				break;
			}
		}
		if (prime) {
			sum += m;
			if (m < min) min = m;
		}
		m++;
	}

	if (ans == n - m + 1) cout << "-1";
	else cout << sum << endl << min;

	return 0;
}