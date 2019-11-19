//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
#define N 2000
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
char ch[N];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),ans=n; scanf("%s",ch+1);
		for(int i=1;i<=n;i++)	if(ch[i]=='1')	ans++;
		int tmp=0;
		for(int i=1;i<=n;i++)	if(ch[i]=='1')
			tmp=max(tmp,max(i<<1,n-i+1<<1));
		printf("%d\n",max(tmp,ans));
	}
	return 0;
}
