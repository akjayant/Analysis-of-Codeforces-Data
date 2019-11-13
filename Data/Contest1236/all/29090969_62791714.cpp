#include<bits/stdc++.h>
using namespace std;

const int mo=1e9+7;

int qpow(int x,int p){
	int rt=1;
	while(p){
		if(p&1)rt=(1ll*rt*x)%mo;
		x=(1ll*x*x)%mo;
		p>>=1;
	}
	return rt;
}

int n,m;

int main(){
	scanf("%d%d",&n,&m);
	printf("%d\n",(qpow(qpow(2,m)-1,n)+mo)%mo);
	return 0;
}
