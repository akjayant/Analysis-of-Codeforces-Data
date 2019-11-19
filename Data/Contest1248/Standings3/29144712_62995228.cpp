#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(), (a).end()
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define sz() size()
#define fr first
#define sc second
#define pb push_back
#define er erase
#define in insert
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>
#define mp make_pair
#define int long long
#define rc(s) return cout<<s,0
#define rcc(s) cout<<s,exit(0)
///#define cin fin
///#define cout fout
using namespace std;

const int mod=1e9+7;
const int mod1=998244353;

int n,m;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    if(n>=3 && m>=3){
        int dp1[n+5][3][3],dp2[m+5][3][3];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=2;j++){
                for(int t=1;t<=2;t++) dp1[i][j][t]=0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=2;j++){
                for(int t=1;t<=2;t++) dp2[i][j][t]=0;
            }
        }
        dp1[1][1][1]=1;
        dp1[1][2][1]=1;
        dp2[1][1][1]=1;
        dp2[1][2][1]=1;
        for(int i=2;i<=n;i++){
            dp1[i][1][1]=(dp1[i-1][2][1]+dp1[i-1][2][2])%mod;
            dp1[i][1][2]=dp1[i-1][1][1]%mod;
            dp1[i][2][2]=dp1[i-1][2][1]%mod;
            dp1[i][2][1]=(dp1[i-1][1][1]+dp1[i-1][1][2])%mod;
        }
        for(int i=2;i<=m;i++){
            dp2[i][1][1]=(dp2[i-1][2][1]+dp2[i-1][2][2])%mod;
            dp2[i][1][2]=dp2[i-1][1][1]%mod;
            dp2[i][2][2]=dp2[i-1][2][1]%mod;
            dp2[i][2][1]=(dp2[i-1][1][1]+dp2[i-1][1][2])%mod;
        }
        rc((dp1[n][1][1]+dp1[n][1][2]+dp1[n][2][1]+dp1[n][2][2]+dp2[m][1][1]+dp2[m][1][2]+dp2[m][2][1]+dp2[m][2][2]-2)%mod);
    }
    if(n==1 || m==1){
        if(n<m) swap(n,m);
        int dp[n+5][3][3];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=2;j++){
                for(int t=1;t<=2;t++) dp[i][j][t]=0;
            }
        }
        dp[1][1][1]=1;
        dp[1][2][1]=1;
        for(int i=2;i<=n;i++){
            dp[i][1][2]=dp[i-1][1][1]%mod;
            dp[i][2][2]=dp[i-1][2][1]%mod;
            dp[i][1][1]=(dp[i-1][2][1]+dp[i-1][2][2])%mod;
            dp[i][2][1]=(dp[i-1][1][1]+dp[i-1][1][2])%mod;
        }
        rc((dp[n][1][1]+dp[n][1][2]+dp[n][2][1]+dp[n][2][2])%mod);
    }
    else{
        if(n<m) swap(n,m);
        int dp[n+5][5][3];
        for(int i=1;i<=n;i++){
            for(int t=1;t<=4;t++){
                for(int k=1;k<=2;k++) dp[i][t][k]=0;
            }
        }
        dp[1][1][1]=1;
        dp[1][2][1]=1;
        dp[1][3][1]=1;
        dp[1][4][1]=1;
        for(int i=2;i<=n;i++){
            dp[i][3][2]=dp[i-1][3][1]%mod;
            dp[i][4][2]=dp[i-1][4][1]%mod;
            dp[i][3][1]=(dp[i-1][4][1]+dp[i-1][4][2])%mod;
            dp[i][4][1]=(dp[i-1][3][1]+dp[i-1][3][2])%mod;
            dp[i][1][1]=dp[i-1][2][1]%mod;
            dp[i][2][1]=dp[i-1][1][1]%mod;
        }
        rc((dp[n][3][1]+dp[n][3][2]+dp[n][4][1]+dp[n][4][2]+dp[n][1][1]+dp[n][2][1])%mod);
    }
}
