using namespace std;
#include<bits/stdc++.h>
#define pb push_back
#define ip pair<int,int>
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define MOD 998244353
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define show(x) cout<<#x<<" = "<<(x)<<" "
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define EN cout<<endl;
#define fn(i,n) for (ll i=0; i<n; i++)
#define fone(i,n) for (int i=1; i<=n; i++)
#define fl(i,a,b) for (int i=a; i<=b; i++)
#define inp(n) int n; cin>>n;
#define TEST int t; cin>>t; while(t--)
#define MAX 3000
#define all(v) v.begin(), v.end()
#define int long long
ll power(ll x, ll y, ll p) { int res = 1; x = x % p;  while (y > 0) { if (y & 1) res = (res*x) % p; y = y>>1;x = (x*x) % p;} return res; } 
ll PO(ll a, ll n) { ll val=1; fn(i,n) val*=a; return val;  }
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
 
signed main()
{
    IOS;
    int n; cin>>n;
    vector<int> v(n);
    fn(i,n) cin>>v[i];
    int x=0, y=0;
    sort(all(v),greater<int>());

    for (int i=0; i<n/2+(n%2); i++)
        x+=v[i];
    for (int i=n/2+n%2; i<n; i++)
        y+=v[i];
    cout<<x*x+y*y<<endl;
}