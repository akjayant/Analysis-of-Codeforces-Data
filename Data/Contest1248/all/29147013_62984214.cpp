//ѹ�пδ�
#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const int MAXN=1e5+10;
int n,a[MAXN];
inline int read(){int sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
void solve()
{
	n=read();
	int A=0,B=0;
	for(int i=1;i<=n;i++) a[i]=read(),B+=a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n/2;i++)
		A+=a[i],B-=a[i];
	printf("%lld\n",1ll*A*A+1ll*B*B);
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
