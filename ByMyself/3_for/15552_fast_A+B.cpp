#include <iostream>
using namespace std;

int main() {
	int tc, a, b;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		scanf("%d %d", &a, &b);		// 시간초과 막기위해 scanf, printf 사용
		printf("%d\n", a + b);
	}

	return 0;
}