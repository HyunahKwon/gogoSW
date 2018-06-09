#include<stdio.h>
#include<vector>
#include<utility>

using namespace std;

int MAX = 0;
vector<pair<int, int>> work;
int n;
//2018.04.11 ¿Ï
void DFS(int v, int val) {
	if (v + work[v].first > n + 1 || v > n + 1) return;
	val += work[v].second;
	
	if (MAX < val) MAX = val;
	for (int i = v + work[v].first; i <= n; i++) {
		DFS(i, val);
	}

}
int main() {
	scanf("%d", &n);
	work.assign(n + 1, make_pair(0, 0));
	int d, p;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &d, &p);
		work[i] = make_pair(d, p);
	}

	for (int i = 1; i <= n; i++) {
		DFS(i, 0);
	}
	printf("%d\n", MAX);
}