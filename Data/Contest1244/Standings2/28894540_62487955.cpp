#include <bits/stdc++.h>
using namespace std;
long long n,k,a[1000005],b[1000005];
int main() {
	cin>>n>>k;
	long long kk=k;
	if (n*(n+1)/2>k)
	{
		puts("-1");
		return 0;
	}
	for (int i=1;i<=n;i++)
		a[i]=i,b[i]=i;
	k-=n*(n+1)/2;
	for (int i=1;i<=n/2;i++)
	{
		if ((n-2*i+1)>=k)
		{
			int tmp=i+k;
			swap(a[i],a[tmp]);
			cout<<kk<<endl;
			for (int j=1;j<=n;j++)
				printf("%lld ",a[j]);
			puts("");
			for (int j=1;j<=n;j++)
				printf("%lld ",b[j]);
			return 0;
		}
		swap(a[i],a[n-i+1]);
		k-=(n-2*i+1);
	}
	cout<<kk-k<<endl;
	for (int i=1;i<=n;i++)
		printf("%d ",i);
	puts("");
	for (int i=n;i>=1;i--)
		printf("%d ",i);
	return 0;
}
