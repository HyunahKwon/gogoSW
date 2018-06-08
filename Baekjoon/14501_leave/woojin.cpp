#include <cstdio>
#include <queue>
using namespace std;

int N, T[16], P[16], reserved[16];

int solve(int n);
bool isPossible(int period, int n);
void setConsulting(int period, int n, int val);

int main() {

    /* Input */
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }

    /* Solve */
    printf("%d", solve(N));
}

int solve(int n) {
    int maxval = 0;

    if(n==0) return 0;

    if(T[n] <= N-n+1 && isPossible(T[n], n)) {
        setConsulting(T[n], n, 1);
        int val = solve(n-1)+P[n];
        maxval = (val>maxval)?val:maxval;
        setConsulting(T[n], n, 0);
    }
    int val = solve(n-1);
    maxval = (val>maxval)?val:maxval;

    return maxval;
}

bool isPossible(int period, int n) {
    for(int i=n; i<n+period; i++) {
        if(reserved[i] == 1) return false;
    }
    return true;
}

void setConsulting(int period, int n, int val) {
    for(int i=n; i<n+period; i++) reserved[i] = val;
}