#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
map<ll,ll>h;
int main()
{
	scanf("%lld",&n);
	if(n==1)return puts("1"),0;
	for(ll i=2;i*i<=n;i++)
		while(n%i==0)
			h[i]++,n/=i;
	if(n>1)
		h[n]++;
	if(h.size()>1)
		printf("1\n");
	else
		for(auto p:h)
			printf("%lld\n",p.first);
	return 0;
}