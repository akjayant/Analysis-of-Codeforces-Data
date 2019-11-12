#include<cstdio>
#include<iostream>
using namespace std;
const int MOD=(int)1e9+7;
int pwr(int x,int y){
	int num=1;
	while(y){
		if(y&1)
			num=1ll*num*x%MOD;
		x=1ll*x*x%MOD;
		y>>=1;
	}
	return num;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",pwr((pwr(2,m)+MOD-1)%MOD,n));
	return 0;
}

