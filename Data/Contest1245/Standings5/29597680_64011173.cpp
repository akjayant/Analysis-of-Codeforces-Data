#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define rnt register int
using namespace std;
inline void read(int &x)
{
	char c;
	while(!isdigit(c=getchar()));x=c-'0';
	while(isdigit(c=getchar()))
		x=(x<<3)+(x<<1)+c-'0';
}
char s[110];
int T,n,cnt;
int a[4],ans[110];
int main()
{
	read(T);
	for(;T;--T)
	{
		read(n);memset(ans,0,sizeof(ans));
		read(a[1]),read(a[2]),read(a[3]);//RPS
		scanf("%s",s);cnt=0;
		for(rnt i=0;s[i];i=-~i)
		{
			if(s[i]=='S'&&a[1]) --a[1],++cnt,ans[i]=1;
			if(s[i]=='R'&&a[2]) --a[2],++cnt,ans[i]=2;
			if(s[i]=='P'&&a[3]) --a[3],++cnt,ans[i]=3;
		}
		if(cnt>=n/2+n%2)
		{
			puts("YES");
			for(rnt i=0;s[i];i=-~i)
			{
				if(!ans[i])
					for(rnt j=1;j<=3;j=-~j)
						if(a[j])
						{
							--a[j];
							ans[i]=j;
							break;
						}
				if(ans[i]==1) putchar('R');
				if(ans[i]==2) putchar('P');
				if(ans[i]==3) putchar('S');
			}puts("");
		}
		else puts("NO");
	}
	return 0;
}