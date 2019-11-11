#include <cstdio>
#include <cstring>
int a,b,c,t,n;char s[100001],bob[100001];int buc[4],cnt[4];inline int min(int a,int b){return a<b?a:b;}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&a,&b,&c);scanf("%s",bob+1);memset(buc,0,sizeof(buc));
		for(int i=1;i<=n;++i){if(bob[i]=='R')++buc[1];if(bob[i]=='P')++buc[2];if(bob[i]=='S')++buc[3];}
		if(min(a,buc[3])+min(b,buc[1])+min(c,buc[2])<(n+1)/2)printf("NO\n");
		else
		{
			printf("YES\n");memset(cnt,0,sizeof(cnt));
			for(int i=1;i<=n;++i)
			{
				int nd=0;s[i]='\0';
				if(bob[i]=='R')nd=1;if(bob[i]=='P')nd=2;if(bob[i]=='S')nd=3;nd=nd%3+1;
				if(nd==1&&cnt[1]==a||nd==2&&cnt[2]==b||nd==3&&cnt[3]==c)continue;
				s[i]=nd==1?'R':(nd==2?'P':'S');++cnt[nd];
			}
			s[n+1]='\0';
			for(int i=1;i<=n;++i)
			{
				if(cnt[1]!=a&&!s[i])s[i]='R',++cnt[1];
				else if(cnt[2]!=b&&!s[i])s[i]='P',++cnt[2];
				else if(cnt[3]!=c&&!s[i])s[i]='S',++cnt[3];
			}
			printf("%s\n",s+1);
		}
	}
	return 0;
}