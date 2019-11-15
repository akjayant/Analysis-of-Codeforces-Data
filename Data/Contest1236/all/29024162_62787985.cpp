//Utkarsh.25dec
#include <bits/stdc++.h>
#define ll long long int 
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
using namespace std;
const int N=500023;
bool vis[N];
vector <int> adj[N];
ll power(ll x, ll y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return ((power(x, y / 2)%mod) * (power(x, y / 2)%mod)%mod); 
    else
        return (x * ((power(x, y / 2)%mod) * (power(x, y / 2)%mod)%mod))%mod; 
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    ll base=power(2,m);
    base--;
    if(base<0)
        base+=mod;
    ll ans=power(base,n);
    ans%=mod;
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    int t=0;
    while(t++<T)
    {
        //cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
}