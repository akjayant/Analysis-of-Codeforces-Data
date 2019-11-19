#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define x first
#define y second

using namespace std;

ll mod=1e9+7;

int main()
{
    //freopen("test.in","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    vector<vector<vector<ll>>> dp1(n,{{0,0},{0,0}}),dp2(m,{{0,0},{0,0}});
    if(n>1)dp1[1][0][0]=dp1[1][0][1]=dp1[1][1][0]=dp1[1][1][1]=1;
    if(m>1)dp2[1][0][0]=dp2[1][0][1]=dp2[1][1][0]=dp2[1][1][1]=1;
    for(int i=2;i<n;i++)
    {
        dp1[i][0][1]=(dp1[i-1][0][0]+dp1[i-1][1][0])%mod;
        dp1[i][0][0]=dp1[i-1][1][0]%mod;
        dp1[i][1][1]=dp1[i-1][0][1]%mod;
        dp1[i][1][0]=(dp1[i-1][1][1]+dp1[i-1][0][1])%mod;
    }
    for(int i=2;i<m;i++)
    {
        dp2[i][0][1]=(dp2[i-1][0][0]+dp2[i-1][1][0])%mod;
        dp2[i][0][0]=dp2[i-1][1][0];
        dp2[i][1][1]=dp2[i-1][0][1];
        dp2[i][1][0]=(dp2[i-1][1][1]+dp2[i-1][0][1])%mod;
    }
    ll all1,all2;
    if(n>1)all1=(dp1[n-1][0][0]+dp1[n-1][0][1]+dp1[n-1][1][0]+dp1[n-1][1][1])%mod;
    if(m>1)all2=(dp2[m-1][0][0]+dp2[m-1][0][1]+dp2[m-1][1][0]+dp2[m-1][1][1])%mod;
    if(n==1 && m==1) cout<<2<<'\n';
    else if(n==1) cout<<all2<<'\n';
    else if(m==1) cout<<all1<<'\n';
    else cout<<(all1+all2-2)%mod<<'\n';
}
