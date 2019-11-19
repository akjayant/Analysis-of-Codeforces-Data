#include <bits/stdc++.h>
using namespace std;
int n,a[10008];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		char ch=getchar();
		int ans=0;
		int cnt=0;
		while(ch!='0'&&ch!='1')ch=getchar();
		for(int i=1;i<=n;i++)
		{
			a[i]=ch-'0';
			if(a[i])
			{
				cnt++;
				ans=max(ans,max(i*2,(n-i+1)*2));
			}
			ch=getchar();
		}
		ans=max(ans,n+cnt);
		printf("%d\n",ans);
	}
	return 0;
}