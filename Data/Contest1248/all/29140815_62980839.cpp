#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define pb push_back
#define mp make_pair

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		ll p,q,odd=0,even=0;
		for(int i = 0; i<n;i++){
			scanf("%lld",&p);
			if(p%2)
				odd++;
			else
				even++;
		}
		ll odd1=0,even1=0,m;
		scanf("%lld",&m);
		for(int i =0 ;i < m;i++){
			scanf("%lld",&q);
			if(q%2)
				odd1++;
			else
				even1++;
		}

		ll ans = odd1*odd + even1*even;
		printf("%lld\n",ans );
	}
	return 0;
}