#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll d[1000100];
int cnt;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
int main()
{
	scanf("%lld",&n);
	if(n==1){
		printf("1\n");
		return 0;
	}
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			d[cnt++]=i;
			if(i*i!=n) d[cnt++]=n/i;
		} 
	}
	ll ans=n;
	sort(d,d+cnt);
	for(int i=1;i<cnt;i++){
		ans=gcd(ans,d[i]);
	}
	printf("%lld\n",ans);
  return 0;
}

