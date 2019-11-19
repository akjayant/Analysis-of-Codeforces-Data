#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int n,a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int t=n/2+1;
	long long ans=0,ans2=0;
	for(int i=t;i<=n;++i)
		ans+=a[i];
	ans=ans*ans;
	for(int i=1;i<t;++i)
		ans2+=a[i];
	ans2=ans2*ans2;
	cout<<ans+ans2;
}
