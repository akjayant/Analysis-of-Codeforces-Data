//压行课次
#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const int mod=1e9+7;
const int MAXN=1e5+10;
int n,m,a[MAXN],book[MAXN],ans=1,f[MAXN];
char c[MAXN];
inline int read(){int sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
inline char R(){char ccc=getchar();while(ccc<'A'||ccc>'Z') ccc=getchar();return ccc;}
void solve()
{
	f[1]=1;f[2]=2;
	for(int i=3;i<MAXN;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	scanf("%s",c+1);
	int len=strlen(c+1);
	for(int i=1;i<=len;)
	{
//		printf("i=%d\n",i);
		if(c[i]=='w'||c[i]=='m') ans=0;
		if(c[i]!='n'&&c[i]!='u')
		{
			i++;
			continue;
		}
		int j=i;
		while(j<=len&&c[j]==c[i]) j++;
		int k=j-i;
//		printf("%d \n",k);
		ans=1ll*ans*f[k]%mod;
		i=j;
	}
	printf("%d\n",ans);
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