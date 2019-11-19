#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#define fir first
#define sec second
using namespace std;

const long long mod = 1e9+7;
const int maxn = 1e5+7;


int n,m;
long long dp[maxn][2]; // = ！=

int main() {
    cin>>n>>m;
    dp[0][1] = 0;
    dp[0][0] = 2;
    for(int i=1;i<=max(n,m);i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] += dp[i-1][0];
        dp[i][1] += dp[i-1][1];
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        // cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<endl;
    }
    cout<<(dp[n][0]+dp[n][1]+dp[m][0]+dp[m][1]-2+mod)%mod<<endl;
    return 0;
}