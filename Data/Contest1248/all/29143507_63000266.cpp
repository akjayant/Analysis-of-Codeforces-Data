#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
const int N = 1e5+5;
ll dp[N];
ll mod = 1e9+7;
int main()
{
    memset(dp,-1,sizeof dp);
    dp[1]=2,dp[2]=4;
    for( int i = 3 ; i <N;i++){
        dp[i] = ((dp[i-1]%mod) + (dp[i-2]%mod) )%mod;
    }
    int n,m;cin>>n>>m;
    cout<<(dp[n]+dp[m]-2)%mod<<endl;
}



