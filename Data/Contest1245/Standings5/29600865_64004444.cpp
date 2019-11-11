#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iostream>
#define test freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
char s[105],ans[105];
int main()
{
	//test
	int T;
	cin>>T;
	while(T--)
	{
		memset(ans,0,sizeof(ans));
		int n,a,b,c;
		cin>>n>>a>>b>>c>>s;
		int cnt=0;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='R'&&b) {--b;++cnt;ans[i]='P';}
			else if(s[i]=='P'&&c) {--c;++cnt;ans[i]='S';}
			else if(s[i]=='S'&&a) {--a;++cnt;ans[i]='R';}
		}
		if(cnt>=(n+1)/2) 
		{
			puts("YES");
			for(int i=0;i<n;++i)
			{
				if(!ans[i])
				{
					if(a) {--a;printf("R");}
					else if(b) {--b;printf("P");}
					else if(c) {--c;printf("S");}
				}
				else printf("%c",ans[i]);
			}
			puts("");
		}
		else puts("NO");
	}

	return 0;
}