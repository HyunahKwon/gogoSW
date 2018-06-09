#include<iostream>
using namespace std;

int n, b, c;
int *a;

long long countSuper(int index) {
	int tmp = a[index] - b;
	long long cnt = 0;
	if (tmp <= 0) return 1;
	else {
		cnt = tmp / c;
		if (tmp%c != 0) return cnt + 2;
		else return cnt+1;
	}
}

int main() {
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> b >> c;
	long long sum = 0; //long longø° ¡÷¿«!!
	for (int i = 0; i < n; i++) {
		sum += countSuper(i);
	}
	cout << sum << endl;
}