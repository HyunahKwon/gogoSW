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

//��������(0�ΰ�) ã�� map ���� �ǵ�����
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

//���̷����� bfs ������� ��Ʈ����
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

//����� 3�� ����� ���� ��� ����� ���� dfs�� ã�´�
void dfs(int x, int y, int d) {

	map[x][y] = 1;
	visited[x][y] = 1;

	if (d == 3) {//����� 3����
		//���̷����� ��Ʈ���� ���� ���� ���� ���� �ؾ߉�
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = map[i][j];
			}
		}

		bfs();//���̷��� ��Ʈ��
		maxval = max(maxval, countsafety());//�������� �ִ밪 ���ϸ鼭 ���̷��� ��Ʈ������ ������ ����
		
		//��Ʈ��ŷ
		map[x][y] = 0; 
		visited[x][y] = 0;
		return;
	}

	//��ռ����
	for (int i = x; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || map[i][j] != 0) continue;
			dfs(i, j, d + 1);
		}
	}

	//��Ʈ��ŷ
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