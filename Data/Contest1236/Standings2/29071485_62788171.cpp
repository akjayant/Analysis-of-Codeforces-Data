#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll N, M;

ll Pow(ll a, ll b) {
	if(b == 0) return 1;
	if(b == 1) return a;
	ll t = Pow(a, b/2);
	t = (t * t) % MOD;
	if(b % 2) return (t * a) % MOD;
	return t;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	ll ans = 1;
	ll t = Pow(2, M) - 1;
	if(t < 0) t += MOD;
	cout << Pow(t, N);
}