#include<bits/stdc++.h>
#define faster_io ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define mem(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
using namespace std;
const ll N=1e6+3,inf=1e18,mod=1e9+7,eps=-1e8;
ll tc,n,m,a,b,c,i,j,k,l,sum,ans,mx;
ll ar[N];
string s,t;
vector<ll>v;

int32_t main()
{
    faster_io;
    cin>>n>>m;
    for(i=1; i<=n; i++)
        cin>>a,v.pb(a);
    sort(v.begin(),v.end());
    ll lft=0,rgt=n-1;
    while(lft<rgt&&(lft+1<=m||n-rgt<=m))
    {
        if(v[lft]==v[lft+1])
        {
            lft++;
            continue;
        }
        if(v[rgt]==v[rgt-1])
        {
            rgt--;
            continue;
        }
        if(lft+1<n-rgt)
        {
            if((v[lft+1]-v[lft])*(lft+1)<=m)
                m-=(v[lft+1]-v[lft])*(lft+1);
            else
            {
                v[lft]+=m/(lft+1);
                break;
            }
            lft++;
        }
        else
        {
            if((v[rgt]-v[rgt-1])*(n-rgt)<=m)
                m-=(v[rgt]-v[rgt-1])*(n-rgt);
            else
            {
                v[rgt]-=m/(n-rgt);
                break;
            }
            rgt--;
        }
    }
    cout<<v[rgt]-v[lft]<<endl;
}
