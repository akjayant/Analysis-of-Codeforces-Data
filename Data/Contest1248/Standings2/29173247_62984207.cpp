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
int a[100050];
signed main(void)
{
	int n;cin>>n;
	for(int i=1;i<=n;++i)
		rd(a[i]);
	sort(a+1,a+n+1);
	reg int i=1;
	reg int w=0,h=0;
	for(i=1;i<=(n>>1);++i)
		w+=a[i];
	for(;i<=n;++i)
		h+=a[i];
	cout<<w*w+h*h<<endl;
	return 0;
}

