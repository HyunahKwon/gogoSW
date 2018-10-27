#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int building[1000];

int solve(int N);
int getmax(int a, int b, int c, int d);

int main(void) {
    int test_case, N;

    //freopen("input.txt", "r", stdin);
    for(test_case = 1; test_case <= 10; ++test_case) {
        /* Initialize */
        memset(building, 0xff, sizeof(int)*1000);

        /* Input */
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            scanf("%d", &building[i]);
        }

        /* Solve */
        printf("#%d %d\n", test_case, solve(N));
    }

    return 0;
}

int solve(int N) {
    int count = 0;
    for(int i=2; i<N-2; i++) {
        int maxh = getmax(building[i-2], building[i-1], building[i+1], building[i+2]);
        if(maxh < building[i]) count += (building[i] - maxh);
    }
    return count;
}

int getmax(int a, int b, int c, int d) {
    int maxh = 0;
    maxh = (maxh<a)?a:maxh;
    maxh = (maxh<b)?b:maxh;
    maxh = (maxh<c)?c:maxh;
    maxh = (maxh<d)?d:maxh;

    return maxh;
}