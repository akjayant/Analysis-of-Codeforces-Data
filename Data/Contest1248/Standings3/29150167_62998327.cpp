#include <cstring>
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX (100005)
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define int long long
#define ll long long
#define lson (p<<1)
#define rson (lson | 1)
#define ALL(x) x.begin(),x.end()

const long long mod = 1e9 + 7;

int dp[MAX][4];
int num[MAX];
void init(){
    for(int i = 1; i <= 1e5; i++){
        if(i == 1){
            dp[1][1] = 1;
            dp[1][2] = 1;
        }else{
            dp[i][0] = dp[i-1][2];
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;
            dp[i][2] = (dp[i-1][2] + dp[i-1][3]) % mod;
            dp[i][3] = dp[i-1][1];
        }
        for(int j = 0;j < 4; j++) num[i] = (num[i] + dp[i][j]) % mod;
    }
}

signed main(void)
{
   init();
   int n, m;
   scanf("%lld%lld", &n, &m);
   memset(dp,0,sizeof dp);
   int an = 0;
   cout << ((num[n] - 2 + mod) % mod  + num[m]) % mod;
}
