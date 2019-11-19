#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100,INF=1e9+100;
int t,n,minn;
char s[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		minn=INF;
		scanf("%d",&n);
		scanf("%s",s+1);
		for (int i=1;i<=n;i++)
		if (s[i]=='1')
		{
			minn=min(minn,i-1);
			minn=min(minn,n-i);
		}
		if (minn==INF) printf("%d\n",n);
		else printf("%d\n",n*2-minn*2);
	}
	return 0;
}
