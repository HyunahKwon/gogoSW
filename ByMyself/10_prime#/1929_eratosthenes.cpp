/* m �̻� n ���� �Ҽ��� �� ��? --> �����佺�׳׽��� ü */
#include <iostream>
using namespace std;
#define MAX 1000000

int main() {
	int m, n, prime[MAX];
	scanf("%d %d", &m, &n);

	for (int i = 0; i <= n; i++) {
		if (i == 1) prime[i] = 0;				// 1�� �Ҽ��� �ƴϴ�!
		else
			prime[i] = i;					// �ڱ� �ڽ� �ֱ�
	}

	// prime number?
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j<=n && i*j < MAX; j++) {
			prime[i*j] = 0;
		}
	}
	
	// output
	for (int i = m; i <= n; i++) {
		if(prime[i] != 0)
			printf("%d\n", prime[i]);
	}

	return 0;
}