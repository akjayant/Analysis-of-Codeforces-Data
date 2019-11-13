#include<bits/stdc++.h>
#define FOR(i, x, y) for(int i = (x), i##END = (y); i <= i##END; ++i)
#define DOR(i, x, y) for(int i = (x), i##END = (y); i >= i##END; --i)
template<typename T, typename _T> inline bool chk_min(T &x, const _T y) {return y < x ? x = y, 1 : 0;}
template<typename T, typename _T> inline bool chk_max(T &x, const _T y) {return x < y ? x = y, 1 : 0;}
typedef long long ll;
int gcd(int a, int b) {return b ? gcd(b, a% b) : a;}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		puts(gcd(x, y) == 1? "Finite" : "Infinite");
	}
	return 0;
}
