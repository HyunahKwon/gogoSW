#include <iostream>
using namespace std;

int *numlist, *dp;

int solve(int n);

int main() {
    int n;

    scanf("%d", &n);

    /* Allocate */
    numlist = new int[n+1];
    dp = new int[n+1];

    /* Input */
    dp[0]=-1000;
    for(int i=1; i<=n; i++)
        scanf("%d", &numlist[i]);

    /* Solve */
    printf("%d\n", solve(n));

    return 0;
}

int solve(int n) {
    int maxval = dp[0];
    for(int i=1; i<=n; i++) {
        dp[i] = (numlist[i]+dp[i-1]>numlist[i])?numlist[i]+dp[i-1]:numlist[i];
        maxval = (maxval>dp[i])?maxval:dp[i];
    }
    return maxval;
}