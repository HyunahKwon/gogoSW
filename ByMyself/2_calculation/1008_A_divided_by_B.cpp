#include <iostream>
using namespace std;

int main() {
	int a, b;
	double answer;

	cin >> a >> b;
	answer = (double)a / (double)b;
	cout << fixed;	// �Ҽ��� ����
	cout.precision(9);	// fixed ���ϸ� �� 9�ڸ�... fixed�ϸ� �Ҽ��� �Ʒ� 9�ڸ�
	cout << answer << endl;

	return 0;
}