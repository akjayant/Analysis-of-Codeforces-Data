#include<bits/stdc++.h>
using namespace std;
char s[100001];
int a[100001];
signed main()
{
	int n;
	long long ans1=0,ans2=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;i++)
		ans1+=a[i];
	for(int i=n/2+1;i<=n;i++)
		ans2+=a[i];
	printf("%I64d",ans1*ans1+ans2*ans2);
	return 0;
}