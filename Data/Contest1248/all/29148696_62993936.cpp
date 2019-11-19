#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const long long P = 1000000007;

long long dp[N+10][4];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    dp[1][0] = 1;
    for (int i = 2; i <= max(n, m); ++i){
        dp[i][0] = (dp[i-1][1] + dp[i-1][3]) % P;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % P;
        dp[i][2] = dp[i-1][0];
        dp[i][3] = dp[i-1][1];
    }
    long long tn = (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3]) % P;
    long long tm = (dp[m][0] + dp[m][1] + dp[m][2] + dp[m][3]) % P;
    long long ans = ((tn - 1 + tm) * 2 % P + P) % P;
    printf("%I64d\n", ans);
    return 0;
}