/* 40�� �̻� = �״��, 40�� �̸�: ������� ������ 40��(������) --> �������? */
#include <iostream>
using namespace std;

int main() {
	int score[5], sum = 0;		// ����, ����, ���, ��, ����

	for (int i = 0; i < 5; i++) {
		cin >> score[i];
		if (score[i] < 40) score[i] = 40;	// 40��+�������
		sum += score[i];
	}
	cout << sum / 5;

	return 0;
}