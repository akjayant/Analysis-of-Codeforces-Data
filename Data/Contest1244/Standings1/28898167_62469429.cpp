#include<bits/stdc++.h>
#define FOR(i, x, y) for(int i = (x), i##END = (y); i <= i##END; ++i)
#define DOR(i, x, y) for(int i = (x), i##END = (y); i >= i##END; --i)
template<typename T, typename _T> inline bool chk_min(T &x, const _T y) {return y < x ? x = y, 1 : 0;}
template<typename T, typename _T> inline bool chk_max(T &x, const _T y) {return x < y ? x = y, 1 : 0;}
typedef long long ll;
const int N=1e5+5;
char str[N];
int n;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",str + 1);
		int t = 1e9;
		FOR(i, 1, n)if(str[i] == '1')
		{
			chk_min(t, std::min(i, n - i +1));
		}
		if(t == 1e9) printf("%d\n", n);
		else printf("%d\n",2 * (n - (t - 1)));
	}
	return 0;
}
