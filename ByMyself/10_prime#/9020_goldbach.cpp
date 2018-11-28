/* �������� ����: 2���� ū ��� ¦���� �� �Ҽ��� ������ ��Ÿ�� �� �ִ�.
   ������ ��Ƽ��: ¦���� �� �Ҽ��� ������ ��Ÿ���� ǥ�� */
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 10000 + 1

int main() {
	int T, n, prime[MAX];

	// �����佺�׳׽��� ü
	for (int i = 0; i < MAX; i++) {
		if (i == 1) prime[i] = 0;			// 1�� �Ҽ��� �ƴϴ�!
		else
			prime[i] = i;					// �ڱ� �ڽ� �ֱ�
	}
	for (int i = 2; i < MAX; i++) {	
		if (prime[i] != 0) {				// �̹� �Ҽ� �ƴϸ� �ǳʶٱ�
			for (int j = 2; j < MAX && i*j < MAX; j++) {
				prime[i*j] = 0;
			}
		}
	}

	// testcase
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		scanf("%d", &n);
		int min = 0, max = MAX;
		for (int i = 2; i <= n / 2; i++) {		// n�� ¦���ϱ� �ڱ���� �� �ʿ� ����
			if (prime[n - i] != 0) {
				if (prime[n - i] - prime[i] < max - min) {
					min = prime[i];
					max = prime[n - i];
				}
			}
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}