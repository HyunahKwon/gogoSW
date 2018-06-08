#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int N, M, lab[8][8], lab_tmp[8][8], dy[4] = {-1,0,1,0}, dx[4] = {0,-1,0,1};
vector<pair<int,int>> vac, virus;

int solve();
void setWall(int i, int j, int k, int val);
int spread();
int countSafe();

int main() {
    /* Initialize */
    memset(lab, 0xff, sizeof(int)*8*8);

    /* Input */
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d", &lab[i][j]);
            if(lab[i][j] == 0) vac.push_back(make_pair(i, j));
            if(lab[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }

    /* Solve */
    printf("%d", solve());

    return 0;
}

int solve() {
    int maxval = 0;
    for(int i=0; i<vac.size(); i++) {
        for(int j=i+1; j<vac.size(); j++) {
            for(int k=j+1; k<vac.size(); k++) {
                memcpy(lab_tmp, lab, sizeof(int)*8*8);
                setWall(i, j, k, 1);
                spread();
                int val = countSafe();
                maxval = (maxval>val)?maxval:val;
            }
        }
    }
    return maxval;
}

void setWall(int i, int j, int k, int val) {
    lab_tmp[vac[i].first][vac[i].second] = val;
    lab_tmp[vac[j].first][vac[j].second] = val;
    lab_tmp[vac[k].first][vac[k].second] = val;
}

int spread() {
    queue<pair<int,int>> q;

    for(int i=0; i<virus.size(); i++)
        q.push(make_pair(virus[i].first, virus[i].second));
    while(!q.empty()) {
        int r = q.front().first, c = q.front().second;
        for(int i=0; i<4; i++) {
            int nr = r+dy[i], nc = c+dx[i];
            if(nr>=0 && nr<N && nc>=0 && nc<M) {
                if(lab_tmp[nr][nc] == 0) {
                    lab_tmp[nr][nc] = 2;
                    q.push(make_pair(nr, nc));
                }
            }
        }
        q.pop();
    }
}

int countSafe() {
    int count=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(lab_tmp[i][j] == 0) count++;
        }
    }
    return count;
}