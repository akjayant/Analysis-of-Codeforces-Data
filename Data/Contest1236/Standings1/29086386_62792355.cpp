#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define for0(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define int long long

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;

ll M = 1e9+7;

ll binpow (ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)
			res = (res*a)%M;;
		a = (a*a)%M;
		n >>= 1;
	}
	return res;
}

ll m1(ll a){
if (a > 0) return a-1;
return M-1;
}


signed main(){
   // ifstream cin("input.txt");
    //ofstream cout("output.txt");
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

ll n, m;
    cin >> n >> m;

if(n == 1) return cout<<(m1(binpow(2, m))), 0;

ll b = m1(binpow(2, m));

ll r = binpow(b, n);

cout << r;

}

