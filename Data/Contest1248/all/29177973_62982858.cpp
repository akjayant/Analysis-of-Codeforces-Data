#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001];
long long ans1,ans2;
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++)
	{
		ans1+=a[i];
		ans2+=a[n-i+1];
	}
	if(n%2==1)
	ans2+=a[n/2+1];
	printf("%lld",ans1*ans1+ans2*ans2);
	return 0;
}