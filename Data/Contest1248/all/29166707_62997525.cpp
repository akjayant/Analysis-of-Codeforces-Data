
/*
Nahid Hossain
Jahangirnagar University
Roll:54
*/
#include<bits/stdc++.h>
#define ll          long long int
#define db          double
#define ma 20005
#define mod 1000000007
using namespace std;
ll dp[100002];

ll pre(ll x)
{
    if(x<0)return 0;
    if(x==0)return 1;
    ll &r=dp[x];
    if(r!=-1)return r;
    r=pre(x-2)+pre(x-1);
    r%=mod;
    return r;
}
int main()
{
    ll n,m;
    cin>>n>>m;

        memset(dp,-1,sizeof(dp));

        ll ans=pre(n)*2;
       ans%=mod;
       ll ans1=0;
       ans1=pre(m)*2;

        cout<<(ans+ans1-2+mod)%mod<<endl;
}
