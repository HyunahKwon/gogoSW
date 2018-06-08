#include<iostream>
using namespace std;

int total = 4;
int wheel[4][8];
int k;
int nd[4];
int score[4] = { 1,2,4,8 };

void change(int num,int d) {
	if (d == 1) { //시계
		int temp = wheel[num][7];
		for (int i = 7; i >0; i--) {
			wheel[num][i] = wheel[num][i - 1];
		}
		wheel[num][0] = temp;
	}
	else if(d == -1){ //반시계
		int temp = wheel[num][0];
		for (int i = 0; i <7; i++) {
			wheel[num][i] = wheel[num][i+1];
		}
		wheel[num][7] = temp;
	}
	else return;
}

int main() {
	char a;
	for (int i = 0; i <4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> a;
			wheel[i][j] = (int)a - 48;
		}
	}
	cin >> k;
	int num, d, sum=0;
	

	for (int i = 0; i <4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << wheel[i][j] << " ";
		}
		cout << endl;
	}
	while (k!=0) {
		cin >> num >> d;
		num--;
		memset(nd, 0, sizeof(nd));
		nd[num] = d;
		if (num == 0) {
			for (int i = 1; i < 4; i++) {
				if (wheel[i-1][2] != wheel[i][6]) nd[i] = nd[i - 1] * (-1);
			}
		}
		else if (num == 1) {
			if (wheel[0][2] != wheel[1][6]) nd[0] = nd[1] * (-1);
			for (int i = 1; i < 3; i++) {
				if (wheel[i][2] != wheel[i+1][6]) nd[i+1] = nd[i] * (-1);
			}
		}
		else if (num == 2) {
			if(wheel[2][2] != wheel[3][6]) nd[3] = nd[2] * (-1);
			for (int i = 2; i >0; i--) {
				if (wheel[i][6] != wheel[i-1][2]) nd[i-1] = nd[i] * (-1);
			}
		}
		else {
			for (int i = 3; i > 0; i--) {
				if (wheel[i][6] != wheel[i-1][2]) nd[i-1] = nd[i] * (-1);
			}
		}

		for (int i = 0; i < 4; i++) change(i, nd[i]);// 톱니바뀌 움직임
		k--;
	}

	for (int i = 0; i < 4; i++) if (wheel[i][0] == 1) sum += pow(2, i);//합 계산
	cout << sum <<endl;
}