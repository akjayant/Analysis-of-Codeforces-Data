#include <bits/stdc++.h>

const int maxn=1e5+5;
char a[maxn],b[maxn];
int n;
int main()
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int t;scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s%s",&n,a,b);
		int flag1=0,flag2=0,tmp=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]!=b[i])
			{
				tmp++;
				if(tmp==1)flag1=i;
				else flag2=i;
				if(tmp>2) break;
			}
		}
		if(tmp>2)puts("No");
		else if(tmp==1)puts("No");
		else if(a[flag1]==a[flag2]&&b[flag2]==b[flag1]) puts("Yes");
		else puts("No");
	}
	return 0;
}