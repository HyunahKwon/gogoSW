/* ����Ʈ�� ����:n < prime <= 2n �� prime#�� �ּ� 1�� ���� */
#include <iostream>
using namespace std;
#define MAX 123456 * 2 + 1

int main() {
	int n, prime[MAX];
	int cnt = 0;

	// �����佺�׳׽��� ü
	for (int i = 0; i < MAX; i++) {
		if (i == 1) prime[i] = 0;			// 1�� �Ҽ��� �ƴϴ�!
		else
			prime[i] = i;					// �ڱ� �ڽ� �ֱ�
	}
	for (int i = 2; i < MAX; i++) {
		for (int j = 2; j < MAX && i*j < MAX; j++) {
			prime[i*j] = 0;
		}
	}

	// testcase
	while (1) {
		cin >> n;
		int cnt = 0;
		if (n == 0) break;

		// output
		for (int i = n + 1; i <= 2 * n; i++) {
			if (prime[i] != 0) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}