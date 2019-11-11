/* LittleFall : Hello! */
#include <bits/stdc++.h>
using namespace std; using ll = long long; inline int read();
const int M = 128, MOD = 1000000007;

char bob[M], alice[M];
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
    #endif

	int t = read();
	while(t--)
	{
		memset(bob, 0, sizeof(bob));
		memset(alice, 0, sizeof(alice));
		int n = read(), r = read(), p = read(), s = read();
		scanf("%s",bob);

		int xr=0, xp=0, xs = 0;
		for(int i=0; bob[i]; ++i)
		{
			if(bob[i]=='R') xr++;
			else if(bob[i]=='P') xp++;
			else xs++;
		}

		if(min(r,xs)+min(s,xp)+min(p,xr)>=(n+1)/2)
		{
			printf("YES\n");
			for(int i=0; i<n; ++i)
			{
				if(bob[i]=='S' && r) 
				{
					alice[i] = 'R';
					r--;
				}
				else if(bob[i]=='P' && s)
				{
					alice[i] = 'S';
					s--;
				}
				else if(bob[i]=='R' && p)
				{
					alice[i] = 'P';
					p--;
				}
			}
			for(int i=0; i<n; ++i)
			{
				if(alice[i]==0)
				{
					if(r) 
					{
						alice[i] = 'R';
						r--;
					}
					else if(p)
					{
						alice[i] = 'P';
						p--;
					}
					else 
					{
						alice[i] = 'S';
						s--;
					}
				}
			}
			printf("%s\n",alice );
		}
		else
		{
			printf("NO\n");
		}
	}

    return 0;
}


inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}