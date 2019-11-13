//ѹ�пδ�
#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const int MAXN=2e5+10;
int n,m,a[MAXN];
char c[MAXN];
inline int read(){int sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
inline int R(){char ccc=getchar();while(ccc<'0'||ccc>'9') ccc=getchar();return ccc-'0';}
void solve()
{
	n=read();m=read();
	if(__gcd(n,m)==1) printf("Finite\n");
	else printf("Infinite\n");
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
