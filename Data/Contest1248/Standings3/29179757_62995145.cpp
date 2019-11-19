#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define rep(i,s,t) for(int i = s;i <= t;i++)
#define per(i,t,s) for(int i = t;i >= s;i--)
#define mst(s) memset(s,0,sizeof(s))
#define ls(x) x<<1
#define rs(x) x<<1|1 
#define lb(x) x&-x
#define pii pair<int,int>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pi acos(-1)
#define F first
#define S second 
#define cuts printf("\n--------------\n");
#define maxn 100005
#define maxm 400005
#define mod 1000000007LL
#define inf 1LL<<60
int n, m;
ll dp1[maxn][4], dp[maxn];;
int main(){
    scanf("%d%d",&n,&m);
    dp1[2][0] = dp1[2][1] = dp1[2][2] = dp1[2][3] = 1;
    dp[1] = 2;
    dp[2] = 4;
    rep(i,3,max(n,m)){
    	dp1[i][0] = dp1[i-1][2];
    	dp1[i][1] = (dp1[i-1][0] + dp1[i-1][2])%mod;
    	dp1[i][2] = (dp1[i-1][1] + dp1[i-1][3])%mod;
    	dp1[i][3] = dp1[i-1][1];
		dp[i] = (((dp1[i][0] + dp1[i][1])%mod + dp1[i][2])%mod + dp1[i][3])%mod; 
    }
    printf("%lld\n",((dp[n]+dp[m]-2)%mod+mod)%mod);
    return 0;
}

//Accepted! 
