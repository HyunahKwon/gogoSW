#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int worm_pos[20][2];
int perm[20], chk[20];
//unsigned long minvec = 0xffffffffffffffff;

unsigned long solve(int pos, int N);
unsigned long vecsum(int N);

int main(void) {
    int test_case, N;
    int T;

    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for(test_case = 1; test_case <= T; ++test_case) {
        /* Initialize */
        memset(worm_pos, 0xff, sizeof(int)*20*2);
        memset(chk, 0xff, sizeof(int)*20);
        memset(perm, 0xff, sizeof(int)*20);

        /* Input */
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            scanf("%d %d", &worm_pos[i][0], &worm_pos[i][1]);
        }

        /* Solve */
        printf("#%d %lu\n", test_case, solve(0, N));
    }

    return 0;
}

unsigned long solve(int pos, int N) {
    unsigned long minvec = 0xffffffffffffffff;
    if(pos == N)
        return vecsum(N);

    for(int i=0; i<N; i++) {
        if(chk[i] != 1) {
            perm[pos] = i; chk[i] = 1;
            unsigned long tmp = solve(pos+1, N);
            minvec = (minvec>tmp)?tmp:minvec;
            perm[pos] = -1; chk[i] = -1;
        }
    }
    return minvec;
}

unsigned long vecsum(int N) {
    unsigned long x=0, y=0;
    for(int i=0; i<N-1; i=i+2) {
        x += (worm_pos[i+1][0] - worm_pos[i][0]);
        y += (worm_pos[i+1][1] - worm_pos[i][1]);
    }
    return x*x+y*y;
}