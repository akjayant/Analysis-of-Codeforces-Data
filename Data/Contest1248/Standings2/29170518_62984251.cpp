#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rint register int
using namespace std;
typedef long long ll;
int t,n,a,num1[10],num2[10];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(num1,0,sizeof num1);
		memset(num2,0,sizeof num2);
		scanf("%d",&n);
		for(rint i=1;i<=n;++i)
			scanf("%d",&a),++num1[a&1];
		scanf("%d",&n);
		for(rint i=1;i<=n;++i)
			scanf("%d",&a),++num2[a&1];
		ll ans=(ll)num1[0]*num2[0]+(ll)num1[1]*num2[1];
		printf("%lld\n",ans);
	}
	return 0;
}
