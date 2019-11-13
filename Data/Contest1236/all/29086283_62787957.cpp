//I love Nanami ChiaKi
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=1e9+7;
const int mod=1e9+7;
//const int N=;
int qsm(int a,int c){
	int re=1;
	while (c){
		if (c&1) re=1ll*re*a%mod;
		c>>=1;a=1ll*a*a%mod;
	}
	return re;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",qsm((1ll*qsm(2,m)-1+mod)%mod,n));
	return 0;
}
/*
input:
*/

