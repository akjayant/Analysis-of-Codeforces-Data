#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,s,f) for(i=s;i<f;i++)
#define print(v) for(auto &z:v) cout<<z<<' ';cout<<'\n'
#define hi cout<<'h'<<'i'<<'\n' 
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define B begin()
#define E end()
#define vi vector<int>
#define vii vector<pair<int,int>>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define clean(arr) memset(arr,0,sizeof(arr))
#define mod 1000000007
#define mod2 998244353
#define space 100005
//<<fixed << setprecision(9)

int main()
{
    int n,i,j,t;
    boost;
    int m;
    cin>>n>>m;

    int dp[m][4];
    dp[0][0]=0;
    dp[0][1]=1;
    dp[0][2]=1;
    dp[0][3]=0;
    rep(i,1,m)
    {
        dp[i][0]=dp[i-1][2];
        dp[i][1]=dp[i-1][0]+dp[i-1][2];
        dp[i][3]=dp[i-1][1];
        dp[i][2]=dp[i-1][3]+dp[i-1][1];
        rep(j,0,4)dp[i][j]%=mod;
    }
    ll ways=0;
    rep(j,0,4)
    {
        ways+=dp[m-1][j];
        ways%=mod;
    }
    //cout<<ways<<' ';
    // print(dp[0]);
    // print(dp[1]);
    // print(dp[2]);
    ll ans=ways-2;
    int dp2[n][4];
    dp2[0][0]=0;
    dp2[0][1]=1;
    dp2[0][2]=1;
    dp2[0][3]=0;
    rep(i,1,n)
    {
        dp2[i][0]=dp2[i-1][2];
        dp2[i][1]=dp2[i-1][0]+dp2[i-1][2];
        dp2[i][3]=dp2[i-1][1];
        dp2[i][2]=dp2[i-1][3]+dp2[i-1][1];
        rep(j,0,4)dp2[i][j]%=mod;
    }

    rep(j,0,4)
    {
        ans+=dp2[n-1][j];
        ans%=mod;
    }   
    cout<<ans;
    return 0;
}

