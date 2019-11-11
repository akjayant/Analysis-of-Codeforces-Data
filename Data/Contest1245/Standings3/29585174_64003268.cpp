#include<cstdio>
#include<cstring>
const int N=100+10;
int ans,T,n,R,P,S,sum[N];
char s[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(sum,0,sizeof(sum));
		ans=0;
		scanf("%d%d%d%d%s",&n,&R,&P,&S,s+1);
		for(int i=1;i<=n;i++)
			if(s[i]=='R'&&P)
			{
				sum[i]='P';
				P--;
				ans++;
			}
			else if(s[i]=='P'&&S)
			{
				sum[i]='S';
				S--;
				ans++;
			}
			else if(s[i]=='S'&&R)
			{
				sum[i]='R';
				R--;
				ans++;
			}
		if(ans>=(n+1)/2)
		{
			puts("YES");
			for(int i=1;i<=n;i++)
				if(sum[i])putchar(sum[i]);
				else if(P)P--,putchar('P');
				else if(R)R--,putchar('R');
				else if(S)S--,putchar('S');
			puts("");
		}
		else puts("NO");
	}
	return 0;
}
