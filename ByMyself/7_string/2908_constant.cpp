/* �Ųٷ� ���� �� �� �� �� �� ū �� ��� */
#include <iostream>
using namespace std;

int main() {
	int a, b, tempa, tempb;
	int ans;
	cin >> a >> b;

	tempa = a, tempb = b;
	while (tempa > 0) {
		if (tempa % 10 == tempb % 10) {		// 1�� �ڸ� ��
			tempa /= 10;
			tempb /= 10;
		}
		else if (tempa % 10 > tempb % 10) {	// a�� 1�� �ڸ��� �� ũ��
			ans = a;						// a�� ����
			break;
		}
		else if (tempa % 10 < tempb % 10) {	// b�� 1�� �ڸ��� �� ũ��
			ans = b;			// b�� ����
			break;
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << ans % 10;
		ans /= 10;
	}
	
	return 0;
}

