//ѹ�пδ�
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){int sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
int R(){char ccc=getchar();while(ccc<'0'||ccc>'9') ccc=getchar();return ccc-'0';}
void solve()
{
	int a=read(),b=read(),c=read();
	int ans=0;
	while(c>=2&&b>=1) ans+=3,c-=2,b-=1;
	while(b>=2&&a>=1) ans+=3,b-=2,a-=1;
	printf("%d\n",ans);
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
