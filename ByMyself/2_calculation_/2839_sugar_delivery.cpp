/* ��Ȯ�ϰ� Nų�� ���
	������ 3kg, 5kg �� �ִ��� ���� ����
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	int bag = 0;
	cin >> n;

	while (n > 0) {
		if (n == 3 || n == 5) {
			bag++;
			break;
		}
		else if (n == 1 || n == 2 || n == 4) {
			bag = -1;
			break;
		}
		else {
			bag++;
			n = n - 5;
			if (n % 3 == 0) {	// 3�� ���
				bag = bag + (n / 3);
				break;
			}
			else if (n % 5 == 0) {	// 5�� ���
				bag = bag + (n / 5);
				break;
			}
		}
	}
	cout << bag;

	return 0;
}