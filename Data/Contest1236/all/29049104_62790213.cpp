#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
// #define int ll
using namespace std;
const int INF (1 << 30);
const ll LLINF (1LL << 55LL);
const int MOD = 1000000007;
const int MAX = 510000;

ll mod_pow(ll x,ll n, ll mod){
    if(n==0) return 1;
    ll res=mod_pow(x * x % mod, n/2, mod);
    if(n & 1) res=res * x % mod;
    return res;
}

 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n,m,ans;
    cin>>n>>m;
    ll s=(mod_pow(2,m,MOD)-1);
    ans=mod_pow(s,n,MOD);
    cout<<ans<<endl;
    return 0;
}