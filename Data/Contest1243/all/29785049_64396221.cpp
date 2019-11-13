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



#define fi(a,b) for (int i=a;i<b;i++)
#define fj(a,b) for (int j=a;j<b;j++)
#define fk(a,b) for (int k=a;k<b;k++)
#define fi1(a,b) for (int i=a-1;i>=b;i--)
#define fj1(a,b) for (int j=a-1;j>=b;j--)


using namespace std;
typedef long long ll;
typedef char ch;
typedef string str;
typedef vector <long long> vl;
typedef vector <int> vi;
typedef vector<vector<long long>> vvl;
typedef vector<vector<int>> vvi;
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<pair<ll, ll>>> vvpll;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<char> vch;
typedef vector<vector<char>> vvch;
typedef vector<string> vs;
typedef map<ll, ll> mll;
typedef map<int, int> mii;
typedef map<ll, ch> mlch;
typedef map<int, ch> mich;
typedef map<ch, int> mchi;
typedef map<ch, ll> mchl;
typedef pair<int, int> pii;
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

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

bool is_prime(int n) {
	int bound = sqrt(n);
	int d = 2;
	while (d <= bound && n % d != 0)
		++d;
	return d * d > n;
}

void sort(vl &a) {
	sort(a.begin(), a.end());
}

void sort(vi &a) {
	sort(a.begin(), a.end());
}

void sort(vpll &a) {
	sort(a.begin(), a.end());
}

void sort(vpii &a) {
	sort(a.begin(), a.end());
}

void rev(vl &a) {
	reverse(a.begin(), a.end());
}

void rev(vi &a) {
	reverse(a.begin(), a.end());
}

void rev(vpll &a) {
	reverse(a.begin(), a.end());
}

void rev(vpii &a) {
	reverse(a.begin(), a.end());
}

void rev(string &a) {
	reverse(a.begin(), a.end());
}

const int MOD = 1000000007;
const int INF = 1000000050;
const int MAXN = 100010;
const double EPS = 1e-9;




int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	const int MAXN = 10000;
#endif 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> k;
	fi(0, k) {
		int n;
		str a, b;
		cin >> n >> a >> b;
		int dif = 0;
		char a1, a2, b1, b2;
		fj(0, n) {
			if (a[j] != b[j]) {
				++dif;
				if (dif == 1) {
					a1 = a[j];
					b1 = b[j];
				}
				else if (dif == 2) {
					a2 = a[j];
					b2 = b[j];
				}
			}
		}
		if (dif == 1 || dif > 2)
			cout << "No" << '\n';
		else if (dif == 0)
			cout << "Yes" << '\n';
		else {
			if (b1 == b2 && a1 == a2)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
}