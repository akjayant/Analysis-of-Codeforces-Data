//ѹ�пδ�
#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const int MAXN=1e3+10;
char s[MAXN];
int read(){int sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
template<typename T> inline void write(T x){if(!x) return;write(x/10);putchar((x%10)+'0');}
template<typename T> inline void wri(T x){write(x);puts("");}
void solve()
{
	int len=read(),x=1,y=len,ans=0;
	scanf("%s",s+1);
	for(int i=1;i<=len;i++)
		if(s[i]=='1') x=max(x,i),y=min(y,i);
	if(len==1&&s[1]=='1') ans=2;
	else if(x==1&&y==len) ans=len;
	else ans=max(2*x,2*(len-y+1));
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
