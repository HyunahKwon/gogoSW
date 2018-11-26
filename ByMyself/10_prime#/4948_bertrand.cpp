/* ����Ʈ�� ����:n < prime <= 2n �� prime#�� �ּ� 1�� ���� */
#include <iostream>
using namespace std;
#define MAX 123456 * 2 + 1

int main() {
	int n, prime[MAX];

	while (1) {
		cin >> n;
		int cnt = 0;
		if (n == 0) break;
		for (int i = 0; i <= 2 * n; i++) {
			if (i == 1) prime[i] = 0;			// 1�� �Ҽ��� �ƴϴ�!
			else
				prime[i] = i;					// �ڱ� �ڽ� �ֱ�
		}

		// prime number?
		for (int i = 2; i <= 2 * n; i++) {
			for (int j = 2; j <= 2 * n && i*j < MAX; j++) {
				prime[i*j] = 0;
			}
		}

		// output
		for (int i = n + 1; i <= 2 * n; i++) {
			if (prime[i] != 0)
				cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}