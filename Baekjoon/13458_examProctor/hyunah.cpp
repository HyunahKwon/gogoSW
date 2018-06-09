#include <iostream>
using namespace std;

int main(){
	int N, B, C;  // N: 시험장 개수, B: 총감독이 감독가능 수, C: 부감독관 감독가능 수
	long long sum = 0;
	int i;

	cin >> N;

	int *A = new int[N];  // A:응시자

	for (i = 0; i < N; i++)
		cin >> A[i];    // 개수 별 응시자 수 넣기
	cin >> B >> C;

	for (i = 0; i < N; i++){
		sum++;  // 총감독자 1명
		// 부감독관들이 봐야하는 응시자 수 x*C >= A - B
		if (A[i] - B < 0)
			continue;
		else
			sum += ((A[i] - B) % C == 0 ? (A[i] - B) / C : (A[i] - B) / C + 1);		
	}
	cout << sum;

	return 0;
}