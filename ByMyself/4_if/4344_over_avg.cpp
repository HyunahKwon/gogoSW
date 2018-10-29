#include <iostream>
#include <vector>
using namespace std;

int main() {
	int c;
	cin >> c;
	vector<int> score;

	for (int j = 0; j < c; j++) {
		int n;
		cin >> n;
		score.clear();
		int temp = 0, sum = 0;
		double avg = 0.0;

		// 각 케이스 평균 구하기
		for (int i = 0; i < n; i++) {
			cin >> temp;
			score.push_back(temp);
			sum += temp;
		}
		avg = (double)sum / (double)n;
		temp = 0;	// 이제는 몇 명이 높은지 저장하는 변수
		
		// 각 케이스에서 평균보다 높은 사람 수
		for (int i = 0; i < n; i++) {
			if (score.at(i) > avg) {
				temp++;
			}
 		}
		
		// 비율 출력
		cout << fixed;	// 소수점 고정
		cout.precision(3);
		cout << (double)temp / (double)n * 100 << "%" << endl;
	}
	return 0;
}