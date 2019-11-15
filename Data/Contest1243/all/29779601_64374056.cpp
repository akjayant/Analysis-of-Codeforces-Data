#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,a[1005];
int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d",&n);for(int i=1;i<=n+3;i++)a[i]=0;
		for(int i=1,t;i<=n;i++)
			scanf("%d",&t),a[t]++;
		for(int i=n;i>=1;i--)
			a[i]+=a[i+1];
		for(int i=n;i>=1;i--)
			if(a[i]>=i)
			{
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}