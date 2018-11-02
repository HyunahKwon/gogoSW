/* A*B*C 결과에 0이 몇 번, 1이 몇 번.... 100 <= A, B, C < 1000 */
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int mul = a * b * c;
	int num[9];

	// 999*999*999=9자리. 각 자리 수 저장(1의자리 -> 0번 배열)
	for (int i = 0; i < 9; i++) {
		num[i] = -1;			// 초기화
		if (mul > 0) {
			num[i] = mul % 10;	// 맨 마지막 자리 저장
		}
		mul /= 10;				// 십의 자리 수 --> 일의 자리 수로
	}

	// 0~9 각각 몇 번 쓰였는지 출력
	for (int i = 0; i <= 9; i++) {
		int cnt = 0;
		for (int j = 0; j < 9; j++) {
			if (i == num[j]) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}