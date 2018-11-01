/*n까지 각 자리수가 등차수열을 이루는 수의 개수 구하기*/
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
	if (n == 1000)		// 1000은 등차 아니니까 그냥 999까지만 구하장...
		n = 999;

	for (int j = 1; j <= n; j++) {
		int tmp = j;		// tmp: 1의 자리가 될 것이야
		int num[3] = { 10, 10, 10 };	// num: 두 수의 차 저장(0: 십의자리-일의자리, 1:백의자리-십의자리, 2:천의자리-백의자리)
		int i = 0;

		// num[0]: 일의자리, num[1]: 십의자리, num[2]: 백의자리
		while (tmp > 0) {
			num[i] = tmp % 10;
			tmp /= 10;
			i++;
		}

		switch(i) {
		case 3:		// 백의자리까지 있으면 각 자리의 차 비교
			if ((num[2] - num[1]) == (num[1] - num[0]))
				cnt++;
			break;
		default:		// 일의자리는 무조건 등차, 십의자리까지 있으면 무조건 등차
			cnt++;
			break;
		}
	}

}