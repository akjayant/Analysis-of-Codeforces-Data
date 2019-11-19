//ѹ�пδ�
#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
int read(){int sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
template<typename T> inline void write(T x){if(!x) return;write(x/10);putchar((x%10)+'0');}
template<typename T> inline void wri(T x){write(x);puts("");}
void solve()
{
	int a=read(),b=read(),c=read(),d=read(),k=read();
	int ansa=(a/c),ansb=(b/d);
	if(a%c!=0) ansa++;
	if(b%d!=0) ansb++;
	if(ansa+ansb>k) printf("-1\n");
	else printf("%d %d\n",ansa,ansb);
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
