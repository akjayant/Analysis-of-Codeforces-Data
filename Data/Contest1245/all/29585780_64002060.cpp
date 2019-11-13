#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
	if(0==b) return a;
	return gcd(b,a%b);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(1LL==gcd(a,b)) puts("Finite");
		else puts("Infinite");
	}
	return 0;
}