#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
const int N = 100;
using namespace std;
int T,a,b,c,n,ans;
char ch[N + 5],ac[N + 5];
int gcd(int x,int y)
{
	if (!y)
		return x;
	return gcd(y,x % y);
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",ch + 1);
		memset(ac,0,sizeof(ac));
		ans = 0;
		for (int i = 1;i <= n;i++)
			if (ch[i] == 'R')
			{
				if (b)
					ans++,ac[i] = 'P',b--;
			}
			else
				if (ch[i] == 'P')
				{
					if (c)
						ac[i] = 'S',ans++,c--;
				}
				else
				{
					if (a)
						ac[i] = 'R',ans++,a--;
				}
		if (ans * 2 >= n)
		{
			printf("YES\n");
			for (int i = 1;i <= n;i++)
				if (ac[i] == 0)
				{
					if (a)
						putchar('R'),a--;
					else
						if (b)
							putchar('P'),b--;
						else
							putchar('S'),c--;
				}
				else
					cout<<ac[i];
			cout<<endl;
		}
		else
			printf("NO\n");
	}
	return 0;
}