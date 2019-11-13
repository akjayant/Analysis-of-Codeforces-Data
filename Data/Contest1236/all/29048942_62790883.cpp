#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef pair<int,int>   pii;
typedef vector< pii >  vii;
typedef long long int 	ll;

#define pb push_back
#define fe first
#define se second
#define all(a) (a).begin(),(a).end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define scn(n) scanf("%d",&n)
#define prn(n) printf("%d\n",n)
#define scnl(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mset(A, val) memset(A, val, sizeof(A))

const ll mod = 1e9 + 7ll;
const int N = (int)1e5 + 7;

inline ll mult(ll a , ll b) { ll x = a; x *= ll(b); if(x >= mod) x %= mod; return x; }
inline ll add(ll a , ll b) { return a + b >= mod ? a + b - mod : a + b; }
inline ll sub(ll a , ll b) { return a - b < 0 ? mod - b + a : a - b; }
inline ll gcd(ll a, ll b) { if(a==0) return b; return gcd(b%a, a); }

ll BE(ll a, ll b)
{
	ll ans = 1;
	for(ans = 1;b; a = (a*a)%mod,b = b>>1)
	{
		if(b&1ll)
		ans = (ans*a)%mod;
	}
	return ans;
}

int main(){
	
	fast_io;
	ll n,m;
	cin>>n>>m;
	ll ans= BE(2,m);
	ans = sub(ans,1);
	ans = BE(ans,n);
	cout<<ans<<endl;
	return 0;
}
