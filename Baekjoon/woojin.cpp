#include <iostream>
#include <cstring>
using namespace std;

char home[50][50];

int solve(int r, int c, int d);

int main() {
    int N, M, r, c, d;

    /* Initialize */
    memset(home, 0xff, sizeof(char)*50*50);

    /* Input */
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &r, &c, &d);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d", &home[i][j]);
        }
    }

    /* Solve */
    printf("%d\n", solve(r, c, d));

    return 0;
}

int solve(int r, int c, int d) {
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    int count = 0;

    if(home[r][c] != 2) {
        home[r][c] = 2;
        count++;
    }
    d = d+4;

    if((home[r+dy[(d-1)%4]][c+dx[(d-1)%4]] & 3) == 0) {
        count += solve(r+dy[(d-1)%4], c+dx[(d-1)%4], (d-1)%4);
    }else if((home[r+dy[(d-2)%4]][c+dx[(d-2)%4]] & 3) == 0) {
        count += solve(r+dy[(d-2)%4], c+dx[(d-2)%4], (d-2)%4);
    }else if((home[r+dy[(d-3)%4]][c+dx[(d-3)%4]] & 3) == 0) {
        count += solve(r+dy[(d-3)%4], c+dx[(d-3)%4], (d-3)%4);
    }else if((home[r+dy[d%4]][c+dx[d%4]] & 3) == 0) {
        count += solve(r+dy[d%4], c+dx[d%4], d%4);
    }else if(home[r+dy[(d-2)%4]][c+dx[(d-2)%4]] != 1) {
        count += solve(r+dy[(d-2)%4], c+dx[(d-2)%4], d);
    }

    return count;
}