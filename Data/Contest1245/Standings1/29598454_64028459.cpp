#include<bits/stdc++.h>
#define FOR(i, x, y) for(int i = (x), i##END = (y); i <= i##END; ++i)
#define DOR(i, x, y) for(int i = (x), i##END = (y); i >= i##END; --i)
template<typename T, typename _T> inline bool chk_min(T &x, const _T y) {return y < x ? x = y, 1 : 0;}
template<typename T, typename _T> inline bool chk_max(T &x, const _T y) {return x < y ? x = y, 1 : 0;}
typedef long long ll;
ll pw3[40];
inline ll erase(ll a, ll b) {return (a | b) ^ b;}
inline int cnt(ll a, int l, int r)
{
	int res = 0;
	FOR(i, l, r) res += (a >> i & 1);
	return res;
}

ll solve(ll a, ll b)
{
	a++, b++;
	if(a <= 0 || b <= 0) return 0ll;
	ll res = 0;
	DOR(i, 30, 0) if(a >> i & 1)
	{
		DOR(j, 30, 0) if(b >> j & 1)
		{
			ll v = 1;
			if(i > j)
			{
				if(erase(a, (1 << (i + 1)) - 1) & erase(b, (1 << (i + 1)) - 1))
					continue;
				v *= 1ll << ((i - j - 1) - cnt(b, j + 1, i - 1));
				v *= 2 * pw3[j];
			}
			else if(i == j)
			{
				if(erase(a, (1 << (i + 1)) - 1) & erase(b, (1 << (i + 1)) - 1))
					continue;
				v *= pw3[j];
			}
			else if(i < j)
			{
				if(erase(a, (1 << (j + 1)) - 1) & erase(b, (1 << (j + 1)) - 1))
					continue;
				v *= 1ll << ((j - i - 1) - cnt(a, i + 1, j - 1));
				v *= 2 * pw3[i];
			}
			res += v;
		}
	}
	return res;
}

int main()
{
	pw3[0] = 1;
	FOR(i, 1, 31) pw3[i] = pw3[i - 1] * 3;
	int T;
	scanf("%d", &T);
	while(T--)
	{
		ll l, r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", solve(r, r) - 2 * solve(l - 1, r) + solve(l - 1, l - 1));
	}
	return 0;
}
