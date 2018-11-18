/* 100이하의 n... 소수는 몇 개? */
#include <iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	int ans = tc;

	while (tc != 0) {
		int n;
		cin >> n;
		if (n == 1) ans--;			// 1은 소수 아님
		for (int i = 2; i < n; i++) {		// 소수: 약수로 1과 n만 가짐
			if (n % i == 0) {
				ans--;
				break;
			}
		}
		tc--;
	}
	cout << ans;
	
	return 0;
}