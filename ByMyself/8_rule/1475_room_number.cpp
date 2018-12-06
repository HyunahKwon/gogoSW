#include <iostream>
using namespace std;

int main() {
	int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int n, cnt, max = 0;

	cin >> n;
	if (n == 0)
		arr[0]++;
	else {
		while (n > 0) {				// arr에 필요한 개수 넣기
			int temp = n % 10;
			arr[temp]++;
			n /= 10;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (arr[max] < arr[i]) {
			max = i;			// 가장 많이 나온 숫자
			switch (i) {
			case 6:
				while (arr[9] < arr[6] - 1) {
					arr[9]++;
					arr[6]--;
				}
				break;
			case 9:
				while (arr[6] < arr[9] - 1) {
					arr[6]++;
					arr[9]--;
				}
				break;
			}
		}
		cnt = arr[max];	// 필요한 세트의 개수
	}

	cout << cnt;

	return 0;
}