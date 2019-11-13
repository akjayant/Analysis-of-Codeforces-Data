#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define pi pair<int,int>
#define vi vector<int>
#define pL pair<ll,ll>
#define vL vector<ll>
#define vp vector<pi>
#define vpL vector<pL>

const int MX=300000;
const ll inf=1e18;
const ll mod=1e9+7;

ll bigmod(ll a, ll b)
{
    if(!b) return 1;
    if(b&1) return (a*bigmod(a, b-1))%mod;
    else
    {
        ll r=bigmod(a, b/2);
        return (r*r)%mod;
    }
}
int main()
{
    FasterIO;
    ll n, m;
    cin>>n>>m;
    ll r=(bigmod(2, m)-1+mod)%mod;
    r=bigmod(r, n);
    cout<<r<<endl;
    return 0;
}
