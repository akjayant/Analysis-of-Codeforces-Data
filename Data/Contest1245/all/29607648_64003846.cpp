#include<bits/stdc++.h>
using namespace std;
int book[105];
int main()
{
//	freopen("ans.out","w",stdout);
	int t;
	cin>>t;
	int n,a,b,c,cnt;
	string s;
	while(t--)
	{
		cin>>n>>a>>b>>c>>s;
		cnt=0;
		for(int i=0;i<n;i++)
		{
			book[i]=0;
			if(s[i]=='R')if(b){cnt++;b--;book[i]=2;}
			if(s[i]=='P')if(c){cnt++;c--;book[i]=3;}
			if(s[i]=='S')if(a){cnt++;a--;book[i]=1;}
		}
		if(cnt*2<n)puts("NO");
		else
		{
			puts("YES");
			for(int i=0;i<n;i++)
			{
				if(book[i]==1)putchar('R');
				if(book[i]==2)putchar('P');
				if(book[i]==3)putchar('S');
				if(!book[i])
				{
					if(a)putchar('R'),a--;
					else if(b)putchar('P'),b--;
					else if(c)putchar('S'),c--;
				} 
			}
			putchar('\n');
		}
	}
} 