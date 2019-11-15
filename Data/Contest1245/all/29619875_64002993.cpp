#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a,b,c;
		scanf("%d %d %d %d",&n,&a,&b,&c);
		string s;
		cin>>s;
		string ans=s;
		int tot=0;
		for(int i=0;i<n;i++)
			if(s[i]=='R'&&b)
			{
				ans[i]='P';
				b--;
				tot++;
			}
			else if(s[i]=='P'&&c)
			{
				ans[i]='S';
				c--;
				tot++;
			}
			else if(s[i]=='S'&&a)
			{
				ans[i]='R';
				a--;
				tot++;
			}
		if(tot>=(n+1)/2)
		{
			printf("YES\n");
			for(int i=0;i<n;i++)
				if(ans[i]!=s[i])
					putchar(ans[i]);
				else
				{
					if(a)
					{
						putchar('R');
						a--;
					}
					else if(b)
					{
						putchar('P');
						b--;
					}
					else if(c)
					{
						putchar('S');
						c--;
					}
				}
			putchar('\n');
			
		}
		else
			printf("NO\n");
	}
	return 0;
}