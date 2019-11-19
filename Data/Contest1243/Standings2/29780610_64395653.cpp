#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include <bitset>
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int maxN = 1e6 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll sq(ll x) {return (x * x) % MOD;}
ll modP(ll a, ll b) {return (!b ? 1 : (sq(modP(a, b / 2)) * (b % 2 ? a : 1)) % MOD);}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	if (n == 1) return cout << 1 << endl, 0;
	ll p = 0, m = n;
	for (ll i = 2; i <= min(m, 1ll * maxN); i++){
		if (n % i == 0){
			if (p) return cout << 1 << endl, 0;
			p = i;
			while (n % p == 0) n /= p;
		}
	}
	if (n != 1){
		if (p) return cout << 1 << endl, 0;
		p = n;
	}
	cout << p << endl;
	return 0;
}
 

