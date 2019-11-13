#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,x;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&x);
		int ans=0;
		for(int i=0;i<=100;i++)
			for(int j=0;j<=100;j++)
				if(i<=n&&2*i+j<=m&&2*j<=x)
					ans=max(ans,i+2*i+j+2*j);
		printf("%d\n",ans);
	}
}

