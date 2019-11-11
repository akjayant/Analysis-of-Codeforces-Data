#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<" --> "<<x<<endl;
#define N 100005
#define M 1000000007
#define pii pair<int,int>
using namespace std;
string s;
int n;
ll dp[N];
ll run(int now)
{
    if(dp[now]!=-1)
    {
        return dp[now];
    }
    if(now==n)
        return 1;
    ll ans=0;
    if(now+1<n)
    {
        if(s[now]=='u'&&s[now+1]=='u')
        {
            ans=run(now+2);
        }
        if(s[now]=='n'&&s[now+1]=='n')
        {
            ans=run(now+2);
        }
    }
    if(s[now]!='w'&&s[now]!='m') ans=(ans+run(now+1))%M;
    return dp[now]=ans;
}
main()
{
    memset(dp,-1,sizeof dp);
   cin>>s;
   n=s.size();
   cout<<run(0);
}
