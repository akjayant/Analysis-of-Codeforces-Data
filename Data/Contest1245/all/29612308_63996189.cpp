#include<bits/stdc++.h>

using namespace std;

int t,n,m;

int gcd(int u,int v){
	if(v==0){
		return u;
	}
	return gcd(v,u%v);
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if(gcd(n,m)>1){
			printf("Infinite\n");
		}
		else{
			printf("Finite\n");
		}
	}
	return 0;
}