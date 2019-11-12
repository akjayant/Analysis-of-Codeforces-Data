#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#define MOD 1000000007
using namespace std;
int main(){
	long long m,n,ans=1,base;
	scanf("%I64d %I64d",&n,&m);
	base=2;
	while(m){
		if(m&1)
		ans=ans*base%MOD;
		base=base*base%MOD;
		m=m>>1;
	}
	ans=(ans-1)%MOD;
	base=ans;
	ans=1;
	while(n){
		if(n&1)
		ans=ans*base%MOD;
		base=base*base%MOD;
		n=n>>1;
	}
	printf("%I64d\n",ans);
	return 0;
}


