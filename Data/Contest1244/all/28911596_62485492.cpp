/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
//codeforces1244B_live
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define mp make_pair
#define pb push_back
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
void parseArray(ll* A,ll n){ for ( ll K = 0; K < n; K++){ cin >> A[K]; } }
//ll modInverse(ll a, ll b){ return 1<a ? b - modInverse(b%a,a)*b/a : 1; }
//ll gcd(ll a, ll b){ return b?gcd(b, a % b):a; }
//ll lcm(ll a, ll b){ return (a*b)/gcd(a, b); }
ld dist(ll x, ll y, ll a, ll b){ return sqrt((x - a)*(x - a) + (y - b)*(y - b)); }
void debug(ll* a, ll n) { for ( int k = 0; k < n; k++ ){ cout << a[k] << " ";} cerr << "\n"; }

ll gcdExtended(ll a, ll b, ll *x, ll *y)  {  
	if (a == 0)  {  
		*x = 0;  
		*y = 1;  
		return b;  
	}  

	ll x1, y1; 
	ll gcd = gcdExtended(b%a, a, &x1, &y1);  
	*x = y1 - (b/a) * x1;  
	*y = x1;  
	return gcd;  
}   

ll modInv(ll a, ll b) {
	ll x, y;
	gcdExtended(a, b, &x, &y);
	return (x % b + b) % b;
}

int main() {
	FASTIO
	ll n, p, w, d; cin >> n >> p >> w >> d;
	ll x, y;
	ll g = gcdExtended(w, d, &x, &y);
	if (p % g) return cout << "-1\n", 0;
	w /= g; d /= g; p /= g;
	ll yy = ((p % w) * modInv(d, w)) % w;
	ll xx = (p - yy * d) / w;
	if (p < yy * d) return cout << "-1\n", 0;
	if ( xx + yy > n) return cout << "-1\n", 0;
	cout << xx << " " << yy << " " << n - yy - xx << endl;
	return 0;
}