/* A*B*C ����� 0�� �� ��, 1�� �� ��.... 100 <= A, B, C < 1000 */
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int mul = a * b * c;
	int num[9];

	// 999*999*999=9�ڸ�. �� �ڸ� �� ����(1���ڸ� -> 0�� �迭)
	for (int i = 0; i < 9; i++) {
		num[i] = -1;			// �ʱ�ȭ
		if (mul > 0) {
			num[i] = mul % 10;	// �� ������ �ڸ� ����
		}
		mul /= 10;				// ���� �ڸ� �� --> ���� �ڸ� ����
	}

	// 0~9 ���� �� �� �������� ���
	for (int i = 0; i <= 9; i++) {
		int cnt = 0;
		for (int j = 0; j < 9; j++) {
			if (i == num[j]) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}