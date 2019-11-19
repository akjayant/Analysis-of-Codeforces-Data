#include <bits/stdc++.h>

#pragma GCC optimize("03")

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define pow2(x) ((x) * (x))
#define rev reverse
#define in insert
#define sz(x) (int)x.size()


using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, pii> piii;

const ll inf = (ll)1e18;
const int MAXN = (int)1e5;
const ll mod = (ll)1e9 + 7;

const double pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 100500;

int main() {
	ll n, m;
	scanf("%I64d%I64d", &n, &m);

	vector<ll> pref(max(n, m) + 1);//dp(max(n, m)), pref(max(n, m) + 1);
	pref[0] = 2;
	pref[1] = 2;
	
	for (int i = 2; i < max(n, m) + 1; i++) {
		pref[i] = (pref[i - 1] + pref[i - 2]) % mod;
	}


	/*cout << "oref : ";
	for (int i = 0; i < max(n, m) + 1; i++)
		cout << pref[i] << " ";
	cout << endl;
	
	dp[ 0 ] = 2;
	dp[ 1 ] = 4;

	for(int i = 2; i < max(n, m); i++) {
		dp[ i ] = dp[ i - 1 ] + dp[ i - 2 ];
	}
	*/
	//cout << "dp = " << dp[n - 1]  << "  +  " << pref[m] << endl;
	cout << (pref[n] + pref[m] - 2) % mod;
	//printf("%I64d\n", 2 * m + 2 * n);
}