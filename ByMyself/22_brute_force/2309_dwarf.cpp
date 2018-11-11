/* 9���� ������ �� Ű�� ���� 100�� �Ǵ� �ϰ� �������� Ű�� ������������ */
#include <iostream>
using namespace std;

int main() {
	int sum = 0, arr[9];

	// input
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	// sort
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[j] < arr[i]) {		// �� ������
				int temp = arr[i];
				arr[i] = arr[j];	// swap
				arr[j] = temp;
			}
		}
	}

	// sum == 100?
	bool flag = false;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if(sum - arr[i] - arr[j] == 100){
				arr[i] = 0, arr[j] = 0;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	// output
	for (int i = 0; i < 9; i++) {
		if (arr[i] != 0) {
			cout << arr[i] << endl;
		}
	}

	return 0;
}