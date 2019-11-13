#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N ((int)1e5 + 1)
#define forn(i,x,y) for(int i = int(x); i<int(y); i++)
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(V) V.begin(), V.end()

template<typename T> ostream &operator<<(ostream &out, const pair<T, T> &P){ out << P.first << ' ' << P.second; return out; }
template<typename T> ostream &operator<<(ostream &out, const vector<T> &V){ for(int i = 0; i<V.size(); ++i) out << V[i] << ' '; return out; }
template<typename T> istream &operator>>(istream &in, vector<T> &V){ for(T &i : V) in >> i; return in; }
template<typename T> istream &operator>>(istream &in, pair<T,T> &P){ in >> P.first >> P.second; return in; }

const ll mod = 1e9 + 7;

long long powmod(long long base, long long exp, long long modulus) {
	base %= modulus;
	long long result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}
  	return result;
}



int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    ll n, m; cin >> n >> m;

    ll ans = powmod(2, m, mod);
    ans--;
    if(ans < mod) ans += mod;

    ans = powmod(ans, n, mod);

    cout << ans << '\n';

    return 0;
}

/* don't forget to check:
   int overflow
   min/max cases (n = 1)
   printing index of sorted array
   limits for ans (start with inf)
 */
