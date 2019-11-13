#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int G,n,a,b,c,x,y,z;
char S[maxn],T[maxn];
int main()
{
	scanf("%d",&G);
	while (G--)
	{
		scanf("%d%d%d%d%s",&n,&a,&b,&c,S);
		x=y=z=0;
		for (int i=0;i<n;i++)
		{
			if (S[i]=='R') x++; else
			if (S[i]=='P') y++; else z++;
			T[i]='.';
		}
		if (min(a,z)+min(b,x)+min(c,y)>=(n+1)/2)
		{
			printf("YES\n");
			for (int i=0;i<n;i++)
				if (S[i]=='R' && b) T[i]='P',b--; else
				if (S[i]=='P' && c) T[i]='S',c--; else
				if (S[i]=='S' && a) T[i]='R',a--;
			for (int i=0;i<n;i++)
				if (T[i]=='.')
					if (a) T[i]='R',a--; else
					if (b) T[i]='P',b--; else T[i]='S';
			for (int i=0;i<n;i++) printf("%c",T[i]);
			printf("\n");
		} else printf("NO\n");
	}
	return 0;
}
