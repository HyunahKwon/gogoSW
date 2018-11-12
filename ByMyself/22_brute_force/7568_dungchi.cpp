/* 덩치 순서 */
#include <iostream>
using namespace std;

int main() {
	int n, info[50][2];	// 몸무게, 키
	int ans[50];		// 덩치 순서

	//input & initialize
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> info[i][0] >> info[i][1];	// x, y
        ans[i] = 1;
	}

	// compare: 몸무게랑 키가 나보다 큰 사람이 있냐?
	for (int j = 0; j < n; j++) {			// j: 나
		for (int i = 0; i < n; i++) {		// i: 남... 나랑 나를 비교해도 등수 변화 없음
			if (info[i][0] > info[j][0] && info[i][1] > info[j][1]) {
				ans[j]++;					// 내 등수는 뒤로 밀림
			}
		}
	}

	// output
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}