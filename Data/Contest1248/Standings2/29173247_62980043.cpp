// This code writed by chtholly_micromaker(MicroMaker)
#include <bits/stdc++.h>
#define reg register
#define int long long
using namespace std;
template <class t> inline void rd(t &s)
{
	s=0;
	reg char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c))
		s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return;
}
inline void work()
{
	int n,m;
	reg int oddA=0,oddB=0,evenA=0,evenB=0,x;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		rd(x);
		if(x&1)
			++oddA;
		else
			++evenA;
	}
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		rd(x);
		if(x&1)
			++oddB;
		else
			++evenB;
	}
	cout<<oddA*oddB+evenA*evenB<<endl;
	return;
}
signed main(void)
{
	int t;cin>>t;
	while(t--)
		work();
	return 0;
}

