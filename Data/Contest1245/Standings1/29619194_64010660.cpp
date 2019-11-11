#include <bits/stdc++.h>

using namespace std;

const int N=1e6+2,MOD=1e9+7;

typedef long long ll;

int a,b,c,n,m,x,y,u,v,tc,k,ans,l,r,q,dp[N];

char s[N];

int solve(int idx){
    if (idx>=n)
        return 1;
    int &r=dp[idx];
    if (~r)
        return r;
    r=0;
    if (s[idx]=='w' || s[idx]=='m')
        return 0;
    if (s[idx]=='n' && s[idx+1]=='n')
        r=(r+solve(idx+2))%MOD;
    if (s[idx]=='u' && s[idx+1]=='u')
        r=(r+solve(idx+2))%MOD;
    return r=(r+solve(idx+1))%MOD;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("test.txt","r",stdin);
    #endif
    memset(dp,-1,sizeof dp);
    scanf("%s",s);
    n=strlen(s);
    printf("%d",solve(0));
}
