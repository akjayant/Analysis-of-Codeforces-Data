#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
const ll mod=1e9+7;
ll dp[maxn];
int main()
{
    dp[0]=dp[1]=1;
    for(int i=2; i<=1e5; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=mod;
    }
    int n, m;
    cin>>n>>m;
    ll sum;
    sum=(dp[n]+dp[m]-1+mod)%mod;
    sum*=2;
    sum%=mod;
    cout<<sum<<endl;
    return 0;
}
