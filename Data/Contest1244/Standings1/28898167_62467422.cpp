#include<bits/stdc++.h>
#define FOR(i, x, y) for(int i = (x), i##END = (y); i <= i##END; ++i)
#define DOR(i, x, y) for(int i = (x), i##END = (y); i >= i##END; --i)
template<typename T, typename _T> inline bool chk_min(T &x, const _T y) {return y < x ? x = y, 1 : 0;}
template<typename T, typename _T> inline bool chk_max(T &x, const _T y) {return x < y ? x = y, 1 : 0;}
typedef long long ll;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		bool flg=0;
		FOR(i,0,k)
		{
			if(c*i>=a&&d*(k-i)>=b)
			{
				printf("%d %d\n",i,k-i);
				flg=1;
				break;
			}
		}
		if(!flg)puts("-1");
	}
	return 0;
}
