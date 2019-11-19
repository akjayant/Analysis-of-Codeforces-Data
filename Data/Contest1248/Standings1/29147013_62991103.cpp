//ѹ�пδ�
#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const int MAXN=1e5+10;
LL n,m,s[MAXN],mod=1e9+7;
inline LL read(){LL sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
void solve()
{
	n=read();m=read();
	if(n>m) swap(n,m);
	s[1]=2;s[2]=4;
	for(int i=3;i<=m;i++) s[i]=(s[i-1]+s[i-2])%mod;
	printf("%lld\n",((s[n]+s[m]-s[1])%mod+mod)%mod);
}
int main()
{
//	freopen("123.in","r",stdin);
//	freopen("123.out","w",stdout);
	int T=1;
	while(T--)
		solve();
	return 0;
}
