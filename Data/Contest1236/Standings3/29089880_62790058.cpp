#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//coded by _Int_
const int Mod=1000000007;
int n,m;
int ksm(int a,int p){
	int res=1;
	while(p){
		if(p&1)res=(1ll*res*a)%Mod;
		a=(1ll*a*a)%Mod;
		p>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	printf("%d\n",ksm(ksm(2,m)-1,n));
	return 0;
}
/*
ans=(2^m-1)*n
*/ 
