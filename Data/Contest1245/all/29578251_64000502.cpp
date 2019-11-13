//压行课次
#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const int MAXN=1e2+10;
int n,m,a[MAXN],book[MAXN];
char c[MAXN],ans[MAXN];
inline int read(){int sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
inline char R(){char ccc=getchar();while(ccc<'A'||ccc>'Z') ccc=getchar();return ccc;}
void solve()
{
	n=read();
	memset(book,0,sizeof(book));
	int A=read(),B=read(),C=read(),cnt=0;
	for(int i=1;i<=n;i++)
	{
		c[i]=R();
		if(c[i]=='R'&&B)
		{
			cnt++;
			book[i]=true;
			ans[i]='P';
			B--;
		}
		else if(c[i]=='P'&&C)
		{
			cnt++;
			book[i]=true;
			ans[i]='S';
			C--;
		}
		else if(c[i]=='S'&&A)
		{
			cnt++;
			book[i]=true;
			ans[i]='R';
			A--;
		}
	}
	for(int i=1;i<=n;i++)
		if(!book[i])
		{
			if(A) ans[i]='R',A--;
			else if(B) ans[i]='P',B--;
			else ans[i]='S',C--;
		}
	if((n+1)/2<=cnt)
	{
		printf("YES\n");
		for(int i=1;i<=n;i++)
			printf("%c",ans[i]);
		printf("\n");
	}
	else printf("NO\n");
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