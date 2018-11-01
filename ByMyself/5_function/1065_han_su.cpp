/*n���� �� �ڸ����� ���������� �̷�� ���� ���� ���ϱ�*/
#include <iostream>
using namespace std;

int n, cnt;
void deungcha(int n);

int main() {
	cin >> n;		// n <= 1000
	cnt = 0;

	deungcha(n);

	cout << cnt;
	return 0;
}

void deungcha(int n) {
	if (n == 1000)		// 1000�� ���� �ƴϴϱ� �׳� 999������ ������...
		n = 999;

	for (int j = 1; j <= n; j++) {
		int tmp = j;		// tmp: 1�� �ڸ��� �� ���̾�
		int num[3] = { 10, 10, 10 };	// num: �� ���� �� ����(0: �����ڸ�-�����ڸ�, 1:�����ڸ�-�����ڸ�, 2:õ���ڸ�-�����ڸ�)
		int i = 0;

		// num[0]: �����ڸ�, num[1]: �����ڸ�, num[2]: �����ڸ�
		while (tmp > 0) {
			num[i] = tmp % 10;
			tmp /= 10;
			i++;
		}

		switch(i) {
		case 3:		// �����ڸ����� ������ �� �ڸ��� �� ��
			if ((num[2] - num[1]) == (num[1] - num[0]))
				cnt++;
			break;
		default:		// �����ڸ��� ������ ����, �����ڸ����� ������ ������ ����
			cnt++;
			break;
		}
	}

}