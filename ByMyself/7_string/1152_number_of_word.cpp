/* �ܾ��� ������ �� ���ΰ�. ���� ���޾� �� �� �� ���� */
#include <iostream>
using namespace std;

#define MAX 1000000

int main() {
	char word[MAX + 1] = {};		// initialize
	cin.getline(word, MAX + 1);		// MAX + 1���� ���ڿ��� �Է¹�����

	int i = 1;
	int cnt = 0;

	while (i < MAX + 1) {
		// ���� ���� �����̸� �ܾ� 1��, �� �ڿ� ���� �ְų� ���� �� ����
		if ((word[i - 1] != ' ' && word[i] == ' ') || (word[i - 1] != ' ' && word[i] == NULL)) {
			cnt++;								
		}
		if (word[i] == NULL) {					// null�̸� ��
			break;
		}
		i++;
	}
	cout << cnt;

	return 0;
}