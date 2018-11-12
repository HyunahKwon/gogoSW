/* 거꾸로 했을 때 두 수 중 더 큰 수 출력 */
#include <iostream>
using namespace std;

int main() {
	int n, info[50][3];	// 몸무게, 키, 덩치 순서
	int weight[50];

	//// initialize
	for (int i = 0; i < 50; i++) {
	//	for (int j = 0; j < 2; j++) {
	//		info[i][j] = 0;
	//	}
		info[i][2] = 50;
	//	weight[i] = -1;
	}

	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> info[i][0] >> info[i][1];	// x, y
	}

	// compare1: 몸무게로 순위 정하기
	for (int j = 1; j <= n; j++) {
		int max = 0, temp = 0;
		for (int i = 0; i < n; i++) {
			if (info[i][0] > max && info[i][2] == 50) {
				max = info[i][0];
				temp = i;
			}
		}
		info[temp][2] = j;
		weight[j - 1] = temp;
	}

	// compare2: 순위로 접근해서 키 비교
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 몸무게는 작지만 키가 크면, 덩치 등수는 같아짐
			if (info[weight[i]][1] < info[j][1] && j != weight[i] && info[j][2] > i) { 
				info[j][2] = info[weight[i]][2];
			}
		}
	}

	// output
	for (int i = 0; i < n; i++) {
		cout << info[i][2] << " ";
	}
	
	return 0;
}

