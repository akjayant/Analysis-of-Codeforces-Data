// #define MODULAR_ARITHMETIC
// #define INDEXED_SET

#pragma region
#ifndef LOCAL_DEBUG
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>
#include <iomanip>
#include <set>
#define pb push_back
#define mp make_pair
#define f(i, a, b) for (int i = a; i < b; i++)
#define revf(i, b, a) for (int i = b; i >= a; i--)
#define srt(v) sort(v.begin(), v.end())
#define revsrt(v) sort(v.rbegin(), v.rend())
using namespace std;

#ifdef MODULAR_ARITHMETIC
template <typename T>
T add(T a, T b, T c)
{
	T res = a + b;
	return (res >= c ? res - c : res);
}
template <typename T>
T mod_neg(T a, T b, T c)
{
	T res;
	if (abs(a - b) < c)
		res = a - b;
	else
		res = (a - b) % c;
	return (res < 0 ? res + c : res);
}
template <typename T>
T mul(T a, T b, T c)
{
	long res = (long long)a * b;
	return (res >= c ? res % c : res);
}

template <typename T>
T mulmod(T a, T b, T m)
{
	long long q = (long long)(((long double)a * (long double)b) / (long double)m);
	long long r = a * b - q * m;
	if (r > m)
		r %= m;
	if (r < 0)
		r += m;
	return r;
}
template <typename T>
T expo(T e, T n)
{
	T x = 1, p = e;
	while (n)
	{
		if (n & 1)
			x = x * p;
		p = p * p;
		n >>= 1;
	}
	return x;
}
template <typename T>
T power(T e, T n, T m)
{
	T x = 1, p = e;
	while (n)
	{
		if (n & 1)
			x = mul(x, p, m);
		p = mul(p, p, m);
		n >>= 1;
	}
	return x;
}
template <typename T>
T extended_euclid(T a, T b, T &x, T &y)
{
	T xx = 0, yy = 1;
	y = 0;
	x = 1;
	while (b)
	{
		T q = a / b, t = b;
		b = a % b;
		a = t;
		t = xx;
		xx = x - q * xx;
		x = t;
		t = yy;
		yy = y - q * yy;
		y = t;
	}
	return a;
}
template <typename T>
T mod_inverse(T a, T n)
{
	T x, y, z = 0;
	T d = extended_euclid(a, n, x, y);
	return (d > 1 ? -1 : mod_neg(x, z, n));
}
#endif

#ifdef INDEXED_SET
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#endif

#define sp << ' ' <<
#define endl '\n'
#define precision(x) cout << fixed << setprecision(x);
#define fio                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);

template <typename T>
ostream &operator<<(ostream &os, vector<pair<T, T>> &v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
		os << v[i].first sp v[i].second << "\n";
	return os;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
		os << v[i] << " ";
	os << endl;
	return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
		is >> v[i];
	return is;
}

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
#pragma endregion

ll mod = 1e9 + 7;
const int MAX = 5 * 1e5 + 5;

vvi adjacent;
vi path;

void dfs(int vertex, int parent)
{
	path.pb(vertex);
	for (auto child : adjacent[vertex])
	{
		if (child != parent)
		{
			dfs(child, vertex);
		}
	}
}

void solvetestcase()
{
	int n;
	cin >> n;
	vvi v(3, vi(n));
	adjacent.resize(n);
	cin >> v[0] >> v[1] >> v[2];
	f(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adjacent[u].pb(v);
		adjacent[v].pb(u);
	}
	int end = -1;
	f(i, 0, n)
	{
		if (adjacent[i].size() > 2)
		{
			cout << "-1\n";
			return;
		}
		if (adjacent[i].size() == 1)
		{
			end = i;
		}
	}
	assert(end != -1);
	dfs(end, -1);
	// cout << path;

	vi color1 = {0, 1, 2}, color2 = {2, 1, 0};

	ll ans = __LONG_LONG_MAX__;
	f(start_col, 0, 3)
	{
		ll sum = 0;
		int col = start_col;
		f(i, 0, n)
		{
			sum += v[color1[col % 3]][path[i]];
			// cout << col % 3 << " ";
			col++;
		}
		// cout << endl;
		// cout << sum << endl;
		ans = min(ans, sum);
	}
	f(start_col, 0, 3)
	{
		ll sum = 0;
		int col = start_col;
		f(i, 0, n)
		{
			sum += v[color2[col % 3]][path[i]];
			// cout << col % 3 << " ";
			col++;
		}
		// cout << endl;
		// cout << sum << endl;
		ans = min(ans, sum);
	}
	cout << ans << endl;
	vi answer(n);
	f(start_col, 0, 3)
	{
		ll sum = 0;
		int col = start_col;
		f(i, 0, n)
		{
			sum += v[color1[col % 3]][path[i]];
			col++;
		}
		if (ans == sum)
		{
			int col = start_col;
			f(i, 0, n)
			{
				answer[path[i]] = color1[col % 3] + 1;
				col++;
			}
			cout << answer;
			return;
		}
	}
	f(start_col, 0, 3)
	{
		ll sum = 0;
		int col = start_col;
		f(i, 0, n)
		{
			sum += v[color2[col % 3]][path[i]];
			col++;
		}
		if (ans == sum)
		{
			int col = start_col;
			f(i, 0, n)
			{
				answer[path[i]] = color2[col % 3] + 1;
				col++;
			}
			cout << answer;
			return;
		}
	}
}

int main()
{
	fio;
	int t = 1;

	// UNCOMMENT FOR TESTCASES	\
	cin >> t;

	f(T, 1, t + 1)
	{
		// UNCOMMENT FOR CODEJAM,HACKERCUP	\
		cout << "Case #" << T << ": ";
		solvetestcase();
	}
};

/*
    AUTHOR:     KUNAL TAWATIA
    EDUCATION:  INDIAN INSTITUTE OF TECHNOLOGY, JODHPUR
*/