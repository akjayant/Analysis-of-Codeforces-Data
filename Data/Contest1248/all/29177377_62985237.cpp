#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int maxn = 200005;

int a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	ll sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a,a+n);
	ll ans=0;
	for(int i=0;i<n/2;i++)
		ans+=a[i];
	sum-=ans;
	printf("%lld\n",ans*ans+sum*sum);
	return 0;
}