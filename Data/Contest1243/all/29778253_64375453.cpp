#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n;
int a[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof a);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			a[x]++;
		}
		int ma=0;
		for(int i=n;i>=1;i--) a[i]=a[i+1]+a[i];
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=i) ma=max(ma,i);
		}
		printf("%d\n",ma);
	}
}