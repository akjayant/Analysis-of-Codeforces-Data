#include<bits/stdc++.h>
using namespace std;
int a[1001];
int mark[1001];
char s[1001];
signed main() 
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,a,b,c,ans=0;
		scanf("%d",&n);
		scanf("%d%d%d",&a,&b,&c);
		memset(mark,0,sizeof(mark));
			cin>>s+1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='R')
			{
				if(b)
				{
					b--,ans++;
					mark[i]=1;
				}
			}
			if(s[i]=='P')
			{
				if(c)
				{
					c--,ans++;
					mark[i]=1;
				}
			}
			if(s[i]=='S')
			{
				if(a)
				{
					a--,ans++;
					mark[i]=1;
				}
			}
		}	queue<char>q;
			for(int i=1;i<=a;i++)
				q.push('R');
			for(int i=1;i<=b;i++)
				q.push('P');
			for(int i=1;i<=c;i++)
				q.push('S');
			if((n+1)/2<=ans)
			{
				printf("YES\n");
				for(int i=1;i<=n;i++)
				{
					if(mark[i]==1)
					{
						if(s[i]=='R')
							printf("P");
						else if(s[i]=='P')
							printf("S");
						else if(s[i]=='S')
							printf("R");
					}
					else
						printf("%c",q.front()),q.pop();
				}
				printf("\n");
			}
			else
				printf("NO\n");
	}
	return 0;
}
