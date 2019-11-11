#include<bits/stdc++.h>
using namespace std;
#define next Next
#define gc getchar
#define int long long
const int N=1e6+5;
int n;
char s[N],ss[N];
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
inline int read()
{
    int ret=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c)){ret=ret*10+c-48;c=gc();}
    if(f)return -ret;return ret;
}
signed main()
{
	int T=read();
	while(T--)
	{
		n=read();
		int a=read(),b=read(),c=read(),gs=0;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
		{
			ss[i]='X';
			if(s[i]=='R')
			{
				if(b)
				{
					ss[i]='P';
					b--;
					gs++;
				}
			}
			else if(s[i]=='P')
			{
				if(c)
				{
					ss[i]='S';
					c--;
					gs++;
				}
			}
			else if(s[i]=='S')
			{
				if(a)
				{
					ss[i]='R';
					a--;
					gs++;
				}
			}
		}
			if(gs>=(n+1)/2)
			{
				puts("YES");
				for(int i=1;i<=n;i++)
				{
					if(ss[i]!='X')putchar(ss[i]);
					else{
						if(a){a--;putchar('R');}
						else if(b){b--;putchar('P');}
						else if(c){c--;putchar('S');}
					}
				}
				puts("");
			}
			else puts("NO");
	}
}