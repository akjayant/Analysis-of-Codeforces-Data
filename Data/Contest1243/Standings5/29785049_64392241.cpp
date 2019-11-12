#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <stack>
#include <deque>
#include <ctime>
#include <random>
#include <cassert>
#include <cmath>
#include <climits>
#include <queue>

//#pragma GCC optimize ("O3")



#define fi(a,b) for (long long i=a;i<b;i++)
#define fj(a,b) for (long long j=a;j<b;j++)
#define fk(a,b) for (long long k=a;k<b;k++)
#define fi1(a,b) for (long long i=a-1;i>=b;i--)
#define fj1(a,b) for (long long j=a-1;j>=b;j--)


using namespace std;
typedef long long ll;
typedef char ch;
typedef string str;
typedef vector <long long> vl;
typedef vector <long long> vi;
typedef vector<vector<long long>> vvl;
typedef vector<vector<long long>> vvi;
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<long long, long long>> vpii;
typedef vector<vector<pair<ll, ll>>> vvpll;
typedef vector<vector<pair<long long, long long>>> vvpii;
typedef vector<char> vch;
typedef vector<vector<char>> vvch;
typedef vector<string> vs;
typedef map<ll, ll> mll;
typedef map<long long, long long> mii;
typedef map<ll, ch> mlch;
typedef map<long long, ch> mich;
typedef map<ch, long long> mchi;
typedef map<ch, ll> mchl;
typedef pair<long long, long long> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;


long long powmod(long long a, long long b, long long mod) {
	if (b == 0 || a == 1)
		return mod == 1 ? 0 : 1;

	if (b % 2 == 0) {
		long long k = powmod(a, b / 2, mod);
		return (k * k) % mod;
	}
	else {
		long long k = powmod(a, b / 2, mod);
		return ((k * k) % mod * a) % mod;
	}
}

long long gcd(long long a, long long b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

bool is_prime(long long n) {
	long long bound = sqrt(n);
	long long d = 2;
	while (d <= bound && n % d != 0)
		++d;
	return d * d > n;
}



const long long MOD = 1000000007;
const long long INF = 1000000050;
const long long MAXN = 100010;
const double EPS = 1e-9;




signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	const long long MAXN = 10000;
#endif 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll k;
	cin >> k;
	fi(0, k) {
		ll n;
		cin >> n;
		vi a(n);
		fj(0, n)
			cin >> a[j];
		sort(a.rbegin(), a.rend());
		int ans = 0;
		fi(1, n + 1) {
			if (a[i - 1] < i)
				break;
			++ans;
		}
		cout << ans << '\n';

	}

}