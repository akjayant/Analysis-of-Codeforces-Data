#include <bits/stdc++.h>
using namespace std;

#pragma region
#define IOS                               \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
	const char *comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif
#define int long long int
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()
#define N 500009
#define M 1000009
#define mod 1000000007
inline int add(int a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}
inline int sub(int a, int b)
{
	a -= b;
	if (a < 0)
		a += mod;
	return a;
}
inline int mul(int a, int b) { return (int)((long long)a * b % mod); }
inline int binpow(int a, int b)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b /= 2;
	}
	return res;
}
inline int inv(int a) { return binpow(a, mod - 2); }
int geo_sum(int start, int ratio, int terms)
{
	if (ratio == 1)
	{
		return mul(start, terms);
	}
	int up = mul(start, sub(1, binpow(ratio, terms)));
	int down = sub(1, ratio);
	return mul(up, inv(down));
}
#pragma endregion

int ans;
int n, m;

void pre()
{
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	ans = binpow(2, m);
	ans = sub(ans, 1);
	ans = binpow(ans, n);
	cout << ans << endl;
}