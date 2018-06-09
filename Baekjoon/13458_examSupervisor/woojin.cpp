#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

long long N, A[1000000], B, C;

long long solve();

int main() {
    /* Initialize */

    /* Input */
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);
    scanf("%d %d", &B, &C);

    /* Solve */
    printf("%lld", solve());

    return 0;
}

long long solve() {
    long long supervisor_cnt = 0;
    for(int i=0; i<N; i++) {
        if(A[i]>B) supervisor_cnt += ((A[i]-B)%C==0)?(A[i]-B)/C+1:((A[i]-B)/C+1)+1;
        else supervisor_cnt += 1;
    }
    return supervisor_cnt;
}