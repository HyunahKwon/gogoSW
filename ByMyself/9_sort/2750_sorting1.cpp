/* �������� �����غ��� */
#include <iostream>
using namespace std;
#define MAX 1000

int main() {
	int n, arr[MAX], temp;
	for (int i = 0; i < MAX; i++) {
			arr[i] = 1001;		// |n|<=1000 �� ����..�� �ƴ� ���� �ʱ�ȭ 
	}

	// input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//sort
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) {		// �� ������
				temp = arr[i];
				arr[i] = arr[j];	// swap
				arr[j] = temp;
			}
		}
	}

	//output
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}