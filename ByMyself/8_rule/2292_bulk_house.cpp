/* 벌집 만들어서 n은 몇 개의 방을 지나가는지?
	--> 몇 번째에 n이 들어갈까? */
#include <iostream>
using namespace std;

void honey(long n, long min, long cnt) {
	long start = min + 1;
	long finish = 6 * cnt + start - 1;
	cnt++;
	if (n <= finish)
		printf("%ld", cnt);		// cout << cnt;
	else
		honey(n, finish, cnt);
}

int main() {
	long cnt = 1;
	long n;
	scanf("%ld", &n);	// cin >> n;

	if (n == 1)
		cout << "1";
	else
		honey(n, 1, cnt);

	return 0;
}