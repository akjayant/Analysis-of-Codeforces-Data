//ѹ�пδ�
#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const int MAXN=1e5+10;
int p[MAXN],q[MAXN];
inline int read(){int sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
void solve()
{
	int cnta=0,cntb=0;
	LL ans=0;
	int n=read();
	for(int i=1;i<=n;i++)
	{
		p[i]=read();
		if(p[i]%2==0) cntb++;
		else cnta++;
	}
	int m=read();
	for(int i=1;i<=m;i++) 
	{
		q[i]=read();
		if(q[i]%2==0) ans+=cntb;
		else ans+=cnta;
	}
	printf("%lld\n",ans);
}
int main()
{
//	freopen("123.in","r",stdin);
//	freopen("123.out","w",stdout);
	int T=read();
	while(T--)
		solve();
	return 0;
}
