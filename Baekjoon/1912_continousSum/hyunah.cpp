#include <iostream>
using namespace std;

int max(int a, int b){
	if (a < b)
		return b;
	else
		return a;
}

int main(){
	int n, sum, res;   // temp=max val
	int arr[100001] = {}; // n(1≤n≤100,000)

	cin >> n;  // 들어올 수의 개수
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	sum = arr[0], res = arr[0];
	for (int i = 0; i < n - 1; i++){
		sum = sum + arr[i+1];
		if (sum < arr[i+1]){
			sum = arr[i+1];
		}
		res = max(sum, res);
		//cout << i + 1 << "번째 sum: " << sum << ", max: " << res << endl;
	}
	cout << res;
	
	return 0;
}