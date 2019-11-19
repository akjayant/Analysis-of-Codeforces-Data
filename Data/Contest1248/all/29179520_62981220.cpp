#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn=1e5+10;
int a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int num=n/2;
	ll sum1=0,sum2=0;
	for(int i=0;i<n;i++)
	{
		sum2+=a[i];
		if(i<num)sum1+=a[i];
	}
	sum2-=sum1;
	printf("%I64d\n",sum1*sum1+sum2*sum2);
	return 0;
}