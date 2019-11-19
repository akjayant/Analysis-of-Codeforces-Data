#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

ll n,m;
int t;
long long ans;
ll c1,c2,c3,c4;
 
int main(){
	scanf("%d",&t);
	while(t--){
		ans=0;c1=c2=c3=c4=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			ll x;
			scanf("%lld",&x);
			if(x%2) c1++;
			else c2++;
		}
		scanf("%lld",&m);
		for(int i=1;i<=m;i++){
			ll x;
			scanf("%lld",&x);
			if(x%2) c3++;
			else c4++;
		}
		ans=c1*c3+c2*c4;
		printf("%lld\n",ans);
	}
	return 0;
} 