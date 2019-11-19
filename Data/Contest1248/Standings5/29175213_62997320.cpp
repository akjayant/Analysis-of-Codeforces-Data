#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n;
ll a[maxn];

int main(){
	scanf("%d",&n);
	ll suma=0,sumb=0,sum=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll ans=0;
	for(int i=1;i<=n/2;i++){
		suma+=a[i];
	}
	for(int i=n/2+1;i<=n;i++){
		sumb+=a[i];
	}
	if(n%2==0){
		printf("%lld\n",suma*suma+sumb*sumb);
	}
	else{
		printf("%lld\n",max(suma*suma+sumb*sumb,(suma+a[n/2+1])*(suma+a[n/2+1])+(sumb-a[n/2+1])*(sumb-a[n/2+1])));
	}
	return 0;
}