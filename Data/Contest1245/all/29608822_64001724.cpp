#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		fh=-1,jp=getchar();
	while (jp>='0'&&jp<='9')
		out=out*10+jp-'0',jp=getchar();
	return out*fh;
}
const int MAXN=128;
char buf[MAXN],ans[MAXN];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),r=read(),p=read(),s=read();
		int x=(n+1)>>1,R=0,P=0,S=0;
		scanf("%s",buf);
		for(int i=0;i<n;++i)
		{
			if(buf[i]=='R')
				++R; 
			else if(buf[i]=='P')
				++P;				
			else
				++S;				
		}
		x-=min(R,p)+min(P,s)+min(S,r);
		if(x>0)
			puts("NO");
		else
		{
			puts("YES");
			for(int i=0;i<n;++i)
				ans[i]='#';
			for(int i=0;i<n;++i)
			{
				if(buf[i]=='R' && p)
					ans[i]='P',--p;
				else if(buf[i]=='P' && s)
					ans[i]='S',--s;
				else if(buf[i]=='S' && r)
					ans[i]='R',--r;
			}
			for(int i=0;i<n;++i)
				if(ans[i]=='#')
				{
					if(p)
						ans[i]='P',--p;
					else if(s)
						ans[i]='S',--s;
					else
						ans[i]='R',--r;
				}
			for(int i=0;i<n;++i)
				putchar(ans[i]);
			puts("");
		}
	}
	return 0;
}
