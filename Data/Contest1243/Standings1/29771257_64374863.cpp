#include <bits/stdc++.h>
using namespace std;
const int M = 100100;
int a[M],n;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+1+n);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int num=0;
			for(int j=1;j<=n;j++)
				if(a[j]>=i)
					num++;
			if(num>=i)
				ans=max(ans,i);
		}
		cout<<ans<<endl;
	}
	return 0;
} 