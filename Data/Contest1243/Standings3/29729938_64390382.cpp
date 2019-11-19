#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+50;
const int INF = 1e9;
int main(){
	ll n;
	scanf("%lld",&n);
	ll cnt=0;ll flag=0;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			flag=i;
			cnt++;
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(!flag) {
		printf("%lld\n",n);
		return 0;
	}
	if(n!=1) {
		cnt++;
	}
	if(cnt>=2) printf("1\n");
	else printf("%lld\n",flag);
	
}