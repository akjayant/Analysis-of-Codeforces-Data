#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll T,n,m,x,a1,a2,b1,b2;
ll p[N],q[N];
int main(){
	scanf("%lld",&T);
	while(T--){
		a1=a2=b1=b2=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&x);
			if(x%2==1) a1++;
			else a2++;
		}
		scanf("%lld",&m);
		for(ll i=1;i<=m;i++){
			scanf("%lld",&x);
			if(x%2==1) b1++;
			else b2++;
		}
		printf("%lld\n",a1*b1+a2*b2);
	}
}
