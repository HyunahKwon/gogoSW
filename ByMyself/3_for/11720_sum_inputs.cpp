/* N���� ���� �� */

#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string temp;
	cin >> temp;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += temp[i] - 48;	// 0�� �ƽ�Ű�� �������� 48�̶��
	}
	cout << sum;

	return 0;
}