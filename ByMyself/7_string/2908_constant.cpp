/* 거꾸로 했을 때 두 수 중 더 큰 수 출력 */
#include <iostream>
using namespace std;

int main() {
	int a, b, tempa, tempb;
	int ans;
	cin >> a >> b;

	tempa = a, tempb = b;
	while (tempa > 0) {
		if (tempa % 10 == tempb % 10) {		// 1의 자리 비교
			tempa /= 10;
			tempb /= 10;
		}
		else if (tempa % 10 > tempb % 10) {	// a의 1의 자리가 더 크면
			ans = a;						// a가 정답
			break;
		}
		else if (tempa % 10 < tempb % 10) {	// b의 1의 자리가 더 크면
			ans = b;			// b가 정답
			break;
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << ans % 10;
		ans /= 10;
	}
	
	return 0;
}

