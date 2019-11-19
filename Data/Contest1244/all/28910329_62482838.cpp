#pragma GCC optimize("2,Ofast,inline")
#pragma GCC diagnostic error "-std=c++11"
#include<bits/stdc++.h>
#define LL long long
#define int LL
#define P pair<LL,LL>
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
LL n,k,x;
map<LL,LL> Map;
deque<P> de;
signed main()
{
	read(n),read(k);
	for(int i=1;i<=n;i++) read(x),Map[x]++;
	for(auto v:Map)
		de.push_back(P(v.fi,v.se));
	while(k>0)
	{
		if(de.size()==1) break;
		P front=de.front();
		P back=de.back();
		if(front.se<back.se)
		{
			de.pop_front();
			P now=de.front();
			LL zz=(now.fi-front.fi)*front.se;
			if(zz>k)
			{
				LL steps=k/front.se;
				front.fi+=steps;
				de.push_front(front);
				break;
			}
			else 
			{
				k-=zz;
				de.front().se+=front.se;
			}
		}
		else 
		{
			de.pop_back();
			P now=de.back();
			LL zz=(back.fi-now.fi)*back.se;
			if(zz>k)
			{
				LL steps=k/back.se;
				back.fi-=steps;
				de.push_back(back);
				break;
			}
			else 
			{
				k-=zz;
				de.back().se+=back.se;
			}
		}
	}
	printf("%lld\n",de.back().fi-de.front().fi);
	return 0;
}
