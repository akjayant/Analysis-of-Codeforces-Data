#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int dp[N][2];
int fun(int n, int p){
    if(n < 0) return 0;
    if(n == 0){
        return 1;
    }
    int &ret = dp[n][p];
    if(ret != -1) return ret;
    ret = 0;
    if(p == 1){
        return ret = fun(n - 1, 0);
    }
    return ret = (fun(n - 1, 1) + fun(n - 1, 0)) % mod;
}
int main(){
    int test;
    test = 1;
    while(test--){
        int n, m;
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &n, &m);
        if(n == 1 && m == 1){
            printf("2\n");
            return 0;
        }
        int ans = (fun(n, 1) + fun(m, 1)) % mod;
        ans--;
        if(ans < 0){
            ans += mod;
        }
        printf("%lld\n", (2LL * ans) % mod);
    }
    return 0;
}