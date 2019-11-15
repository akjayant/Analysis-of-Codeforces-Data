#include<bits/stdc++.h>
#define maxn 100005
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define mod 1000000007
#define pb push_back
#define plll pair<pll,pll>
#define xx first.first
#define yy first.second
#define zz second.first
#define br second.second
#define INF 1000000000
using namespace std;


ll digni(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2==0)
    {
        ll res=digni(x,y/2);
        return (res*res)%mod;
    }
    return (digni(x,y-1)*x)%mod;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n,m;
    cin>>n>>m;

    ll ste2=digni(2,m);
    cout<<digni(ste2-1,n);

    return 0;
}
