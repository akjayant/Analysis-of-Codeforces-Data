#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
ll s1,s2;
ll a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n/2;i++)
		s1+=a[i];
	for(int i=n/2+1;i<=n;i++)
		s2+=a[i];
	ll ans=s1*s1+s2*s2;
	printf("%lld\n",ans);
	return 0;
}