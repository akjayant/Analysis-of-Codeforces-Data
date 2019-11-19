#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll unsigned long long
#define MAXN 100100 
ll n, m, cnt, a[MAXN], len, sum1, sum2, ans; 
int main()
{
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1ll,a+n+1ll);
/*	if(n == 1)
	{
		cout<<0<<endl;
		return 0;
	}*/
	len = n/(ll)2ll;
	for(ll i=1;i<=len;i++) sum1 += a[i];
	for(ll i=len+1;i<=n;i++) sum2 += a[i];
	ans = sum1*sum1+sum2*sum2;
	cout<<ans<<endl;
	
	return 0;
} 