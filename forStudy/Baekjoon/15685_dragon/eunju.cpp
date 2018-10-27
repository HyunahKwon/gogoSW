#include<iostream>
#include<vector>
using namespace std;

vector<int> hist;
bool map[100][100];
int sx, sy, sd, sg, t;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
//예제는 맞지만 왜 틀렸는가..??!!!!
int findRectangle() {
	int res=0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == true && map[i + 1][j] == true && map[i][j + 1] == true && map[i + 1][j + 1] == true)
				res++;
		}
	}
	return res;
}
void printMap() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout <<map[i][j]<<" ";
		}
		cout << endl;
	}
}
void solve(int x, int y, int d, int g) {
	map[y][x] = true;
	hist.push_back(d);
	
	int nx = x + dx[d];
	int ny = y + dy[d]; 
	map[ny][nx] = true;
	int nd = (d + 1) % 4;

	while (g!=0) {
		for (int i = hist.size()-1; i>=0; i--) {
			nd = (hist.at(i)+1)%4;
			nx = dx[nd] + nx;
			ny = dy[nd] + ny;
			map[ny][nx] = true;
			hist.push_back(nd);
		}
		g--;
	}

}

int main() {
	memset(map, false, sizeof(map));
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> sx >> sy >> sd >> sg;
		solve(sx, sy, sd, sg);
		hist.clear();
	}
	cout << findRectangle() << endl;

	return 0;
}
