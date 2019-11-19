#pragma GCC optimize("2,Ofast,inline")
#pragma GCC diagnostic error "-std=c++11"
#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
#define fi first
#define se second
const LL N=1e5+10;
const LL mod=1e9+7;
const LL inf=0x3f3f3f;
const double eps=1e-9;
using namespace std;
template<typename tp> inline void read(tp &x)
{
    x=0;char c=getchar();
    bool f=0; for(; c<'0'||c>'9'; f|=(c=='-'),c = getchar());
    for(; c>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0',c = getchar());
    if(f) x=-x;
}
int T,a,b,c,d,e;
signed main()
{
	read(T);
	while(T--)
	{
		read(a),read(b),read(c),read(d),read(e);
		int x=(a/c)+(a%c==0?0:1);
		int y=(b/d)+(b%d==0?0:1);
		if(x+y>e) puts("-1");
		else printf("%d %d\n",x,y);
	}
	return 0;
}
