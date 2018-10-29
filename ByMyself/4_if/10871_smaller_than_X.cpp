/* 수열 A에서 X보다 작은 수 모두 출력 */
#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int arr[10000];		// 1 <= n <= 10000
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] < x) {
			cout << arr[i] << " ";
		}
	}
	return 0;
}