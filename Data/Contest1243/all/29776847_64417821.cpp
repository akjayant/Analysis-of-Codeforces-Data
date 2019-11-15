// #define MODULAR_ARITHMETIC
// #define INDEXED_SET

#pragma region
#ifndef LOCAL_DEBUG
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <iomanip>
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

void solvetestcase()
{
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int cnt[26][2];
	f(i, 0, 26)
		f(j, 0, 2)
			cnt[i][j] = 0;
	f(i, 0, n)
	{
		cnt[s[i] - 'a'][0]++;
		cnt[t[i] - 'a'][1]++;
	}
	bool flag = true;
	f(i, 0, 26) if (abs(cnt[i][0] - cnt[i][1]) % 2 != 0)
		flag = false;
	if (flag == false)
	{
		cout << "No\n";
		return;
	}
	vpii ans;
	f(i, 0, n)
	{
		char ch = s[i];
		if (s[i] != t[i])
		{

			f(j, i + 1, n)
			{
				if (s[j] == ch)
				{
					ans.pb({j + 1, i + 1});
					swap(t[i], s[j]);
					break;
				}
			}
		}
		if (s[i] != t[i])
		{

			f(j, i + 1, n) if (t[j] == ch)
			{

				ans.pb({j + 1, j + 1});
				swap(s[j], t[j]);
				ans.pb({j + 1, i + 1});
				swap(s[j], t[i]);
				break;
			}
		}
	}
	cout << "Yes\n"
		 << ans.size() << "\n";
	cout << ans;
}

int main()
{
	fio;
	int t = 1;

	// UNCOMMENT FOR TESTCASES
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