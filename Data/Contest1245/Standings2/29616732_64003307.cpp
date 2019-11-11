#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int mo=1e9+7;

LL qpow(LL a,LL b)
{
	LL ans=1;
	a%=mo;
	while(b)
	{
		if(b&1)
			ans=ans*a%mo;
		b>>=1;
		a=a*a%mo;
	}
	return ans;
}


int main()
{
	int T;
	scanf("%d",&T);
	char s[200];
	char t[200];
	
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",s);
		int r=0,p=0,sa=0;
		int i;
		for(i=0;i<n;i++)
		{
			if(s[i]=='R')
				r++;
			else if(s[i]=='P')
				p++;
			else
				sa++;
		}
		int ans=0;
		int ta=min(r,b);
		int tb=min(p,c);
		int tc=min(sa,a);
		ans=min(r,b)+min(p,c)+min(sa,a);
		
		if(ans*2>=n)
		{
			printf("YES\n");
			for(i=0;i<n;i++)
			{
				if(s[i]=='R')
				{
					if(ta>0)
					{
						ta--;
						t[i]='P';
						continue;
					}
				}
				if(s[i]=='P')
				{
					if(tb>0)
					{
						tb--;
						t[i]='S';
						continue;
					}
				}	
				if(s[i]=='S')
				{
					if(tc>0)
					{
						tc--;
						t[i]='R';
						continue;
					}
				}
				t[i]=0;
			}
			b-=min(r,b)-ta;
			c-=min(p,c)-tb;
			a-=min(sa,a)-tc;
			for(i=0;i<n;i++)
			{
				if(t[i]==0)
				{
					if(b)
					{
						b--;
						t[i]='P';
					}
					else if(c)
					{
						c--;
						t[i]='S';
					}
					else
					{
						a--;
						t[i]='R';
					}
				}
			}
			t[i]=0;
			printf("%s\n",t);
		}
		else
			printf("NO\n");
	}
	
	return 0;
}