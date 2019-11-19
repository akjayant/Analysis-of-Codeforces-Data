#include <bits/stdc++.h>
using namespace std;

int n;
int chi,org,gi,ou;

void solve(){
	scanf("%d",&n);
	chi=org=gi=ou=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(x%2){
			chi++;
		}else{
			org++;
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(x%2){
			gi++;
		}else{
			ou++;
		}
	}
	printf("%lld\n",1ll*chi*gi+1ll*org*ou);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}