/* 100������ n... �Ҽ��� �� ��? */
#include <iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	int ans = tc;

	while (tc != 0) {
		int n;
		cin >> n;
		if (n == 1) ans--;			// 1�� �Ҽ� �ƴ�
		for (int i = 2; i < n; i++) {		// �Ҽ�: ����� 1�� n�� ����
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