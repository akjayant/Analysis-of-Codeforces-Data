#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 1000005
int a[N];
bool f[N];
int n,m;
int main()
{
	int T=1;
	while(T--)
	{
		LL s1=0,s2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s1+=a[i];
		sort(a+1,a+n+1);
		for(int i=n;i>n/2;i--)
			s2+=a[i];
		printf("%lld\n",s2*s2+(s1-s2)*(s1-s2));
	}
}