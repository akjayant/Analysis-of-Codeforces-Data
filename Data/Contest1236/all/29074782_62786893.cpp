#include <bits/stdc++.h>
using namespace std;
#define IO                 \
	ios::sync_with_stdio(0); \
cin.tie(0);              \
cout.tie(0);
#define forn(i, n) for (int i = 0; i < n; i++)
#define forse(i, s, e) for (int i = s; i < e; i++)
#define pb push_back
#define pf push_front
#define rb pop_back
#define rf pop_front
#define mp make_pair
#define all(vec) vec.begin(), vec.end()
#define getcurrtime() \
	cerr << "Time = " << ((double)clock() / CLOCKS_PER_SEC) << endl

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> Matrix;
const int sqr = 500;
ll P = 1e9 + 7;
const int arrn = 1e5 + 3;
const int arrn2 = 5e3 + 3;

ll binpow(ll a,ll n,ll p){
		ll ret = 1;
		while(n){
			if(n&1) ret *= a;
			a *= a;
			a %= p;
			ret %= p;
			n /= 2;
		}
		return ret;
}
void solve() {
	ll n,m;
	cin >> n >> m;
	ll tem=binpow(2,m,P)-1;
	ll out=binpow(tem,n,P);
	cout << out;
}
int main() {
  IO;
  int T;
	T=1;
  while (T--) {
    solve();
  }
  return 0;
}
