#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll D[1000100],d1[1000100];
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
			d1[i]=1;
			D[cnt++]=i;
			if(i*i!=n) D[cnt++]=n/i;
		} 
	}
	ll ANS=n;
	sort(D,D+cnt);
	for(int i=1;i<cnt;i++){
		ANS=gcd(ANS,D[i]);
	}
	printf("%lld\n",ANS);
  return 0;
}

