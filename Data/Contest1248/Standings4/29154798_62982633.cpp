#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
int a[100005];

signed main()
{
	scanf("%lld",&n);
	int sum=0,s1=0,s2;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		sum+=a[i]; 
	}
	sort(a+1,a+n+1);
	int len=n/2;
	for(int i=1;i<=len;++i)
	{
		s1+=a[i];
	}
	s2=sum-s1;
	printf("%lld",s1*s1+s2*s2);
	return 0;
}