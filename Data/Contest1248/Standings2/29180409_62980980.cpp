#include <bits/stdc++.h>
using namespace std;
//mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
//int rnd(int x) { return mrand()%x;}
int n;
int a[100100];
typedef long long ll;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	ll l=0,u=0;
	for(int i=1;i<=n/2;i++){
		l+=1ll*a[i];
	}
	for(int i=n/2+1;i<=n;i++){
		u+=1ll*a[i];
	}
	printf("%lld\n",l*l+u*u);
	return 0;
}

