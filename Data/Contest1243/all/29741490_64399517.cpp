#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+5;

int main()
{
	ll n;
	while(~scanf("%lld",&n)){
		if(n==1){
			printf("1\n");
			continue;
		}
		vector<ll>factor;
		ll ub=sqrt(n);
		for(ll i=2;i<=ub;i++){
			if(n%i==0){
				factor.push_back(i);
				while(n%i==0)n/=i;
			}
		}
		if(n!=1)factor.push_back(n);
		if(factor.size()>1)printf("1\n");
		else printf("%lld\n",factor[0]);
	}
    return 0;
}
