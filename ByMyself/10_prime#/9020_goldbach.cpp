/* 골드바흐의 추측: 2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다.
   골드바흐 파티션: 짝수를 두 소수의 합으로 나타내는 표현 */
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 10000 + 1

int main() {
	int T, n, prime[MAX];

	// 에라토스테네스의 체
	for (int i = 0; i < MAX; i++) {
		if (i == 1) prime[i] = 0;			// 1은 소수가 아니다!
		else
			prime[i] = i;					// 자기 자신 넣기
	}
	for (int i = 2; i < MAX; i++) {	
		if (prime[i] != 0) {				// 이미 소수 아니면 건너뛰기
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
		for (int i = 2; i <= n / 2; i++) {		// n은 짝수니까 자기까지 할 필요 없음
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