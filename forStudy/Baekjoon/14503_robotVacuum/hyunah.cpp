#include <iostream>
using namespace std;

int main() {
	int N, M;   // N: row, M: column
	int r, c;  // r: initial x-coord, c: initial y-coord
	int direction; // 0: N, 1: E, 2: N, 3: W
	int arr[50][50] = { 3 };  // 0: dirty, 1: wall, 2: clean, 3: initialize
	bool chk; // visit
	int cnt = 0;
	int next[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };  // W, N, E, S
	/*
	 -1  0
	  0  1
	  1  0
	  0 -1
	*/

	// input
	cin >> N >> M;
	cin >> r >> c >> direction;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	// dfs
	chk = false;
	while (1) {
		if (arr[r][c] == 0) {
			arr[r][c] = 2;  // make it clean
			cnt++;
		}

		for (int i = 0; i < 4; i++) {
			if (arr[r + next[i][0]][c + next[i][1]] != 0) {
				chk = true;
			}
			else {
				chk = false;
				break;
			}
		}

		if (chk == true) {
			int t = (direction + 2) % 4;

			if (arr[r + next[t][0]][c + next[t][1]] == 1)  // wall
				break;

			r += next[t][0];
			c += next[t][1];
		} else {
			direction = (direction + 3) % 4;

			if (arr[r + next[direction][0]][c + next[direction][1]] == 0) {
				r += next[direction][0];
				c += next[direction][1];
			}
		}
	}

	cout << cnt << endl;

	return 0;
}