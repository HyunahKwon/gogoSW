#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;

int map[8][8];
int temp[8][8];
int visited[8][8];
int n, m;
vector<pair<int, int>> vi;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int maxval=-1;

//안전구역(0인곳) 찾고 map 상태 되돌리기
int countsafety() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) res++;
			map[i][j] = temp[i][j];
		}
	}
	return res;
}

//바이러스를 bfs 방식으로 퍼트린다
void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < vi.size(); i++)
		q.push(vi[i]);


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] != 0) continue;
			
			map[nx][ny] = 2;
			q.push(make_pair(nx, ny));
		}
	}
}

//기둥을 3개 세우기 위해 모든 경우의 수를 dfs로 찾는다
void dfs(int x, int y, int d) {

	map[x][y] = 1;
	visited[x][y] = 1;

	if (d == 3) {//기둥이 3개면
		//바이러스를 퍼트리기 전의 맵을 따로 복사 해야됌
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = map[i][j];
			}
		}

		bfs();//바이러스 퍼트림
		maxval = max(maxval, countsafety());//안전구역 최대값 구하면서 바이러스 퍼트리기전 맵으로 돌림
		
		//백트래킹
		map[x][y] = 0; 
		visited[x][y] = 0;
		return;
	}

	//기둥세우기
	for (int i = x; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || map[i][j] != 0) continue;
			dfs(i, j, d + 1);
		}
	}

	//백트래킹
	map[x][y] = 0;
	visited[x][y] = 0;

}
int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) vi.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) dfs(i, j, 1);
		}
	}

	printf("%d\n", maxval);

	return 0;

}