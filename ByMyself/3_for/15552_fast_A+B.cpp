#include <iostream>
using namespace std;

int main() {
	int tc, a, b;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		scanf("%d %d", &a, &b);		// �ð��ʰ� �������� scanf, printf ���
		printf("%d\n", a + b);
	}

	return 0;
}