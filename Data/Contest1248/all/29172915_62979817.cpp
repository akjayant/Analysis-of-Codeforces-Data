#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[100005];
int main()
{
	ll n;
	ll i,j,m;
	scanf("%lld",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	ll num1=0,num2=0;
	for(i=1;i<=n/2;i++) num1+=a[i];
	for(i=n/2+1;i<=n;i++) num2+=a[i];
	printf("%lld\n",num1*num1+num2*num2);
	return 0;
}