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
    int f=0,nn=n;
    for(i=2;i<=sqrt(nn);i++)
    {
        if(nn%i==0)
        {
            f=i;
            break;
        }
    }
    if(!f)
    {
        cout<<n;
        return;
    }
    while(nn%f==0)
    {
        nn/=f;
    }
    if(nn==1)
    {
        cout<<f;
        return;
    }
    cout<<1;
}
signed main()
{
    fast;
    int t=1;
    //cin>>t;
    int cas=1;
    while(cas<=t)
    {
    shikhar7s(cas);
    cas++;
    }
    return 0;
}