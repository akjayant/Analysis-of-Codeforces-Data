#include<bits/stdc++.h>
using namespace std;

char en[110];

main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char ans[110];
		for(int i=0;i<102;i++)ans[i]='A';
		int n,a,b,c;
		scanf("%d",&n);
		scanf("%d %d %d",&a,&b,&c);
		scanf("%s",en);
		int win=n/2;
		if(n%2==1)win++;
		for(int i=0;i<n;i++)
		{
			if(en[i]=='R')
			{
				if(b>0)
				{
					b--;
					win--;
					ans[i]='P';
				}
			}
			else if(en[i]=='P')
			{
				if(c>0)
				{
					c--;
					win--;
					ans[i]='S';
				}
			}
			else
			{
				if(a>0)
				{
					a--;
					win--;
					ans[i]='R';
				}
			}
		}
		ans[n]='\0';
		if(win<=0)
		{
			printf("YES\n");
			for(int i=0;i<n;i++)
			{
				if(ans[i]=='A')
				{
					if(a>0)
					{
						printf("R");
						a--;
					}
					else if(b>0)
					{
						printf("P");
						b--;
					}
					else
					{
						printf("S");
						c--;
					}
				}
				else printf("%c",ans[i]);
			}
			printf("\n");
		}
		else printf("NO\n");
	}
}
