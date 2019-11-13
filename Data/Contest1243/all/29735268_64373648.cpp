#include<bits/stdc++.h>
using namespace std;
int a[100001];
signed main() 
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		int flag=0;
		for(int i=1;i<=n;i++)
			if(a[i]<i)
			{
				flag=i;
				break;
			}
		if(!flag)
			flag=n+1;
		printf("%d\n",flag-1);
	}
	return 0;
}
