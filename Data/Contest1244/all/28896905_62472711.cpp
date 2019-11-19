#include <bits/stdc++.h>

using namespace std;
char s[100001];
int sum[100001];
signed main() 
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		cin>>s+1;
		int mn=999999999,mx=0;
		for(int i=1;i<=n;i++)
		{
			sum[i]=sum[i-1];
			if(s[i]=='1')
			{
				mn=min(mn,i);
				mx=max(mx,i);

				sum[i]++;
			}
		}
		int ans=n;
		for(int i=1;i<=n;i++)
			if(i>=mn)
			ans=max(ans,i+sum[n]-sum[i]+n-(mn-1)*2);
		for(int i=1;i<=n;i++)
			if(i<=mx)
			ans=max(ans,n-i+1+sum[i-1]+n-(n-mx)*2);
		printf("%d\n",ans);
	}	
	return 0;
}