#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define FER(i,a,b) for(ll i = ll(a); i < ll(b); ++ i)
#define IFR(i,a,b) for(ll i = ll(a); i >= ll(b); -- i)
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define ff first
#define ss second
#define tm1 ff
#define tm2 ss.ff
#define tm3 ss.ss
#define fill(x,v) memset(x,v,sizeof(x))
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sqr(x) (x)*(x)
#define bas 987625403
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> tri;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)

template<typename t> void fff(const char *x, t&& val1){
	cout << x << " : " << val1 << endl;
}

template<typename t1, typename... t2> void fff(const char *x, t1&& val1, t2&&... val2){
	const char *xd = strchr(x + 1, ',');
	cout.write(x, xd -x) << " : " << val1 << " | ";
	fff(xd + 1, val2...);
}

//111111

vector<ll> v;

ll lcm(ll a, ll b){
	return (a * b) / __gcd(a, b);
}

int main(){
	fastio;
	ll n; cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	for(ll x = 1; x * x <= n; x ++){
		if(n % x == 0){
			ll p = x, q = n / x;
			if(p != 1) v.pb(p);
			if(p != q && q != 1) v.pb(q);
		}
	}
	sort(all(v));
	ll ans = 0;
	if(sz(v) == 1) ans = v[0];
	else{
		ans = __gcd(v[0], v[1]);
		FER(i, 2, sz(v)) ans = __gcd(ans, v[i]);
	}
	cout << ans << endl;
	return 0;
}
