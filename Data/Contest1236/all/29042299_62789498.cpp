#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int qpow(long long x,int n){
	long long ans=1;
	for(;n;n>>=1,x=x*x%mod)if(n&1)ans=ans*x%mod;
	return ans;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d",qpow((qpow(2,m)+mod-1)%mod,n));
} 