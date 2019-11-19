// This code writed by chtholly_micromaker(MicroMaker)
#include <bits/stdc++.h>
#define reg register
#define int long long
using namespace std;
const int p=1e9+7;
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
int f[100050];
signed main(void)
{
	f[1]=1;f[2]=2;
	for(int i=3;i<=100000;++i)
		f[i]=(f[i-1]+f[i-2])%p;
	int n,m;
	cin>>n>>m;
	cout<<((f[n]+f[m]-1)*2ll)%p<<endl;
	return 0;
}

