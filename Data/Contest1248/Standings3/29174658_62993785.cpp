/*

Sviatoslav Bidzilia 2019
CF: anakib1

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <map>
#include <chrono>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <ctime>
#include <stack>
#include <set>
#include <list>
#include <deque>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdarg.h>
#include <utility>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unisgned long long
#define ld long double
#define all(a) a.begin(), a.end()
#define SORT(a) sort(all(a))
#define pii pair<int, int>
#define tii triple<int, int, int>
#define e 1e-7
#define PI acos(-1)
#define inf 1e17
#define vi vector<int>
#define F first
#define S second
#define rng(x) for(int _ = 0; _ < (x); _++)
#define rngi(i, x) for(int i = 0; i < (x); i++)
#define rngsi(s, i, x) for(int i = (s); i <(x); i++)
#define int long long

template<typename A, typename B, typename C>
struct triple
{
	A X;
	B Y;
	C Z;
	triple(A a = 0, B b = 0, C c = 0) :X(a), Y(b), Z(c) {}
};
template<typename A, typename B, typename C>
triple<A, B, C> make_triple(A a = 0, B b = 0, C c = 0)
{
	return triple<A, B, C>(a, b, c);
}
template<typename A, typename B, typename C>
bool operator<(const triple<A, B, C>& a, const triple<A, B, C>& b)
{
	if (a.X != b.X)
		return a.X < b.X;
	if (a.Y != b.Y)
		return a.Y < b.Y;
	return a.Z < b.Z;
}
template<typename T, typename SS>
ostream& operator<<(ostream& ofs, const pair<T, SS>& p)
{
	ofs << "( " << p.F << " , " << p.S << " )";
	return ofs;
}
template<typename T>
void print(T a)
{
	for (auto i : a)
		cout << i << ' ';
	cout << '\n';
}
template<typename T>
T max(T a, T b, T c)
{
	return max(a, max(b, c));
}
template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}
struct custom_hash
{
	static uint64_t splitmix64(uint64_t x)
	{
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const
	{
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
#define mod (int)(1e9 + 7)
signed main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	srand(time(NULL));
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	/*int n, m;
	for(n = 4; n < 5; n++)
		for (m = 6; m <= 6; m++)
		{
			int ans = 0;
			for (int mask = 0; mask < (1 << (n * m)); mask++)
			{
				vector<vi> now(n, vi(m));
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						now[i][j] = (mask >> (m * i + j)) & 1;
				bool ok = 1;
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
					{
						int cnt = 0;
						if (i && now[i - 1][j] == now[i][j])
							cnt++;
						if (j && now[i][j - 1] == now[i][j])
							cnt++;
						if (i < n - 1 && now[i + 1][j] == now[i][j])
							cnt++;
						if (j < m - 1 && now[i][j + 1] == now[i][j])
							cnt++;
						if (cnt > 1)
							ok = 0;
					}
				/*if (ok)
				{
					cout << '\n';
					for (auto i : now)
						print(i);
					cout << '\n';
				}
				ans += ok;
			}
			anss[n][m] = ans;
		}
	for (auto i : anss)
		print(i);*/
	int n, m;
	cin >> n >> m;
	if (n == m && m == 1)
		return cout << "2\n", 0;
	if (n < m)
		swap(n, m);
	vi f(n + 1);
	vi l(n + 1);
	f[1] = f[2] = 1;
	l[1] = 1;
	l[2] = 3;
	vi r(n + 1);
	r[1] = f[1] + l[1];
	r[2] = f[2] + l[2];
	for (int i = 3; i <= n; i++)
	{
		f[i] = (f[i - 1] + f[i - 2]) % mod;
		l[i] = (l[i - 1] + l[i - 2]) % mod;
		r[i] = (f[i] + l[i]) % mod;
	}
	int now = (l[n] + f[n]) % mod;
	if (m == 1)
		return cout << now << '\n', 0;
	//cout << now << '\n';
	now += 2;
	for (int i = 1; i < m - 1; i++)
		now = (now + r[i]) % mod;
	cout << now << '\n';
}