/* ��Ȯ�ϰ� Nų�� ���
	������ 3kg, 5kg �� �ִ��� ���� ����

�׽�Ʈ
3: 1
4: -1
5: 1
6: 2
7: -1
8: 2
9: 3
10: 2
11: 3
12: 4
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	int bag = -1;
	cin >> n;

	for (int i = n / 5 * 5; i >= 0; i -= 5) {
		if ((n - i) % 5 == 0) {					// 5�� ���
			bag = i / 5;
			break;
		}
		else if ((n - i) % 3 == 0) {			// 3�� ���
			bag = (n - i) / 3 + i / 5;
			break;
		}

	}
	cout << bag;
	return 0;
}