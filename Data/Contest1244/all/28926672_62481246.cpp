#include "bits/stdc++.h"
using namespace std;

#define ll long long 
ll n, p, w, d;

int main(){
	scanf("%lld %lld %lld %lld", &n, &p, &w, &d);
	if(p%__gcd(w, d) != 0){
		printf("-1\n");
		return 0;
	}
	ll ansW = (p/w);
	int cnt = 0;
	while(cnt < 1000000 && ansW >= 0){
		cnt++;
		if((p-w*ansW)%d == 0){
			ll ansD = (p-w*ansW)/d;
			// printf("(%lld, %lld)\n", ansW, ansD);
			if(ansW + ansD > n){
				printf("-1\n");
				return 0;
			}else{
				printf("%lld %lld %lld\n", ansW, ansD, n-ansW-ansD);
				return 0;
			}
		}
		ansW--;
	}
	printf("-1\n");
	return 0;
}