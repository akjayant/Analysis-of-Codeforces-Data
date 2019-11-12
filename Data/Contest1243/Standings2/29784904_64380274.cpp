#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define fr(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define endl "\n"
#define fast std::ios_base::sync_with_stdio(false)
#define mod 1000000007
#define pi 3.14159265
void shikhar7s(int cas)
{
    int n,i;
    cin>>n;
    int a[n];
    fr(i,n)
    {
    	cin>>a[i];
    }
    sort(a,a+n);
    int c=1,ans=0,m=mod;
    for(i=n-1;i>=0;i--)
    {
    	m=min(m,a[i]);
    	ans=max(ans,min(c,m));
    	c++;
    }
    cout<<ans<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin>>t;
    int cas=1;
    while(cas<=t)
    {
	shikhar7s(cas);
	cas++;
    }
    return 0;
}