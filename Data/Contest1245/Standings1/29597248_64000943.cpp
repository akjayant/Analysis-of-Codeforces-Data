#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
}
int T,a,b,c;
char s[233],ans[233];
int main()
{
	T=read();
	while(T--)
	{
		int n=read(),cnt=0; a=read(),b=read(),c=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++) ans[i]='#';
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='P'&&c) cnt++,c--,ans[i]='S';
			if(s[i]=='S'&&a) cnt++,a--,ans[i]='R';
			if(s[i]=='R'&&b) cnt++,b--,ans[i]='P';
		}
		for(int i=1;i<=n;i++)
			if(ans[i]=='#')
			{
				if(a) ans[i]='R',a--;
				else if(b) ans[i]='P',b--;
				else if(c) ans[i]='S',c--;
			}
		if(cnt>=(n+1)/2)
		{
			printf("YES\n");
			for(int i=1;i<=n;i++)
				printf("%c",ans[i]);
			puts("");
		}
		else printf("NO\n");
	}
	return 0;
}